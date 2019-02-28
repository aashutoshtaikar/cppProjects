/* To resolve race condition inherit from interface
 * combine pop and top functions
 * */

#include <iostream>
#include <mutex>
#include <thread>
#include <stack>

template<typename T>
class trivial_thread_safe_stack{
	std::stack<std::shared_ptr<T>> stk;
	std::mutex m;

public:
	bool isempty(){
		std::lock_guard<std::mutex> lg(m);
		return stk.empty();
	}

	int size(){
		std::lock_guard<std::mutex> lg(m);
		return stk.size();
	}

	//combine top and pop -- returning already stored shared pointer cannot throw exception
	std::shared_ptr<T> pop(){
		std::lock_guard<std::mutex> lg(m);
		//check if empty
		if(stk.empty()) throw std::runtime_error("stack is empty");

		//construct a shared_ptr obj using the top value of stack
		std::shared_ptr<T> res(stk.top());
		stk.pop();
		return res;
	}

	void pop(T& value){
		std::lock_guard<std::mutex> lg(m);
		if(stk.empty()) throw std::runtime_error("stack is empty");
		value = *(stk.top().get());
		stk.pop();
	}

	////combine top and pop -- using a user provided reference for top function


	void push(T element){
		std::lock_guard<std::mutex> lg(m);
		stk.push(std::make_shared(element));
	}

};

int main() {



	std::cout << "finished\n";
	return 0;
}
