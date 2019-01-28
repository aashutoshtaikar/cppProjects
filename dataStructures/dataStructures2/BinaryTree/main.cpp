#include <iostream>
#include <fstream>
#include "BSTree.h"
using namespace std;

int main()
{
    string fileName = "input.txt";
    fstream inFile;
    inFile.open(fileName);

    //BSTree myTree;
    if (inFile.is_open())
    {
        string line;
        int num;

        while (!inFile.eof())
        {
            getline(inFile, line, ',');
            
        }
    }

    
    // while (!inFile.eof())
    // {
    //     getline(inFile, line);
    //     const char *p = line.c_str();
    //     while (*p != '\0')
    //     {
    //         if (*p != ',')
    //             cout << *p;
    //         p++;
    //     }
    //     cout << line;
    // }

    // myTree.insert(1);

    // node* temp = nullptr;
    // temp = myTree.search(1);
    // cout << temp->key_value;
    // delete temp;

    return 0;
}
