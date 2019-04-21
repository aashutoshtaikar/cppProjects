namespace assignment3{

//1. Modify the function templates created in Assignment I to accept array by reference.
template<class T, int size>
T Max(T (&pArr)[size]){
    T greater{};
    for(int i = 0 ; i < size; i++){
        if(greater < pArr[i]) greater = pArr[i];    
    }
    return greater;
}
//2. Create specialization of the function templates created in Assignment I. Specialized for const char * & std::vector<int>

}//namespace assignment3