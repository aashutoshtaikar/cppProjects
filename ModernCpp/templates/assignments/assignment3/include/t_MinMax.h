#include <utility> //std::pair

namespace assignment3{

//1. Modify the function templates created in Assignment I to accept array by reference.
template <class T, int size>
std::pair<T,T> MinMax(T (&pArr)[size]){
    T smaller = pArr[0];
    T greater;
    
    for(int i = 0; i < size; i++){
        if (greater<pArr[i]) greater = pArr[i];
        if (smaller>pArr[i]) smaller = pArr[i];
    }
    
    return std::make_pair(smaller,greater);
}
//2. Create specialization of the function templates created in Assignment I. Specialized for const char * & std::vector<int>

} //namespace assignment3