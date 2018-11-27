#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

class AIfunctions{
    public:
    // AIfunctions();
    // ~AIfunctions();
    int inputSize;
    int wordCount;

    int countWords(string s);
    char* evalInput(string aiInput);
    vector<string> wordSeperator(string s);

};

// AIfunctions::AIfunctions(){
//     cout<<"Hi I am an AI"<<endl; 
// }

// AIfunctions::~AIfunctions(){
//     cout<<"Good Bye"<<endl;
// }

//count words
int AIfunctions::countWords(string s){
    int state = 0; //OUT
    unsigned wc = 0;

    //copy string to char
    char cstr[s.length()+1];
    strcpy(cstr,s.c_str());
    char *ch = cstr;

    while(*ch){
        if(*ch==' '||*ch=='\n'|| *ch=='\t'){
            state=0;
        }
        else if(state==0){
            state = 1;
            ++wc;
        }
        ++ch;
    }
    return wc;
}

vector<string> AIfunctions::wordSeperator(string s){
    string tmpWord;              //tmpWord to fill one word
    vector<string> sepWords;    //sepWords to 
    int state = 0;

    //copy string to char
    char cstr[s.length()+1];
    strcpy(cstr,s.c_str());
    char *ch = cstr;

    while(*ch){
        if(*ch==' '||*ch=='\n'||*ch=='\t'){
            sepWords.push_back(tmpWord);
            tmpWord.erase();
        }
        else {
            //state = 1;
            tmpWord += *ch;              
        }
        ++ch;   
    }
    sepWords.push_back(tmpWord);
    return sepWords;
}

char* AIfunctions::evalInput(string aiInput){
    int wordsMatched=0;
    //check if DefaultText matches aiInput
    string test = "hey how are you";
    
    vector<string> aiInputSep = wordSeperator(aiInput);
    vector<string> testSep = wordSeperator(test); 

    //O(n2)
    for(int i=0;i<countWords(aiInput);i++){
        for(int j=0;j<countWords(test);j++){
            if(aiInputSep[i]==testSep[j]){
                wordsMatched++;
            }
        }
    }

    //check for the match percentage if >50% execute task else print error
    double percent=(double)wordsMatched/countWords(test);
    if( percent >= 0.5){
        cout<<"I am good. How are you doing?"<<endl;
    }

}