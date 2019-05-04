#include <iostream>
#include <string>
#include <memory>
#include <typeinfo>
#include "custom_uniqueptr.h"

class Entity{
    std::string m_name;
public:
    Entity():m_name{}{
        printf("Empty Entity created\n");
    }

    Entity(std::string n):m_name(n){
        std::cout << m_name << " Entity created\n";
    }
    ~Entity(){
         std::cout << m_name << " Entity destroyed\n";
    }
};

class custom_uniqueptr{
public:
    static void reset()
    {
        using namespace memory_ayt;
        {
            unique_ptr<Entity> x(new Entity("x_en"));
            unique_ptr<Entity> y = std::move(x);
            y.reset();
            y = unique_ptr<Entity>(new Entity("y_en"));
        }
        std::cout << "done\n";
    }

    static void lvalues()
    {
        using namespace memory_ayt;

        int x = 10;
        // unique_ptr<int> y = &x; //should not be allowed in the first place
        unique_ptr<int> y = make_unique(x);
        std::cout << *y << "\n";
    }
};


class std_uniqueptr{
public:
    static void test_stduniqueptr_reset()
    {
        using namespace std;
        {
            unique_ptr<Entity> x(new Entity("x_en"));
            unique_ptr<Entity> y = std::move(x);
            y.reset();
            y = unique_ptr<Entity>(new Entity("y_en"));
        }
        std::cout << "done\n";
    }

    static void test_stduniqueptr_lvalues()
    {
        using namespace std;
        {
            int x = 10;
            // unique_ptr<int> der = &x; //no suitable constructor exists to convert from "int *" to "std::unique_ptr<int, std::default_delete<int>>"
            unique_ptr<int> y = make_unique<int>(x);
            std::cout << *y;
        }
        std::cout << "done\n";
    }
};


int main() {
    custom_uniqueptr::reset();
    custom_uniqueptr::lvalues();   //problem with the stack value int x being de-allocated
    
    return 0;
}