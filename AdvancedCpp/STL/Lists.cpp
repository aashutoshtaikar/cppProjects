#ifndef _HEADER_H 
#include "Header.h"
#endif

void list1Example(){
    //list is formed as a doubly linked list
    list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_front(0);

    list<int>::iterator it=numbers.begin();
    it++;
    it = numbers.insert(it,100);
    cout << "Element: " << *it << endl;

    list<int>::iterator eraseIt=numbers.begin();
    eraseIt++;
    eraseIt = numbers.erase(eraseIt);
    cout << "Element: " << *eraseIt << endl;

    for (list<int>::iterator it=numbers.begin();it!=numbers.end();){
        if(*it==2){
           numbers.insert(it,1234);  
        }
        if(*it==1){
            it = numbers.erase(it); //erase invalidates current iterator and returns the next iterator
        }    //problem: even if the iterator is initialized again it gets affected by the for loop incrementer 
        else{
            //solution: use a while loop 
            //or 
            //remove the for loop iterator and increment it here
            it++;
        }
    }

    for (list<int>::iterator it=numbers.begin();it!=numbers.end();it++){
        cout << *it << endl;
    }
}

void list2Example(){        //iterating list using a while loop
    list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_front(0);
    

    list<int>::iterator it=numbers.begin();
    while(it!=numbers.end()){
        if(*it==2){
           numbers.insert(it,1234);  
        }
        if(*it==1){
            it = numbers.erase(it); //erase invalidates current iterator and returns the next iterator
        }    //problem: even if the iterator is initialized again it gets affected by the for loop incrementer 
        else{
            //solution: use a while loop 
            //or 
            //remove the for loop iterator and increment it here
            it++;
        }
    }

    for (list<int>::iterator it=numbers.begin();it!=numbers.end();it++){
        cout << *it << endl;
    }
}

int listToBin(){
    //defining and initializing numbers list 
    list<int> numbers;

    for(int i = 0; i<=1000;i++){
        numbers.push_back(i);
    }
    
    //write numbers list to bin file
    string fileName="list.bin";
    fstream someFileToWrite;
    someFileToWrite.open(fileName,ios::out|ios::binary);
    for (list<int>::iterator it=numbers.begin();it!=numbers.end();it++){
        someFileToWrite.write((char*)&(*it),sizeof(int));
    }
    someFileToWrite.close();
    return numbers.size();
}

void readFromListBin(int numbers){
    list<int> numbersRead;
    string fileName="list.bin";
    //read the bin file into the numbersRead list
    fstream someFileToRead;
    someFileToRead.open(fileName,ios::in|ios::binary);
    for (int i = 0; i < numbers; ++i) {
      int j = 0;
      someFileToRead.read((char*)(&j),sizeof(int));
      numbersRead.push_back(j);
    }
    someFileToRead.close();

    //printing the numbersRead list
    for (list<int>::iterator it=numbersRead.begin();it!=numbersRead.end();it++){
        cout << *it << endl;
    }
}



int main(){
    cout << "Select a function to run1:" <<endl;
    cout << "1.list1Example" << endl;
    cout << "2.list2Example" << endl;
    cout << "3.listToBin" << endl;
    cout << "4.readFromListBin" << endl;

    int x;
    cin >> x;

    switch (x)
    {
        case 1:list1Example();break;
        case 2:list2Example();break;
        case 3:listToBin();break;
        case 4:readFromListBin(listToBin());break;
    
        default:
            cout << "Please enter a valid number" <<endl;
            break;
    }

    return 0;
}