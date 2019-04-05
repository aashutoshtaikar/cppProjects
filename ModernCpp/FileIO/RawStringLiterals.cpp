#include <iostream>
#include <string>
using namespace std;


int main(){
    string filename_problem{"C:\temp\newfile.txt"};
    string filename{"C:\\temp\\newfile.txt"};
    string filename_raw{ R"(C:\temp\newfile.txt)" };
    cout << filename_problem << "\n";
    cout << filename << "\n";
    cout << filename_raw << "\n";
    
    //string message{R"(C++ introduced filesystem API"(in C++17)")"}; // will not work - compiler will misinterpret escape seq C++17)"
    //introduce own escape sequence to resolve this
    string message{R"XYZ(C++ introduced filesystem API"(in C++17)")XYZ"};
    cout << message << "\n";
    return 0;
}