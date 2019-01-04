#ifndef _HEADER_H 
#include "Header.h"
#endif

class Test{
    int id;
    string name;

public:

    Test():id(0),name(""){}

    Test(int i, string nam):id(i),name(nam){}
    
    void print(){
        cout << id << ":" << name << endl;
    }



    // bool operator<(const Itest &other) const{
    //     if(name==other.name){
    //         return id<other.id;
    //     }
    //     else{
    //         return name<other.name;             //sorts in alphabetical order
    //     }
    // }


    // friend bool comp(const Test &a,const Test &b);

};

class Itest:public Test{
private:
    string name;
    int id;
public:
    void print();
  //  Itest(int i,string nam):id(i),name(nam){}
    Itest(int i,string nam):Test(i,nam){
        id = i;
        name = nam;
    }
    bool operator<(const Itest &other) const{
        return name<other.name;
    }

    // bool operator<(const Test &other) const{
    //     return (getName()<other.getName());
    // }

};

// bool comp(const Test &a,const Test &b){
//     return a.name<b.name;
// }

void vecSortOperatorOv(){
    vector<Test> tests;

    tests.push_back(Test(5,"Mike"));
    tests.push_back(Test(10,"Ash"));
    tests.push_back(Test(7,"Raj"));
    tests.push_back(Test(8,"Vicky"));
    tests.push_back(Test(14,"Sue"));

    sort(tests.begin(),tests.end());    //sort accepts two iterators sort(start it,end it)

    for(int i=0;i<tests.size();i++){
        tests[i].print();
    }
}

//if the base classes are not user defined we can create a class which inherits the base class and implement operator overloading
//other option is to create a comparison function for the sort function
void vecSortFunctPointer(){

    vector<Itest> tests;

    tests.push_back(Itest(5,"Mike"));
    tests.push_back(Itest(10,"Ash"));
    tests.push_back(Itest(7,"Raj"));
    tests.push_back(Itest(8,"Vicky"));
    tests.push_back(Itest(14,"Sue"));

    //sort(tests.begin(),tests.begin()+1,comp); //sorts first 2 elements
   // sort(tests.begin(),tests.end(),comp);    //sort accepts two iterators and a function pointer sort(start it,end it,function pointer)

    for(int i=0;i<tests.size();i++){
        tests[i].print();
    }
}

// void dequeSortFunctPointer(){

//     deque<Test> tests;              //double ended queue - deque

//     tests.push_back(Test(5,"Mike"));
//     tests.push_back(Test(10,"Ash"));
//     tests.push_back(Test(7,"Raj"));
//     tests.push_back(Test(8,"Vicky"));
//     tests.push_back(Test(14,"Sue"));


// }

int main(){

    vecSortFunctPointer();
    //if sorting is needed regularly set must be implemented than a vector

    return 0;
}
