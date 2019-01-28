#include<iostream>
#include<fstream>
using namespace std;


int main(){
    string inFileName = "text.txt";
    ifstream inFile;
    inFile.open(inFileName);
    
    if(inFile.is_open()){
        string line;
        //inFile >> line;
        // while(inFile){ //this can be also used due to '!' operator overloading
        while(!inFile.eof()){
            getline(inFile,line);
            cout <<line << endl;
        }

        inFile.close();
    }

    return 0;
}
