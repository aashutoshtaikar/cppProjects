#include<iostream>
#include<fstream>
using namespace std;



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

int main()
{
    arrayToBin();
    readArrayBin();
    return 0;
}

