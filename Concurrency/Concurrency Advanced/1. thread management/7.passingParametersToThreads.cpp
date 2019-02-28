#include <iostream>
#include <thread>

void func_1(int x, int y)
{
    printf("X + Y = %d \n", x + y);
}

void func_2(int &x)
{
    while (1)
    {
        printf("thread 1 value of x - %d \n", x);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void run_1()
{
    int p = 9;
    int q = 2;

    std::thread thread1(func_1, p, q);
    thread1.join();
}

void run_2()
{
    int x = 9;
    printf("Main thread value of x : %d \n", x);

    //thread object itself takes arg by value, thus use wrapper std::ref()
    std::thread thread1(func_2, std::ref(x));
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    x = 15;
    printf("Main thread value has been changed to - %d \n", x);
    thread1.join();
}

int main(int argc, char const *argv[])
{
    //run_1();
    run_2();
}
