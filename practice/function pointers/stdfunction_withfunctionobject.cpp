/* std::function _ with function object(functor) 
reference : 
https://embeddedartistry.com/blog/2017/1/26/c11-improving-your-callback-game
https://stackoverflow.com/questions/4295432/typedef-function-pointer
*/

#include <iostream>
#include <functional>
typedef std::function<unsigned int(const std::string&)> HashFunction;

struct Hash {
    unsigned int operator()(const std::string& s) const {
        std::cout << s;
        return 0; // this is a pretty bad hash! a better implementation goes here
    }
};

int main() {
    HashFunction hash{ Hash() }; //functor has the same signature as the 
    hash("hello");
}