/* tuple assignment :
-Any number or any combo of types
-No type info needed at runtime
-get<n> function that lets us access the nth element of the tuple

*/
#include <iostream>

/* void testTupleAssignment(){
    Tuple<int,char> tuple;
    get<0>(tuple) = 32;     //assign to the tuple
    get<1>(tuple) = 'c';

    auto v1 = get<0>(tuple);   //assign from the tuple
    auto v2 = get<1>(tuple);
    assert(v1==34);
    assert(v2 =='c');
} 

void testMakeTuple(){
    auto t2 = makeTuple(63,'H',std::string{"foo"});
    assert(get<0>t2 == 64);
    assert(get<1>(t2)=='H');
    assert(get<2>(t2=="foo"));
}
*/

int main() {
    std::cout << "Hello Easy C++ project!" << std::endl;
}