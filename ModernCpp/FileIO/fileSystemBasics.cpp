#include <iostream>
#include <experimental/filesystem>

int main(){
    namespace fs = std::experimental::filesystem;

    fs::path p{R"(/home/batman/test.bmp)"};

    if (p.has_filename()) {
        std::cout << p.filename() << "\n";
    }

    for(const auto&x : p)
    {
        std::cout << x << "\n";
    }

    fs::path p2{R"(/home/batman/)"};
    
    fs::directory_iterator beg{p2};
    fs::directory_iterator end{};
    while(beg!=end){
        std::cout << *beg << "\n";
        ++beg;
    }
    
    

}