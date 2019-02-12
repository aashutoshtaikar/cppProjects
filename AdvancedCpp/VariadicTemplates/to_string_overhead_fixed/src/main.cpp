#include <iostream>
#include <vector>
#include <sstream>

template<typename T>
std::string to_string_impl(const T& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
} 

//using initializer list
template<typename ... Param>
std::vector<std::string> to_string(const Param&... param)
{
    return {to_string_impl(param)...};  //constructs a vector of strings using initializer list
}


int main() 
{
    const auto vec = to_string("hello", 1, 5.3);

    for(const auto &i : vec){
        std::cout << i << '\n';
    }
    
}

/* 0.40user 0.04system 0:00.45elapsed 100%CPU (0avgtext+0avgdata 66580maxresident)k
0inputs+456outputs (0major+21026minor)pagefaults 0swaps
 Compilation time is lesser (0:00.45elapsed) than to_string_overhead
 program size is lesser (66580K) than to_string_overhead
 */