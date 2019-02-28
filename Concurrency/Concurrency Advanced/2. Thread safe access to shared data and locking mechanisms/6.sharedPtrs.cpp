/*Shared pointers empty vs null
 https://stackoverflow.com/questions/25920681/what-is-the-difference-between-an-empty-and-a-null-stdshared-ptr-in-c

 	-Empty shared_ptr doesn't have control block and its use count considered to be 0.
	-Copy of empty shared_ptr is another empty shared_ptr. They are both separate shared_ptrs that doesn't share
 	  common control block because they don't have it. Empty shared_ptr can be constructed with default constructor
  	  or with constructor that takes nullptr.

	-Non-empty null shared_ptr has control block that can be shared with other shared_ptrs. Copy of non-empty null shared_ptr
	 is shared_ptr that shares the same control block as original shared_ptr so use count is not 0.
	 It can be said that all copies of shared_ptr share the same nullptr. Non-empty null shared_ptr can be constructed
	 with null pointer of object's type (not nullptr)
 */

#include <iostream>
#include <memory>


int main() {
	std::cout << "std::shared_ptr<int> ptr1:" << std::endl;
	{
		std::shared_ptr<int> ptr1;
		std::cout << "\tuse count before copying ptr: " << ptr1.use_count()
				<< std::endl;
		std::shared_ptr<int> ptr2 = ptr1;
		std::cout << "\tuse count  after copying ptr: " << ptr1.use_count()
				<< std::endl;
		std::cout << "\tptr1 is " << (ptr1 ? "not null" : "null") << std::endl;
	}
	std::cout << std::endl;

	std::cout << "std::shared_ptr<int> ptr1(nullptr):" << std::endl;
	{
		std::shared_ptr<int> ptr1(nullptr);
		std::cout << "\tuse count before copying ptr: " << ptr1.use_count()
				<< std::endl;
		std::shared_ptr<int> ptr2 = ptr1;
		std::cout << "\tuse count  after copying ptr: " << ptr1.use_count()
				<< std::endl;
		std::cout << "\tptr1 is " << (ptr1 ? "not null" : "null") << std::endl;
	}
	std::cout << std::endl;

	std::cout << "std::shared_ptr<int> ptr1(static_cast<int*>(nullptr))"
			<< std::endl;
	{
		std::shared_ptr<int> ptr1(static_cast<int*>(nullptr));
		std::cout << "\tuse count before copying ptr: " << ptr1.use_count()
				<< std::endl;
		std::shared_ptr<int> ptr2 = ptr1;
		std::cout << "\tuse count  after copying ptr: " << ptr1.use_count()
				<< std::endl;
		std::cout << "\tptr1 is " << (ptr1 ? "not null" : "null") << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
