/* *Assignment3:
1. Modify the function templates created in Assignment I to accept array by reference.
2. Create specialization of the function templates created in Assignment I. Specialized for const char * & std::vector<int>
3. Define the specialized functions in a .h file and include it in multiple source files. Observe what happens. 
Ans: gives error that the .h file is defined twice also spl template functions must be defined in .cpp
*/

#include <iostream>
#include <string>
#include "t_add.h"
#include "t_arraysum.h"
#include "t_Max.h"
#include "t_MinMax.h"

namespace assignment3{

class tests_add{
  public:
    static void string_test()
    {
        using std::cin, std::cout;
        
        std::string first, last;
        cin >> first;
        cin >> last; //cannot do this as templates are runtime
        cout << add(first, last);
    }

    static void constchar_specialization()
    {
        using std::cin,std::cout;

        char first[10], last[10];
        cin.getline(first, 10);
        cin.getline(last, 10);

        const char *pfullname = add(static_cast<const char *>(first), static_cast<const char *>(last));
        cout << pfullname << "\n";
        delete[] pfullname;
    }

    static void vector_specialization(){
        using std::vector,std::cout;

        vector<int> x = {1,2,3};
        vector<int> y = {1,1,1};
        auto z = add(x,y);
        for(auto&& i : z)
        {
            cout << i << " ";
        }
    }

    static void vectorAny_specialization(){
        using std::vector,std::cout,std::string;

        vector<string> x = {"hello","hi"};
        vector<string> y = {"Ash", "Bash"};
        auto z = add_vector(x,y);
        for(auto&& i : z)
        {
            cout << i << " ";
        }
    }

    static void run_all(){
        tests_add::string_test();
        tests_add::constchar_specialization();
        tests_add::vector_specialization();
        tests_add::vectorAny_specialization();
    }
};

//1. Modify the function templates created in Assignment I to accept array by reference.
void test_ArraySum(){
    using namespace std;
    int x[] = {1,5,3,4};
    cout << ArraySum(x) << "\n";

    // std::string str[] = {"1","2","3"};
    // cout << ArraySum(str) << "\n";
}

}//namespace assignment3



int main(){
    using namespace assignment3;
    // tests_add::string_test();
    // test_ArraySum();
    
    test_ArraySum();


    return 0;
}