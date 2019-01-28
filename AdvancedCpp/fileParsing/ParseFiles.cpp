#include<iostream>
#include<fstream>
using namespace std;

////parsing text files with different datatypes
int main(){
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
        ////OR
        input >> ws;    //ws is whitespace in (c++11)

        if(!input){     //for breaking on maformed lines formed during error
            break;      //error state as the input file ends
        }

        cout << "'" << line << "'" << "--'" << population << "'" <<endl;
    }
    input.close();

    return 0;
}

