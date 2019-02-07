#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std; 

int parTn(vector<int> input, int from, int to);
void quickSort(vector<int> input, int from, int to);

int parTn(vector<int> input, int from, int to){
    int pivot = input[to];      //choosing pivot as the end O(n^2)
    int wall = from;
    for(int i = from; i < to; i++){
        if(input[i]<=pivot){        
            int temp = input[wall];
            input[wall] = input[i];
            input[i] = temp;
            wall++;                 //increment wall 
        }
        //else if elements<pivot continue incrementing i and not incrementing wall
    }
    //swap the pivot to the wall position
    input[to]=input[wall];
    input[wall]=pivot;
    return wall;
}

void quickSort(vector<int> input, int from, int to){
    if (from<to) {
        int indexOfPivot = parTn(input, from, to);
        quickSort(input, from, indexOfPivot - 1);
        quickSort(input, indexOfPivot+1 , to);
    } 
}

// int main(int argc, char const *argv[])
// {
//     quickSort();
//     return 0;
// }



