
  
  static const int tableSize = 10;

  struct item{
      bool value;
      bool first;
      bool last;
      item* next;
      item* prev;
  };

  item* HashTable[tableSize];


//hashTable contains 1-10 indices to scaled to the times a cell is written. 
//for eg. index[1] ~ 1 - 1000 R/Wcycles 

void cellHashWrite(bool i){ //writes to a least written cell 
    //get fileSize

    int hIndex=0;
    //get a non empty hashIndex
    for(int i=0;i<tableSize;i++){
        if(!hashObj.IsEmpty(i)){
            hIndex = i;
            //see if it is already written

            break;
        }
    }

    if (HashTable[hIndex]->Value!=1){
        
    }  
    



}  
