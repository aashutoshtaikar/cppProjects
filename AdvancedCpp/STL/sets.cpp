#ifndef _HEADER_H 
#include "Header.h"
#endif

class Person{
private:
    string namE;
    int agE;

public:
    Person():namE(""),agE(0){
    }

    //copy constructor - accepts an object of Person type
    //the variables can be set as per the object attributes
    Person(const Person &other){
        namE = other.namE;
        agE = other.agE;
    }

    Person(string name, int age):namE(name),agE(age){
    }

    void print() const{
        cout << namE << ":" << agE << endl;
    }

    //setting uniqueness
    bool operator<(const Person &other) const{  //const object reference ensures that the refered object is read-only
        return namE<other.namE;
    }

    //find functions
    bool contains(string name) const{   //const(read-only) ensures that this method cannot change any instance variables 
        return (namE==name);
    }

    bool contains(int age) const{
        return (agE==age);
    }
};

void set1Example(){
    set<int> numbers;   //a set only stores unique elements, same value won't be inserted again
    numbers.insert(1);
    numbers.insert(2);

    for(set<int>::iterator it=numbers.begin();it!=numbers.end();it++){
        cout << *it << endl;
    }

    set<int>::iterator it = numbers.find(1);
    if(it!=numbers.end()){
        cout << "found here" << endl;
    }

    if(numbers.find(1)!=numbers.end()){
        cout << "found" << endl;
    }

    if(numbers.count(2)){
        cout << "Number found." <<endl;
    }
}

void set2Example(){
    set<Person> people;   //a set only stores unique elements, same value won't be inserted again
    people.insert(Person("Jack",10));
    people.insert(Person("Sam",20));

    for(set<Person>::iterator it=people.begin();it!=people.end();it++){
        it->print();

        if(it->contains("Jack")){
            cout << "found name" <<endl;
        } 

        if(it->contains(10)){
            cout << "found age" <<endl;
        }
    }

}

int main(){
    cout << "Select a function to run1:" <<endl;
    cout << "1.set1Example" << endl;
    cout << "2.set2Example" << endl;

    int x;
    cin >> x;

    switch (x)
    {
        case 1:set1Example();break;
        case 2:set2Example();break;

        
        default:
            cout << "Please enter a valid number" <<endl;
            break;
    }

    return 0;
}
