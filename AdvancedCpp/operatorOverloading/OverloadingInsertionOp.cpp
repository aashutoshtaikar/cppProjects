#ifndef _HEADER_H
#include"Header.h"
#endif

class Test{
private:
    int iD;
    string namE;

public:
    Test():iD(0),namE(""){}

    Test(int id,string name):iD(id),namE(name){}

    void print(){
        cout << iD << ":" << namE << endl;
    }

    const Test &operator=(const Test &other){
        iD = other.iD;
        namE = other.namE;
        return *this;
    }

    //1.getters for private vars  OR 2. make this friend
    friend ostream &operator<<(ostream &out, const Test &test){
        out << test.iD << ":" << test.namE;
        return out;
    }
    
};

void OvInsertion1(){
    Test test1(10,"Mike");
    //  Left bit shift operator takes 2 args <<(test1, endl)
    cout << test1 << endl; 
}

int main(){
    
}