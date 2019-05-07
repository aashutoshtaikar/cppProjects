#include <iostream>
#include <vector>
#include <any>


class TempClass
{
  public:
    int x;
    TempClass() : x(1) {}
    ~TempClass() {}
} temp_obj;

int main()
{
    std::vector<std::any> vec{1, temp_obj};

    for (auto &i : vec)
    {
        std::string tmp = i.type().name();
        if (tmp == "i")
            std::cout << "Integer:" << std::any_cast<int>(i) << '\n';
        else if (tmp == "d")
            std::cout << "Double:" << std::any_cast<double>(i) << '\n';
        else if (tmp == "f")
            std::cout << "float:" << std::any_cast<float>(i) << '\n';
        else if (tmp == "PKc")
            std::cout << "const char*:" << std::any_cast<const char *>(i) << '\n';
        else if (tmp == "b")
            std::cout << ":" << std::any_cast<bool>(i) << '\n';
        else if (tmp == "9TempClass")
        {
            TempClass z = std::any_cast<TempClass>(i);
            std::cout << tmp << ':' << z.x;
        }
        else{
            std::cout << "Invalid type entered in vector\n";
        }
    }
    return 0;
}

