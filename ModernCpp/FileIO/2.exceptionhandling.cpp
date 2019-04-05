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
    input >> value;
    if(input.fail()) cout << "io failed, Could not read\n"; // same as if(!input) ! operator overloaded for getting fail bit
    if(input.eof()) cout << "end of file encountered\n";
    if(input.bad()) cout << "irrecoverable stream error\n";
    if(input.good()) cout << " I/O operations are successful\n";
    else cout << "Some I/O operations failed\n";

    input.setstate(std::ios::failbit); //setting one of ifstream object state
    input.clear(); //clears 
    input.close();
    cout << message << ":" << value << endl;
}


int main(){
    Write();
    Read();
    return 0;
}