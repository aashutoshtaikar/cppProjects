/* writing into a text file */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Write(){
    ofstream out{"data.txt"};
    out << "hello world" << "\n";
    out << 10 << "\n";
    out.close();
}

void Read(){
    ifstream input{"data.txt"};
    
    string message;
    getline(input,message); //read entire line
    
    int value{};
    input >> value;
    
    input.close();
    cout << message << ":" << value << endl;
}


int main(){
    Write();
    Read();
    return 0;
}