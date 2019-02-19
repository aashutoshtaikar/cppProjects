#include <iostream>
#include <string>

template <typename... Params>
class Printer;

template<> class Printer<>{};

template <typename T, typename... Params>
class Printer<T, Params...>
{
    template <typename U, typename...Us>
    void PrintImpl(U&& u, Us&&...rest){
        std::cout << u << ", ";
        PrintImpl(rest...);
    }

    template <typename U>
    void PrintImpl(U&& u){
        std::cout << u << '\n';
    }
    
public:
    
    void Print()
    {
        std::cout << "\nhere\n";
    }

    // void Print(T a)
    // {
    //     std::cout << a;
    // }

    void Print(T a, Params... args)
    {
        PrintImpl(a, args...);
    }
};

int main()
{
    Printer<int, double, int> p;
    p.Print(1, 2.2, 3);
    return 0;
}

/* In each recursive call the number of args from pack is reduced by 1

1. Print(1,2.5,3,"4");
2. Print(2.5,3,"4");
3. Print(3,"4");
4. Print("4");
5. Print(); //compiler expects a function that does not accept any argument

 */