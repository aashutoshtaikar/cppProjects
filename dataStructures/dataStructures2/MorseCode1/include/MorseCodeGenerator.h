#include <string>
#include "BST.h"

struct alphaTree
{
    std::string letter;
    std::string code;
};

alphaTree tree[]= {  
                    {"ROOT", ""},  {"E", "."},    {"T", "-"},    {"I", ".."},   {"A", ".-"},   {"N", "-."},   
                    {"M", "--"},   {"S", "..."},  {"U", "..-"},  {"R", ".-."},  {"W", ".--"},  {"D", "-.."},  
                    {"K", "-.-"},  {"G", "--."},  {"O", "---"},  {"H", "...."}, {"V", "...-"}, {"F", "..-."}, 
                    {"L", ".-.."}, {"P", ".--."}, {"J", ".---"}, {"B", "-..."}, {"X", "-..-"}, {"C", "-.-."}, 
                    {"Y", "-.--"}, {"Z", "--.."}, {"Q", "--.-"}  
                };

class MorseGen
{
  public:
   
    BSTree t;
    
    MorseGen()
    {          
        for (int i = 0; i < 27; i++)
        {
            t.insert(tree[i].letter, tree[i].code);
        }
    }

    ~MorseGen(){

    }

    void generate(const char* input_str){
        
    }
};