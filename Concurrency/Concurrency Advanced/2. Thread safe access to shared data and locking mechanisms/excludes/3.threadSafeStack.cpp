/*
 * */

#include <iostream>
#include <mutex>
#include <thread>
#include <stack>

template<typename T>
class trivial_thread_safe_stack{
	std::stack<T> stk;
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

	T& top(){
		std::lock_guard<std::mutex> lg(m);
		return stk.top();
	}

	void push(T val){
		std::lock_guard<std::mutex> lg(m);
		stk.push(val);
	}

	void pop(){
		std::lock_guard<std::mutex> lg(m);
		stk.pop();
	}
};

int main() {



	std::cout << "finished\n";
	return 0;
}
