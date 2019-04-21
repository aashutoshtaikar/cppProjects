#include "t_add.h"
/* specialized template functions for add() */

namespace assignment3{

template<>
const char* add<const char*>(const char* x, const char* y){
    char* fullname = new char[strlen(x)+strlen(y)+1];   //allocating on heap because, have to return ptr
    strcpy(fullname,x);
    strcat(fullname,y);

    return fullname;
}

template<>
std::vector<int> add<std::vector<int>>(std::vector<int> x, std::vector<int> y){
    y.resize(x.size());
    std::transform(x.begin(),x.end(),y.begin(),y.begin(),std::plus<int>());
    return y;
}

}//namespace assignment3

