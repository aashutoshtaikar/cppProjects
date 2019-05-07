#include <iostream>

/* Simple Template Usage */
template<typename Tfirst, typename Tsecond>
struct SimplePair
{
    Tfirst first;
    Tsecond second;

    SimplePair(Tfirst f, Tsecond s): first{f}, second{s} {};

    void PrintPair(){
        std::cout << first << ", " << second << '\n';    
    }
};

int runSimpleTemplate(){
    auto foo = SimplePair<int, double> {2,3.4};
    auto bar = SimplePair<std::string, int> {"lemons",42};
    std::cout << "foo : "; foo.PrintPair();
    std::cout << "bar : "; bar.PrintPair();    
}

/* templates with a non-type */
template<size_t NUMBER_OF_COPIES>
void copyPrint(const std::string& str){
    for(auto i = 0; i< NUMBER_OF_COPIES; i++){
        std::cout << str << '\n';
    }
}

void runCopyPrint(){
    copyPrint<3>("The team!");
}

int main(){
    // runSimpleTemplate();
    runCopyPrint();
}
