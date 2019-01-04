#ifndef _HEADER_H 
#include "Header.h"
#endif

void mapsintroExample(){
   //map - key value pairs
   //keys are always unique
    map<string,int> ages;

    //way of adding things to map
    ages["Mike"] = 40;
    ages["Raj"] = 20;
    ages["Vicky"] = 30;
    cout << ages["Raj"] << endl;
    ages["Mike"] = 70;

    //another way of adding things to map - create a pair and add it to map
    pair<string,int> addToMap("Peter",100);
    ages.insert(addToMap);
    //another way
    ages.insert(pair<string,int>("Sam",30));
    //function which doesn't require <type> specifiers and returns a pair of the right type; 
    ages.insert(make_pair("Ash",90));

    //incorect way to check values in map
    cout << ages["sue"] << endl; //array subscript overloaded operator adds a key in map
    //corect way to check values in map
    if(ages.find("Vicky")!=ages.end()){
        cout <<"found vicky" <<endl;
    }
    else{
        cout << "key not found" << endl;
    }

    //printing a map
    for(map<string,int>::iterator it=ages.begin();it!=ages.end();it++){
        cout << it->first << ":" << it->second << endl;
    }
    //another way of printing a map
    for(map<string,int>::iterator it=ages.begin();it!=ages.end();it++){
        pair<string,int> age = *it;
        cout << age.first << ":" << age.second << endl;
    }  
}

//use an object of own class as the values and keys --- 
//1. Custom objects as map values
class Person{
private:
    string name;    //assignment operator creates a shallow copy of these vars
    int age;        //sometimes this is undersirable

    // you want some of them to be diff for the copied object
    //thus (assignment)operator overloading is needed

public:
    //Default constructors does only shallow copy.
    Person(): name(""), age(0){
        //parameterless constructor necessary for the Map
        //program won't won't compile if this is not included
        //Map creates an object first and then adds values
    }

    //copy constructor
    //Deep copy is possible only with user defined copy constructor.
    Person(const Person &other){
        cout << "copy constructor running" << endl;
        name = other.name;
        age = other.age;
    }


    Person(string name, int age):
        name(name), age(age){
    }

    void print(){
        cout << name << ":" << age << endl;
    }
};

void customObjAsValueExample(){
    map<int, Person> people;
    people[0] = Person("Mike",40);
    people[1] = Person("Vicky",30);
    people[3] = Person("Raj", 50);

    people.insert(make_pair(55,Person("Bob",45)));
    people.insert(make_pair(60,Person("sue",43)));

    for(map<int,Person>::iterator it = people.begin(); it!=people.end();it++){
        cout << it->first << ":" <<flush;
        it->second.print();
    }
}

/*  When is user-defined copy constructor needed?
If we don’t define our own copy constructor, the C++ compiler creates 
a default copy constructor for each class which does a member-wise 
copy between objects. The compiler created copy constructor works 
fine in general. We need to define our own user defined copy constructor only 
if an object has pointers or any runtime allocation of the resource 
like file handle, a network connection..etc.  */

//Custom Objects as keys in maps
class Personk{
private:
    string name;    
    int age;        

public:
    //Default constructors does only shallow copy.
    Personk(): name(""), age(0){
    }

    //Deep copy - copy constructor
    Personk(const Personk &other){
        name = other.name;
        age = other.age;
    }


    Personk(string name, int age):
        name(name), age(age){
    }

    void print() const{
        cout << name << ":" << age << flush;
    }

    //operator overloading - first taste for usage of objects as keys
    //each new object passed as a key has to be unique/different  
    //if a new object is the same it is checked against its name else if it has same name 
    //it is check against age and updated accordingly
    
    bool operator<(const Personk &other) const{ 
        if(name == other.name){     //If the key's name is same 
            return age < other.age; //for age to be taken into account
        } else{
            return name < other.name;
        }
    }  
};

void customObjAsKeyExample(){
    map<Personk, int> people;

    people[Personk("Mike",40)] = 40;
    people[Personk("Mike",60)] = 22; //updates the value in the map to 22 for the key; key wont be changed
    //if you want a key's attribute (age), change the overloaded operator 

    people[Personk("Vicky",30)] = 20;
    people[Personk("Raj", 50)] = 30;


    for(map<Personk,int>::iterator it = people.begin(); it!=people.end();it++){
        it->first.print(); //won't work if the print() is not const as the keys in maps are const
        cout <<  ":" << it->second  <<endl;
    }   //still won't work if operator ovverloading is not done as keys in maps need to be added in an order
}

int main(){
    // mapsintroExample();         //basics
    // customObjAsValueExample();  //parameterless constructor and copy constructor  
    customObjAsKeyExample();    //operator overloading to order keys as they are added to map
}