#pragma once
#include"Client.h"
#include <fstream>

class Employee : public Person {
private:
	double salary;
public:
	Employee() :Person() {
		this->salary = 0.0;
	}
	Employee(int id, string name, string password, double salary) :Person(id, name, password) {
		setSalary(salary);
	}
	void setSalary(double salary) {
		this->salary = salary;
	}
	double getSalary() {
		return salary;
	}
	void displayFunction() {
		Person::displayFunction();
		cout << "Salary " << getSalary() << endl;
	}
	
	void addClient(Client& client) {
		allClients.push_back(client);
	}
    Client* searchClient(int id) {
		for (clIt = allClients.begin();clIt != allClients.end();clIt++) {
			if (clIt->getId() == id)return clIt._Ptr;//address the client we want  
		}return NULL;
	 }
	void listClient() {
		for (clIt = allClients.begin();clIt != allClients.end();clIt++) 
			clIt->displayFunction();
			cout << "----------------------------\n";
	}
	void editClient(int id, string name, string password, double balance) {
		searchClient(id)->setName(name);
		searchClient(id)->setPassword(password);
		searchClient(id)->setBalance(balance);
	}
};
static vector<Employee> allEmployees;
static vector<Employee>::iterator eIt;

