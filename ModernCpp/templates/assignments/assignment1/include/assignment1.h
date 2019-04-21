#pragma once

template<class T>
T add(T x, T y){
    return x + y;
}

template<class T>
T ArraySum(T* pArr, int size){
    T sum{};
    for(int i = 0 ; i < size; i++){
        sum += pArr[i];
    }
    return sum;
}

template<class T>
T Max(std::unique_ptr<T[]>& pArr, int size){
    T greater{};
    for(int i = 0 ; i < size; i++){
        if(greater < pArr[i]) greater = pArr[i];    
    }
    return greater;
}

template <class T>
std::pair<T,T> MinMax(T* pArr, int size){
    T smaller = pArr[0];
    T greater;
    for(int i = 0; i < size; i++){
        if (greater<pArr[i]) greater = pArr[i];
        if (smaller>pArr[i]) smaller = pArr[i];
    }
    return std::make_pair(smaller,greater);
}