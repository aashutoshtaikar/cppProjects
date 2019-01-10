/* convienience : lets you easily define a type equivalent to reference any callable type(anything you can call by ()) */

#include<iostream>
#include<functional>
#include<vector>
#include<algorithm> //count_if

using namespace std;

bool check(string &test){
    return test.size() == 3;
}

class Check{
public:
    bool operator()(string& txt){
        return txt.size() == 3; 
    }
} check1;

void run( function<bool(string&)> check){    //enabled by #include<functional>
    string test = "dog";
    cout << check(test) << endl;
}

int main(){

    int size = 5;

    vector<string> vec{"one","two","three"};

    /* //as count_if accepts functions with a function pointer we can pass lambda expression. */
    auto lambda = [size](string test){return test.size()==size;};

    int count =  count_if(vec.begin(),vec.end(),lambda) ; 
    cout << count << endl;

    count = count_if(vec.begin(),vec.end(),check);
    cout << count << endl;

    int countx =  count_if(vec.begin(),vec.end(),check1);
    cout << countx << endl;

    run(lambda);  //pass lambda
    run(check1); //pass functor
    run(check);   //pass function

    function<int(int,int)> add = [](int x, int y){return x+y;};
    cout << add(7,3) << endl;

    return 0;
}