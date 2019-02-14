#include <iostream>
/* Static member function can only access static members (aka Class Methods)
public static members(functions/variables) can be accessed directly using scope operator

Non-Static members function can access all -- static as well as non-static
*/
using namespace std;

class static_demo
{
private:
	static int b;

public:
	static void staticPrint(){std::cout << "hello from static function\n";}
	void nonStaticPrint(){std::cout << "hello from non-static function\n";}
	
	static int getb(){
		return b;
	}
	
	int nonStaticgetb(){
		return b;
	}
	
	static void print(){
		staticPrint(); // works --static function can access all static members(functions/variables)
		//nonStaticPrint(); //won't work -- a static function cannot access "this"
	}
	

};

//static member variables need to be initialized outside a class
int static_demo::b=10;

int main()
{
	//std::cout << static_demo::b << '\n'; // cannot access as member is public
   std::cout << static_demo::getb();	//accessing static member with static member function
   
   static_demo obj;
   std::cout << obj.nonStaticgetb();	//accessing static member with non-static member function

   return 0;
}