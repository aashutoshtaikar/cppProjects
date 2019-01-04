#ifndef _HEADER_H 
#include "Header.h"
#endif

//multimap even stores the values with same keys
void multimapExample(){

    multimap<int,string> lookup;

    //inserting elements with duplicate keys
    lookup.insert(make_pair(30,"Mike"));
    lookup.insert(make_pair(10,"Vicky"));
    lookup.insert(make_pair(30,"Raj"));
    lookup.insert(make_pair(20,"Bob"));

    for(multimap<int,string>::iterator it=lookup.begin();it!=lookup.end();it++){
        cout << it->first << ":" << it->second << endl;
    }
    cout <<"----" <<endl;

    //find element - not efficient
    for(multimap<int,string>::iterator it=lookup.find(30);it!=lookup.end();it++){
        cout << it->first << ":" << it->second << endl;
    }
    cout <<"----" <<endl;

     //find element - efficient
    //to get a range of elements from the map
    //c++98
    //create a pair of iterators it=  lookup.equal_range(key) - returns an iterator of pairs
    pair<multimap<int,string>::iterator,multimap<int,string>::iterator> its = lookup.equal_range(30);
    //iterate from one iterator to other
    //first points to the iterator to start of the range | second points to the iterator at the end of the map
    for(multimap<int,string>::iterator it=its.first;it!=its.second;it++){
        cout << it->first << ":" << it->second << endl;
    }
    cout <<"----" <<endl;

    //c++11
    auto its2 = lookup.equal_range(30);
    for(multimap<int,string>::iterator it=its2.first;it!=its2.second;it++){
        cout << it->first << ":" << it->second << endl;
    }

}

int multiMapFindRange() { 
    //https://www.geeksforgeeks.org/map-equal_range-in-c-stl/
    // initialize container 
    map<int, int> mp; 
  
    // insert elements in random order 
    mp.insert({ 4, 30 }); 
    mp.insert({ 1, 40 }); 
    mp.insert({ 6, 60 }); 
  
    pair<map<int, int>::iterator, map<int, int>::iterator> it; 
  
    // iterator of pairs 
    it = mp.equal_range(1); 
    cout << "The lower bound is " <<  
    it.first->first << ":" << it.first->second; 
  
    cout << "\nThe upper bound is " <<  
    it.second->first << ":" << it.second->second; 
  
    return 0;
/* output:
The lower bound is 1:40
The upper bound is 4:30  */
}

int main(){
    // multimapExample();
    multiMapFindRange();
    return 0;
}