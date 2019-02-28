/* There are two versions of accumulate algorithm in numeric header file.
First one take three arguments and it will sum the elements in the range given by the first two arguments
to initial value which is given as third argument. In the second version,
you can pass what operation to perform as a predicate as 4th argument.

 */
#include <iostream>
#include <numeric> //accumulate
#include <vector>

void seq_accumulate()
{
    std::vector<int> x{1, 2, 3, 4};
    int sum = std::accumulate(x.begin(), x.end(), 0);
    std::cout << sum << std::endl;

    int product = std::accumulate(x.begin(), x.end(), 1, std::multiplies<int>());
    std::cout << product << std::endl;

    //print values of vectors seperated by dashes
    auto dash_fold = [](std::string a, int b) {
        return std::move(a) + '-' + std::to_string(b);
    };

    std::string s = std::accumulate(std::next(x.begin()), x.end(), std::to_string(x[0]), dash_fold);
    std::cout << s << std::endl;
}

//int main(int argc, char const *argv[])
//{
//    seq_accumulate();
//
//    return 0;
//}
