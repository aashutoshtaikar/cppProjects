#include<iostream>
#include<fstream>
using namespace std;

////struct padding -- structs are automatically padded to round off the size of contents  
#pragma pack(push,1)    //align this to single byte boundaries
struct Person {
    //char c;
    char name[50];      //50 bytes
    int age;            //4 bytes
    double height;      //8 bytes
};
#pragma pack(pop)       //end

void structToBin(){
    string fileName = "struct.bin"; //extension doesn't have to be bin
    Person someone = {"Frodo",220,0.8};
    cout << sizeof(Person) << endl;
    
    // ofstream outputFile;
    // outputFile.open(fileName,ios::binary);

////write struct to a binary file ////
    fstream outputFile;
    outputFile.open(fileName,ios::binary|ios::out);
    if(outputFile.is_open()){
        outputFile.write((char*)(&someone),sizeof(Person));
        //outputFile.write(reinterpret_cast<char *>(&someone),sizeof(Person));
        outputFile.close();
    }
    else{
        cout << "Could not create file " + fileName;
    }

////read binary file into struct //// 
    Person someoneElse = {};
    
    ifstream inputFile;
    inputFile.open(fileName, ios::binary);
    if(inputFile.is_open()){
        inputFile.read((char*)(&someoneElse),sizeof(Person));
        inputFile.close();
    }
    else{
        cout << "Could not read file " + fileName;
    }
    cout << someoneElse.name << "," << someoneElse.age << "," << someoneElse.height << endl;
}