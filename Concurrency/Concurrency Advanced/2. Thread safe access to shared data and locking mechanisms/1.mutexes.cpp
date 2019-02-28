//============================================================================
// Name        : mutexes.cpp
// Author      : Aashutosh
// Version     :
// Copyright   : All rights reserved
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * #include<mutex>
lock
locks the mutex, blocks if the mutex is not available
(public member function)

try_lock
tries to lock the mutex, returns if the mutex is not available
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

std::list<int> my_list;
std::mutex m;

void add_to_list(int const & x){
	m.lock();
	my_list.push_front(x); //push_front is an invariant
	m.unlock();
}

void size(){
	m.lock();
	my_list.size();
	m.unlock();
}

int main() {
	std::thread thread1(add_to_list, 4);
	std::thread thread2(add_to_list, 11);

	thread1.join();
	thread2.join();
	std::cout << "finished\n";

	return 0;
}
