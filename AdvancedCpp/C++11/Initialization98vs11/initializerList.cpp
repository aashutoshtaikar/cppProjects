#include<iostream>
#include<vector>
//#include<initializer_list>
using namespace std;

class Test{
public:
    Test(initializer_list<string> texts){
        for(auto value : texts){
            cout << value << endl;
        }
    }

    void print(initializer_list<string> texts){
        for(auto value:texts){
            cout << value << endl;
        }
    }
};



int main(){
    vector<string> numbers {"one","two","three"};
    cout << numbers[2] << endl;

    Test test{"apples","orange","banana"};

    test.print({"one","two","three"});
    
    return 0;
}


/* output:
three
apples
orange
banana
one
two
three
 */

//Exercise: implement a ring buffer with initializer list