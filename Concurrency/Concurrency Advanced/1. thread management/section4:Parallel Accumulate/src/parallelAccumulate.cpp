#include <iostream>
#include <vector>
#include <numeric>   //accumulate
#include <algorithm> //for_each
#include <functional>
#include <thread>

#define MIN_BLOCK_SIZE 1000

//wrapper function for std::accumulate
template <typename iterator, typename T>
void accumulate(iterator start, iterator end, T &ref)
{
    ref = std::accumulate(start, end, 0);
}

template <typename iterator, typename T>
T parallel_accumulate(iterator start, iterator end, T &ref)
{
    //calculate no. num of data blocks for whole context
    int input_size = std::distance(start, end);

    //allowed threads by current input_size
    int allowed_threads_by_elements = (input_size) / MIN_BLOCK_SIZE;

    //allowed threads by system
    int allowed_threads_by_hardware = std::thread::hardware_concurrency();

    //decide threads by taking the min of the above two
    int num_threads = std::min(allowed_threads_by_elements, allowed_threads_by_hardware);

    //calculate the data block size per thread
    int block_size = (input_size + 1) / num_threads;

    //to store results and threads
    std::vector<T> results(num_threads);
    std::vector<std::thread> threads(num_threads - 1);

    iterator last;

    //assigning task to each thread
    for (int i = 0; i < num_threads - 1; i++)
    {
        last = start;
        std::advance(last, block_size);

        threads[i] = std::thread(accumulate<iterator, T> , start, last, std::ref(results[i]));

        start = last;
 
    }

    results[num_threads - 1] = std::accumulate(start, end, 0);

    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

    return std::accumulate(results.begin(), results.end(), ref);
}

int main(int argc, char const *argv[])
{
    const int size = 8000;
    int *my_array = new int[size];
    int ref = 0;

    srand(0);

    for (size_t i = 0; i < size; i++)
    {
        my_array[i] = rand() % 10;
    }

    int rer_val = parallel_accumulate<int *, int>(my_array, my_array + size, ref);

    printf("accumulated value : %d \n", rer_val);

    return 0;
}
