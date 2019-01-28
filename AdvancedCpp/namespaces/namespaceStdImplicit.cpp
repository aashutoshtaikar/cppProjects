#include<iostream>
#include<vector>
#include<functional>   //functional prog
#include<algorithm> //for find_if



namespace apple{
    //using a string reference
    void print(const std::string& text){
        std::cout << text << std::endl;
    }
}

namespace orange{
    //using a char pointer
    void print(const char* text){
        std::string temp = text;
        std::reverse(temp.begin(),temp.end());
        std::cout << temp << std::endl;
    }
}


using namespace apple;
using namespace orange;

int main(){
    //apple::print("Hello");
    print("Hello"); //if we include both the namespaces, the function contained in the orange becomes a better match as the passed parameter is array of chars

}