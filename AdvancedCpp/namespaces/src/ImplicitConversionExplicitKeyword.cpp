#include<iostream>
#include<string>

class Entity
{
private:
    std::string m_Name;
    int m_Age;
public:
    Entity(const std::string& text)
        :m_Name(text), m_Age(-1){}

    Entity(int age)
        :m_Name("Undefined"), m_Age(age){}

    int get_age()const{
        return m_Age;
    }

    std::string get_name()const{
        return m_Name;
    }
};

void PrintEntity(const Entity& entity){
    //printing
    std::cout << entity.get_name() << " " << entity.get_age() <<"\n";
}

int main(){
    /* this works */
    // Entity a("Ash");
    // Entity b(25);

    /* implicit conversions and issues*/

    //PrintEntity("Ash");     //error as the implicit conversion allows only 1 type conversion
    
    PrintEntity(std::string("Ash")); //type casting from char[] to string
    PrintEntity(Entity("Ash")); //implicit conversion helping
    PrintEntity(25);            //implicit conversion helping

    //Entity a = "Ash";   //error as the implicit conversion allows only 1 type conversion
    Entity b = 25;

    std::cin.get();
}