/* unique locks need not be constructed at time of declaration
 * unique locks are move assignable and move constructible
 * */

#include <iostream>
#include <mutex>
#include <thread>
#include <stack>

class Bank_Account {
	double m_balance;
	std::string m_holderName;
	std::mutex m_mtx;

public:
	Bank_Account() :
			m_balance { }, m_holderName { }, m_mtx { } {
	}

	Bank_Account(double inBalance, std::string inHolderName) :
			m_balance(inBalance), m_holderName(inHolderName) {
	}

	Bank_Account(const Bank_Account &other) = delete;
	Bank_Account &operator=(Bank_Account const &other) = delete;

	void Withdraw(double amount) {
		std::lock_guard<std::mutex> lg(m_mtx);
		if (m_balance >= amount) {
			m_balance -= amount;
			std::cout << m_holderName << "'s new balance: " << m_balance
					<< std::endl;
		} else {
			std::cout << m_holderName << " has insuficient balance: "
					<< m_balance << std::endl;
		}
	}

	void Deposite(double amount) {
		std::lock_guard<std::mutex> lg(m_mtx);
		m_balance += amount;
		std::cout << m_holderName << "'s new balance: " << m_balance << std::endl;
	}

	void Transfer(Bank_Account& from, Bank_Account& to, double amount) {

		std::unique_lock<std::mutex> ul_1(from.m_mtx,std::defer_lock);
		std::cout << "Lock for " << from.m_holderName << " account acquired by "<< std::this_thread::get_id() << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << " waiting to acquire lock for " << to.m_holderName << " account by " << std::this_thread::get_id() << std::endl;

		std::unique_lock<std::mutex> ul_2(to.m_mtx,std::defer_lock);
		std::lock(ul_1, ul_2); //all or nothing operation - either acquire mutex associated with both locks or it will wait for it

		if(m_balance>amount){
			from.m_balance -= amount;
			to.m_balance +=amount;
			std::cout << "Successfully transfered " << amount << " from " << from.m_holderName << " to " << to.m_holderName << std::endl;
		} else printf("Insufficient funds\n");


	}
};

int main() {
	Bank_Account account;
	Bank_Account BA_James(5000, "James");
	Bank_Account BA_Martin(10000, "Martin");

	std::thread t1(&Bank_Account::Transfer,&account, std::ref(BA_James),std::ref(BA_Martin), 500);
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	std::thread t2(&Bank_Account::Transfer,&account, std::ref(BA_Martin),std::ref(BA_James), 250);

	t1.join();
	t2.join();

	std::cin.get();
	return 0;
}
