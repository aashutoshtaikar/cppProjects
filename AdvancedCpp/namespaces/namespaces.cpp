#include<iostream>
#include<algorithm> //for find_if

/* NEVER USE using namespace ns_name IN A HEADER FILE */

//traditional way
namespace apple{ namespace functions{
    void print(const std::string& text){
        std::cout << text << std::endl;
    }
}
}

//c++17 way
namespace apple::otherFunctions{
    void print(const std::string& text){
        std::cout << text << std::endl;
    }
}

namespace orange{
    void print(const char* text){
        std::string temp = text;
        std::reverse(temp.begin(), temp.end());
        std::cout << temp << std::endl;
    }
}



int main(){
    //using namespace apple;
    namespace aof = apple::otherFunctions;
    
    apple::functions::print("hello1");
    aof::print("hello2");

    namespace a = apple::functions;
    a::print("hello3");

    std::cin.get();

}