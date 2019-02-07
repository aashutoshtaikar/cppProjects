/* Transfer ownership of mutex from one scope to another by unique lock's move constructor
 * unique locks need not be constructed at time of declaration
 * unique locks are move assignable and move constructible
 * */

#include <iostream>
#include <mutex>
#include <thread>
#include <stack>

void x_operations(){
	printf("this is x operation\n");
}

void y_operations(){
	printf("this is y operation\n");
}

std::unique_lock<std::mutex> get_lock(){
	std::mutex m;
	std::unique_lock<std::mutex> ul_1(m);
	x_operations();
	return ul_1;
}

int main() {
	std::unique_lock<std::mutex> ul_2(get_lock());	//move constructor transfers the ownership
	//std::unique_lock<std::mutex> ul_2 = get_lock(); //move assingment operator
	y_operations();

	//calling x_operations and y_operation happen under protection of the same mutex
	return 0;
}
