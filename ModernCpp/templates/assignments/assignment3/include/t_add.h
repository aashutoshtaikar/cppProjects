#pragma once

#include <cstring>
#include <string>
#include <vector>
#include <algorithm>    //transform

namespace assignment3{

template<class T>
T add(T x, T y){
    return x + y;
}

//2. Create specialization of the function templates created in Assignment I. Specialized for const char * & std::vector<int>
template<>
const char* add<const char*>(const char* x, const char* y);

//2. Create specialization of the function templates created in Assignment I. Specialized for const char * & std::vector<int>
template<>
std::vector<int> add<std::vector<int>>(std::vector<int> x, std::vector<int> y);


//extra
template<class VT>
std::vector<VT> add_vector(std::vector<VT> x, std::vector<VT> y){
    y.resize(x.size());
    std::transform(x.begin(),x.end(),y.begin(),y.begin(),std::plus<VT>());
    return y;
}

}//namespace assignment3