#pragma once
#include"Person.h"

class Client :public Person {
private:
	double balance;
public:
	Client() :Person() {
		this->balance = 0.0;
	}
	Client(int id, string name, string password, double balance) :Person(id, name, password) {
		setBalance(balance);
	}
	void setBalance(double balance) {
		this->balance = balance;
	}
	double getBalance() {
		return balance;
	}
	void deposit(double amount) {
		if (amount > 0)
			this->balance += amount;
		cout << "\nSuccessful transaction.\n";
	}
	void withdraw(double amount) {
		if (amount <= balance && amount > 0){
			this->balance -= amount;
		cout << "\nSuccessful transaction.\n";
	}
		else cout << "\nAmount Exceeded.\n";
	}
	void transferTo(double amount, Client& reciptient) {
		if (amount <= balance) {
			this->balance -= amount;
			reciptient.balance += amount;
			cout << "\nSuccessful transaction.\n";
		}
		else cout << "\nAmount Exceeded.\n";
		
	}
	void checkBalance() {
		cout << "Balance is: " << balance << endl;
	}
	void displayFunction() {
		Person::displayFunction();
		cout << "Balance is: " << balance << endl;
	}
};
static vector<Client> allClients;
static vector<Client>::iterator clIt;


