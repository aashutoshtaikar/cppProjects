#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

int getMinimumUniqueSum(vector<int> arr) {
    unordered_map<int,int> mapped_arr;

    //insert all elements into map
    for (auto i : arr){
        mapped_arr[i]++;
    }

    /* think of finder as a traveller iterator
        and count_handler bound to the fixed found value
     */
    for (auto &i : arr)
    {
        auto finder = mapped_arr.find(i);
        auto count_handler = finder; //saves the finder iterator

        //check for count 
        if (count_handler->second != 1)
        {
            while (finder != mapped_arr.end()) {
                i++;
                finder = mapped_arr.find(i);
            }
            count_handler->second--; //
            mapped_arr[i]++;
        }
    }

    //print the result
    for (const auto i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";

    //warning: accumulate last argument determines the return type
    return std::accumulate(arr.begin(), arr.end(), 0);

}

int main() {
    cout <<  getMinimumUniqueSum({3,2,1,2,7}) << "\n";
    cout <<  getMinimumUniqueSum({3,2,1,2,7,3,2,1,2,7}) << "\n";

    std::cin.get();
    return 0;
}