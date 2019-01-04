#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//if string size is 3
bool match(string test){
    return test.size() == 3;
}

bool matchx(string test,int sz){
    return test.size() == sz;
}

//own version of count_if
int countStrings(vector<string> &texts, bool (*match)(string test,int sz)){
    int count{0};
    for(auto& e:texts){
        if(matchx(e,3)==true){
            count++;
        }
    }

    return count;
}


int main(){
    vector<string> texts;
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("four");
    texts.push_back("five");
    texts.push_back("six");
    

   cout <<"elements containing 3 letter string: " << endl;
   cout << count_if(texts.begin(),texts.end(),match) << endl; //algorithm which counts if match criteria is true
    
    cout << countStrings(texts,&matchx) << endl;

    return 0;
}
