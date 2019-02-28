//============================================================================
// Name        : mutexes.cpp
// Author      : Aashutosh
// Version     :
// Copyright   : All rights reserved
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * using lock_guard with mutex for scoped mutex
 * #include<mutex>
lock
locks the mutex, blocks if the mutex is not available
(public member function)

try_lock
tries to lock the mutex, returns if the mutex is not available -- no need to unlock for that scope
(public member function)

unlock
unlocks the mutex
(public member function)
 *
 * */

#include <iostream>
#include <mutex>
#include <thread>
#include <list>
#include <functional>


class data_object{
	int x{};
public:
	data_object():x(0){
		std::cout << "Protected\n";
	}
};

class data_wrapper{

	std::list<int> my_list;
	data_object protected_data;
	std::mutex m;

public:
	void add_to_list(int const & x){
		std::lock_guard<std::mutex> lg(m);
		my_list.push_front(x); //push_front is an invariant
	}

	void size(){
		std::lock_guard<std::mutex> lg(m);
		my_list.size();
	}

	std::list<int>* get_data(){	//unsafe 1. caller may alter things -- thus is not thread safe to do this
		return &my_list;	//returning a pointer to private/protected_data
	}

	template<typename function>
	void do_some_work(function f){
		std::lock_guard<std::mutex> lg(m);
		f(protected_data);	//unsafe 2. even though we are locking this we don't know what this function would do
	}
};

data_object* unprotected_data;

void malicious_function(data_object& data){
	unprotected_data = &data;	//unsafe 3. other threads may access this unprotected_data and alter it
}


int main() {
	data_wrapper wrapper;
	wrapper.do_some_work(malicious_function);

	std::cout << "finished\n";

	return 0;
}

