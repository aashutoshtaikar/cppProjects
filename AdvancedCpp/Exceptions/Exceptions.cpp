#include<iostream>

using namespace std;

void mightGoWrong(){
    bool error1 = false;
    bool error2 = true;
    if(error1){
        throw "something went wrong";
    }
    if(error2){
        throw string("something else went wrong");
    }

}

void usesMightGoWrong(){
    mightGoWrong();
}


int main(){
    try{
        usesMightGoWrong();
    }
    catch(int e){
        cout<<"Error Code:" << e <<endl;
    }
    catch(char const* e){
        cout<<"Error Code:" << e <<endl;
    }
    catch(string &e){ //catch by referrence is recommended for string object
        cout<<"Error Code:" << e <<endl;
    }
    cout<<"still running"<<endl;
    
    return 0;
}