#include <iostream>
#include <vector>
#include <sstream>
#include<typeinfo> 

template<typename T>
std::string to_string_impl(const T& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
} 

//case for 0 args needed
std::vector<std::string> to_string()
{
    return {};
} 


template<typename P1, typename ... Param>
std::vector<std::string> to_string(const P1 &p1, const Param&... param)
{
    std::vector<std::string> s;
    s.push_back(to_string_impl(p1));

    //convert each arg to string, auto stores each return value in (vector) remainder
    const auto remainder = to_string(param...);
    s.insert(s.end(), remainder.begin(),remainder.end());
    
    return s;
}


int main() 
{
    auto vec = to_string("hello", 1, 5.3);

    for(auto &i : vec){
        std::cout << i << '\n';
    }
    
}

/* 0.44user 0.07system 0:00.51elapsed 100%CPU (0avgtext+0avgdata 70572maxresident)k
0inputs+888outputs (0major+22482minor)pagefaults 0swaps

 Compilation time is more (0:00.51elapsed)
 program size is more (70572K)
 */