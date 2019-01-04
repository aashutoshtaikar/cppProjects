#ifndef _HEADER_H 
#include "Header.h"
#endif


void vector1Example(){
    vector<string> strings;
    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");
    
    for(int i = 0; i<strings.size();i++){
        cout << strings[i] << endl;
    }

    for(vector<string>::iterator it=strings.begin(); it!=strings.end();it++){
        cout << *it << endl;
    }
}

//vector manages an array internally
//insertion time in a vector is constant
//capacity increases exponentially with the number of elements
//size - actual number of elements in the vector(internal variable in vector class which holds the count of elements)
//capacity - size of the vector allocated 

void vector2Example(){
    vector<double> numbers(20);

    cout << "Size: " << numbers.size() << endl;

    int capacity = numbers.capacity();
    cout << "Capacity: " << capacity << endl;

    for(int i = 0; i< 10000; i++){
        if(numbers.capacity()!=capacity){
            capacity = numbers.capacity();          //update the latest capacity value
            cout << "Capacity: " << capacity << endl;
        }

        numbers.push_back(i);
    }

    numbers.clear();    //removes all elements of the vector
    numbers.resize(100);    //changes the internal count var of vector
    numbers.reserve(100000); //increases the capacity by 100000 (new capacity = 100000) used for efficiency/ to avoid re-allocations.
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;
    
}

//two dimensional vector
void twoDimVector(){
    //rows containing columns (3rows,4 columns init to 7)
    vector<vector<int>> grid(3,vector<int>(4,7));
    
    grid.push_back(vector<int>(4,7));

    grid[1].push_back(8);

    for(int row=0;row<grid.size();row++){
        for(int col=0; col<grid[row].size();col++){
            cout << grid[row][col] << flush;
        }
        cout <<endl;
    }

}

//create a 2D vector and preinit the size, fill it with the 12 times table, print it
void vectorExercise1(){
    vector<vector<int>> xVec(12,vector<int>(1,0));

    for(int row=0; row<xVec.size();row++){
        for(int col=0; col<xVec[row].size();col++){
            xVec[row][col]=row*12;
        }
    }

    for(int row=0;row<xVec.size();row++){
        for(int col=0; col<xVec[row].size();col++){
            cout << xVec[row][col] << flush;
        }
        cout <<endl;
    }
}

void vectorExercise2(){
    vector<vector<int>> xVec(12,vector<int>());

    for(int row=0; row<xVec.size();row++){
            xVec[row].push_back(12*row);
    }

    for(int row=0;row<xVec.size();row++){
        for(int col=0; col<xVec[row].size();col++){
            cout << xVec[row][col] << flush;
        }
        cout <<endl;
    }
}

void vectorExercise3(){
    vector<vector<int>> xVec;

    for(int row=0; row<=12;row++){
            xVec.push_back(vector<int>());
            xVec[row].push_back(12*row);
    }

    for(int row=0;row<xVec.size();row++){
        for(int col=0; col<xVec[row].size();col++){
            cout << xVec[row][col] << flush;
        }
        cout <<endl;
    }
}

void vectorExercise4(){
    vector<vector<int>> xVec;

    for(int row=0; row<=12;row++){
        xVec.push_back(vector<int>(1,row*12));
    }


    for(int row=0;row<xVec.size();row++){
        for(int col=0; col<xVec[row].size();col++){
            cout << xVec[row][col] << flush;
        }
        cout <<endl;
    }
}

int vectorToBin(){
    //defining and initializing numbers vector 
    vector<int> numbers{1,2,3};
    
    //write numbers vector to bin file
    string fileName="vect.bin";
    fstream someFileToWrite;
    someFileToWrite.open(fileName,ios::out|ios::binary);
    for (vector<int>::iterator it=numbers.begin();it!=numbers.end();it++){
        someFileToWrite.write((char*)&(*it),sizeof(int));
    }
    someFileToWrite.close();

    return numbers.size();
}

void readVecBin(int numbers){
    string fileName="vect.bin";
    vector<int> numbersRead;
    //read the bin file into the numbersRead vector
    fstream someFileToRead;
    someFileToRead.open(fileName,ios::in|ios::binary);
    for (int i = 0; i < numbers; ++i) {
      int j = 0;
      someFileToRead.read((char*)(&j),sizeof(int));
      numbersRead.push_back(j);
    }
    someFileToRead.close();

    //printing the numbersRead vector
    for (vector<int>::iterator itr=numbersRead.begin();itr!=numbersRead.end();itr++){
        cout << *itr << endl;
    }
}

int main(){
    cout << "Select a function to run1:" <<endl;
    cout << "1.vector1Example" << endl;
    cout << "2.vector2Example" << endl;
    cout << "3.twoDimVector" << endl;
    cout << "4.vectorExercise1" << endl;
    cout << "5.vectorExercise2" << endl;
    cout << "6.vectorExercise3" << endl;
    cout << "7.vectorToBin" << endl;
    cout << "8.readVecBin" << endl;
    int x;
    cin >> x;

    switch (x)
    {
        case 1:vector1Example();break;
        case 2:vector2Example();break;
        case 3:twoDimVector();break;
        case 4:vectorExercise1();break;
        case 5:vectorExercise2();break;
        case 6:vectorExercise3();break;
        case 7:vectorExercise4();break;
        case 8:vectorToBin();break;
        case 9:readVecBin(vectorToBin());break;
        
    
        default:
            cout << "Please enter a valid number" <<endl;
            break;
    }

    return 0;
}


