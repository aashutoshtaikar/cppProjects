
#include <iostream>
#include <vector>
#include <any>

#define CAST_TO(X,Y) static_cast<X>(Y)

template <typename T2> void somefun(){

}

class TempClass{
    public:
    int x;
    TempClass():x(1){}
    ~TempClass(){}
}temp_obj;

int main ()
{
//   std::vector <std::any> vec{1, "ash", 3.2, temp_obj};

    // for (auto& i:vec) {
    //   std::string tmp = i.type().name();
    //   if (tmp == "i") std::cout << "Integer:"<< std::any_cast <int>(i) << '\n';
    //   else if (tmp == "d") std::cout << "Double:"<< std::any_cast <double>(i) << '\n';
    //   else if (tmp == "f") std::cout << "float:"<< std::any_cast <float>(i) << '\n';
    //   else if (tmp == "PKc") std::cout << "const char*:"<< std::any_cast <const char*>(i) << '\n';
    //   else if (tmp == "b") std::cout << ":"<< std::any_cast <bool> (i) << '\n';
    //   else{
    //       tmp.erase(tmp.begin());
    //       std::cout << tmp ;
    //       std::cout << ":"<< CAST_TO(tmp)(i) << '\n'; //does not work
    //   }

    // }
    char* a = "1";
    std::cout << CAST_TO(int,a);
    

  return 0;
}
