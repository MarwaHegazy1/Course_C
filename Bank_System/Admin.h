#pragma once
#include "Employee.h"

using namespace std;

class Admin :public Employee
{
private:
	Employee employee;
public:
	Admin() :Employee() {};

	Admin(int id, string name, string password, double Salary) :Employee(id, name, password, Salary) {}

	void addEmployee(Employee& employee) {
		allEmployees.push_back(employee);
	}
	Employee* searchEmployee(int id) {
		for (eIt = allEmployees.begin();eIt != allEmployees.end();eIt++) {
			if (eIt->getId() == id)return eIt._Ptr;
		}return NULL;
	}
	void editEmployee(int id, string name, string password, double salary) {
		searchEmployee(id)->setName(name);
		searchEmployee(id)->setPassword(password);
		searchEmployee(id)->setSalary(salary);
	}
	void listEmployee() {
		for (eIt = allEmployees.begin();eIt != allEmployees.end();eIt++)
			eIt->displayFunction();
		cout << "----------------------------\n";

	}
};
static vector<Admin> allAdmins;
static vector<Admin>::iterator aIt;


 