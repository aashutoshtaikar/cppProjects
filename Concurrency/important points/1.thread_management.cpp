#include <iostream>
#include <thread>
#include <string>
#include <functional>

void function1(){
    std::cout << "beauty is only skin-deep\n"; 
}

class Fctor{
public:
    void operator()(std::string& msg){
        std::cout << "t1 says: " << msg << "\n";
        // for(size_t i = 0; i >-100; i--)
        // {
        //     std::cout << "from t1" << i << "\n";
        // }
        msg = "passed by reference -- value changed";
    }
};

int main() {
    //Fctor fctor1;
    // std::thread t1(function1);
    // std::thread t1(fctor1);

    // return_type function_name(arg as fctor); 
    // std::thread t1( Fctor() );   //wrong way here we are not creating thread but declaring t1 function, function t1 returns a std::thread as shown above
    
    std::string s = "where there is no trust, there is no love";
    std::thread t1( (Fctor()), std::ref(s)); //brackets around Fctor() necessary to not declare a function of thread return type as shown above 
    try
    {
        std::cout << "from main: " << s << "\n";
        //throw; // test exception throw
    }
    catch (...)
    {
        //std::cerr << e.what() << '\n';
        t1.join();
        throw;
    }

    t1.join();
    return 0;
}