#include <iostream>
#include "MorseCodeGenerator.h"

int main()
{
    MorseGen mgen;

    mgen.t.print2DUtil(mgen.t.root,0);
    
    return 0;
}
