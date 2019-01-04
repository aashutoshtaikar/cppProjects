#pragma once
#include<string>
using namespace std;
/*Hash functions ---- collision resolving:
					|-Seperate Chaining
					|-Open Addressing
*/
class HashIt {
private:
	static const int tableSize = 10;		//set 10 buckets/indexes

	struct item {
		string name;
		string drink;
		item* next;							//ability to point to some other item
	};

	item* Hashtable[tableSize];				//pointers having the ability to point to some item objects || array with buckets and each bucket/index has pointers inside

public:
	HashIt();									//constructor
	int Hash(string key);						//adds up ASCII values for each letter in name
	void AddItem(string name, string drink);	//adds name and drink to the Hashtable
	int NumOfItemsinIndex(int index);		//helper function to count the number of items
	void PrintTable();						//print the info contained in the first items of each of the buckets and how many items are in the bucket
	void PrintItemsinIndex(int index);
	int findBucket(string name);
};

HashIt::HashIt() {
	for (int i = 0; i < tableSize; i++) {
		Hashtable[i] = new item;
		Hashtable[i]->name = "empty";
		Hashtable[i]->drink = "empty";
		Hashtable[i]->next = NULL;
	}
}

int HashIt::Hash(string key) {
	// table size = 100
	// has value 453
	// 453/100 = 4 r 53
	int hash = 0;
	int index;

	for (int i = 0; i < key.length(); i++) {
		//cout << "key["<<i<<"]=" << (int)key[i] << endl; 

		hash = hash + (int)key[i];	//type casting - grabs the ASCII values of letters

		//cout << "hash=" << hash << endl;
	}

	index = hash % tableSize;
	
	return index;
}

void HashIt::AddItem(string name, string drink) {
	int index = Hash(name);	//index holds the location where we are going to store this name

	if (Hashtable[index]->name == "empty") {
		Hashtable[index]->name = name;
		Hashtable[index]->drink = drink;
	}
	else {

		item* Ptr = Hashtable[index];
		item* n = new item;
		n->name = name;
		n->drink = drink;
		n->next = NULL;				//end of the list

		while (Ptr->next != NULL) {	//traverse to the last item in that (Hashtable)list 
			Ptr = Ptr->next;
		}
		Ptr->next = n;				// link the last item to the newly created/added item
	}
}

int HashIt::NumOfItemsinIndex(int index) {
	int count = 0;
	if (Hashtable[index]->name == "empty") {
		return count;
	}
	else
	{
		count++;
		item* Ptr = Hashtable[index]; //point to the begenning of that index
		while (Ptr->next != NULL) {
			count++;
			Ptr=Ptr->next;
		}
	}
	return count;
}

void HashIt::PrintTable() {
	int number;
	for (int i = 0; i < tableSize; i++) {
		number = NumOfItemsinIndex(i);
		cout << "-----------------------------\n";
		cout << "index=" << i << endl;
		cout << Hashtable[i]->name << endl;
		cout << Hashtable[i]->drink << endl;
		cout << "no of items=" << number << endl;
		cout << "------------------------------\n";
	}
}

void HashIt::PrintItemsinIndex(int index) {
	item* Ptr = Hashtable[index];
	while (Ptr->next != NULL) {
		cout << "------------------------------\n";
		cout << Ptr->name  << endl;
		cout << Ptr->drink << endl;
		cout << "------------------------------\n";
		Ptr = Ptr->next;
	} 
	cout << "------------------------------\n";
	cout << Ptr->name << endl;
	cout << Ptr->drink << endl;
	cout << "------------------------------\n";
	delete Ptr;
}

int HashIt::findBucket(string name) {
	HashIt HObj;
	int num = HObj.Hash(name);
	item* Ptr = Hashtable[num%tableSize];
	for (Ptr = Ptr; Ptr->next != NULL; Ptr = Ptr->next) {
		if (Ptr->name == name) {
			cout << "------------------------------\n";
			cout << "Present in bucket " << num % tableSize << endl;
			cout << Ptr->name << endl;
			cout << Ptr->drink << endl;
			cout << "------------------------------\n";
			return (num % tableSize);
		}
	}
}