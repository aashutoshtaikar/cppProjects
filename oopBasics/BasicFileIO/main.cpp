#include<iostream>
#include<fstream>

using namespace std;

int getUserInput();
void displayItems(int x);

int main()
{
    int userInput{};

    userInput = getUserInput();

    while(userInput != 5){

        switch(userInput){
            case 1: 
                displayItems(1);
                break;
            case 2:
                displayItems(2);
                break;
            case 3:
                displayItems(3);
                break;
            case 4:
                displayItems(4);
                break;

        }
        
        userInput = getUserInput();
    }



    return 0;
}

void storeData(){

    ofstream outFile("objects.txt");


    cout << "Enter players ID, Name, and Money" << endl;
    cout << "0 to exit" << endl;

    int idNum;
    string name;
    double Money;
    char addMore{'y'};

    while(cin >> idNum >> name >> Money){
        outFile << idNum << ' ' << name << ' ' << Money << endl;
        cout << "Add more? y/n? : ";
        cin >> addMore;
        if (addMore == 'n') break;
    }


    
}


int getUserInput(){
    int choice;

    cout << "1 - all" << endl;
    cout << "2 - poor items" << endl;
    cout << "3 - rich items" << endl;
    cout << "4 - store items" << endl;
    cout << "5 - quit" << endl;

    cin >> choice;

    return choice; 
}

void displayItems(int x){
    ifstream inFile("objects.txt");
    
    int idNum;
    string name;
    double Money;

    if(x==1){
        while(inFile >> idNum >> name >> Money){
            cout << idNum  << ' ' << name << ' ' << Money << endl;
        }
    }

    if(x==2){
        while(inFile >> idNum >> name >> Money){
            if(Money < 0){
                cout << idNum  << ' ' << name << ' ' << Money << endl;
            }
        }
    }

    if(x==3){
        while(inFile >> idNum >> name >> Money){
            if(Money > 0){
                cout << idNum  << ' ' << name << ' ' << Money << endl;
            }
        }
    }

    if(x==4) {
        cout << " here";
        storeData();
    }
}