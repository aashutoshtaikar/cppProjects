#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;
using boost::lexical_cast;
using boost::bad_lexical_cast;

int main(){
    int s = 23;
    
    string str = lexical_cast<string>(s);
    str = "Message: " + lexical_cast<string>('A') + "=" + lexical_cast<string>(34.5);
    
    boost::array<char,5> msg = lexical_cast<boost::array<char,5>>(12);
    //*msg.rbegin() = '3';
        msg.back() = '5';

    msg.front() = '4';


    s = lexical_cast<int>("3456");
    cout << s << "\n";
    
    for (int i : msg) cout << i << " ";
    cout << "\n";

    try{
        s = lexical_cast<int>("56.78"); //bad_lexical_cast
    }
    catch(const bad_lexical_cast& e){
        std::cerr << "Exception caught: " << e.what() << '\n';
    }
    // s = lexical_cast<int>("5678yu",4); //bad lexical cast
    s = lexical_cast<int>("5678yu",4);
    cout << s << "\n";
    
}