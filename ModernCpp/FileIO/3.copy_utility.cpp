/* copy text files */
#include <boost/filesystem.hpp>
#include <iostream>
#include <boost/filesystem/fstream.hpp>
#include <string>

using namespace std;
namespace fs =  boost::filesystem;

int main(){
    fs::path source{fs::current_path()};
    //cout << source.string() << "\n";

    try{
        fs::file_status s = status(source);
        cout << boolalpha << is_directory(s) << "\n";
    }
    catch(const fs::filesystem_error& e){
        std::cerr << e.what() << '\n';
    }

    source /= "src/3.copy_utility.cpp";

    fs::path dest(fs::current_path());
    dest /= "Copy_3.copy_utility.cpp" ;

    fs::ifstream input{source};
    if(!input){
        cout << "Source file not found\n";
        return -1;
    }
    
    fs::ofstream output{dest};
    string line;
    while(!std::getline(input,line).eof()){
        output << line << "\n";
    }
    input.close();
    output.close();

    return 0;
}