/* 
variants provides method to save different data types and
visitor provides facility to act upon them depending on the type without worrying about type,

 */

#include <iostream>
#include <vector>
#include <string>
#include <boost/variant.hpp>

using namespace std;

// functor derived from boost::static_visitor<> to accept string or int and operate over variant 
class StringIntVisitor : public boost::static_visitor<>{
  public:
    void operator()(int &i) const
    {
        i += 1;
    }
    void operator()(string &str) const
    {
        str += str;
    }
};

int main(){
    //1. problem with std::union container
    union {int i; float f;} u;
    u.i = 34;
    u.f = 2.3; // overwritten

    //union {int i; string s;} u; //but cannot do this
    boost::variant<int,string> u1,u2;
    u1 = 2; u2 = "hello";
    cout << u1 << u2 << endl;

    //u1 = u1 * 2;  //cannot operate like this
    u1 = boost::get<int>(u1)*2;

    // problem with get: need to know the datatype 
    //string st = boost::get<string>(u1); //throw exception of bad_get,
    
    //variant advantage - can store/change any variant of existing datatype
    u1 = "good"; //u1 becomes a string
    u1 = 32; //u1 becomes int

    //defaults
    boost::variant<int,string> u3;
    cout << u3 << endl;

    //solution using functor
    u1 = 3;
    boost::apply_visitor(StringIntVisitor(),u1);   // u1 becomes 4
    u2 = 1;
    boost::apply_visitor(StringIntVisitor(),u2);  // u2 becomes "hellohello"
    cout << u1 << u2 << endl;

// even more powerful things
    std::vector< boost::variant<int,string> > vec;
    vec.push_back("good");
    vec.push_back("bad");
    vec.push_back(23);
    vec.push_back(1.2);
    for (auto& x : vec) cout << x << " ";
    cout << endl;

    StringIntVisitor f;
    for (auto& x : vec) boost::apply_visitor(f,x);
    for (auto& x : vec) cout << x << " ";
}

/* 
    Note reminders:  auto& - gets element(by-reference) from container 
*/