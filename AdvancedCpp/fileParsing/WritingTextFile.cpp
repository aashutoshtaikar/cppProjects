#include<iostream>
#include<fstream>
using namespace std;


int main()
{
    fstream outFile;
    string outputFileName = "text.txt";
    //ofstream outFile;
    //outFile.open(outputFileName);         //used with ofstream
    
    outFile.open(outputFileName, ios::out); //fstream is general 
    if(outFile.is_open()){
        outFile << "hello there" << endl;
        outFile << "123" << endl;
        outFile << 123 << endl;
    }
    else{
        cout << "Could not create file: " << outputFileName <<endl;
    }

    return 0;
}
