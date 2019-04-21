namespace assignment3{

//1. Modify the function templates created in Assignment I to accept array by reference.
template<class T, int size>
T ArraySum(T (&pArr)[size]){
    T sum{};
    for(int i = 0 ; i < size; i++){
        sum += pArr[i];
    }
    return sum;
}
//2. Create specialization of the function templates created in Assignment I. Specialized for const char * & std::vector<int>

}//namespace assignment3