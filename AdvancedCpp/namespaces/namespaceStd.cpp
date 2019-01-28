#include<iostream>
#include<vector>
#include<functional>   //functional prog
#include<algorithm> //for find_if
#include<string>

void for_each(const std::vector<int>& values, const std::function<void(int)>& func){
    for(int value : values)
        func(value);
}


int main(){
    //using namespace std;  //may cause conflicts with the same name functions, thus better to use std::functionName

    std::vector<int> values = {1, 5, 4, 2, 3};
    
    auto it = std::find_if( values.begin(), values.end(), [](int value){return value > 3;} );
    std::cout << *it << std::endl;

    //int a = 5;

    auto lambda = [=](int value){ std::cout << "value: " << value << std::endl; };

    //ForEach(values, lambda); //this could have been fine as it doesn't have a c-style function name 

    for_each(values, lambda); //for_each will conflict with namespace std if using namespace std is used in this scope

    std::cin.get();

} //scope