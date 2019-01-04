#ifndef _HEADER_H 
#include "Header.h"
#endif

void fileOutMain(){
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
}

void fileInMain(){
    string inFileName = "text.txt";
    ifstream inFile;

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
}

////parsing text files
int parsingText(){
    string fileName = "stats.txt";
    ifstream input;
    input.open(fileName);

    if(!input.is_open()){
        return 1;
    }

    while(input){
        string line;
        getline(input,line,':');
        
        int population;
        input >> population;

        //input.get(); //get next char and discard
        input >> ws;    //ws is whitespace in (c++11)

        if(!input){     //for breaking on maformed lines formed during error
            break;      //error state as the input file ends
        }

        cout << "'" << line << "'" << "--'" << population << "'" <<endl;
    }
    input.close();
}

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

void arrayToBin(){

    int dataToWrite[5] = {0,1,2,3,4};
    string fileName="array.bin";
    fstream someFileToWrite;
    someFileToWrite.open(fileName,ios::out|ios::binary);
    someFileToWrite.write((char*)(&dataToWrite),sizeof(dataToWrite));
    someFileToWrite.close();
    

    
}

void readArrayBin(){
     string fileName="array.bin";
    int temp[5];
    fstream someFileToRead;
    someFileToRead.open(fileName,ios::in|ios::binary);
    someFileToRead.read((char*)(&temp),sizeof(temp));
    someFileToRead.close();

    for(int i = 0; i <= 4; i++)
    {
        cout << temp[i] << endl;
    }
}
