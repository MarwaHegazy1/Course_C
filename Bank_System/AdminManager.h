#pragma once
#include"EmployeeManager.h"
class AdminManager
{
private:
	static void printAdminMenu(){
		system("cls");
		cout << "(1) Display my info\n";
		cout << "(2) Update Password\n";
		cout << "(3) Add new client\n";
		cout << "(4) Search for client\n";
		cout << "(5) List all clients\n";
		cout << "(6) Edit client info\n";
		cout << "(7) Add new Employee\n";
		cout << "(8) Search for Empolyee\n";
		cout << "(9) List all Employee\n";
		cout << "(10) Edit Employee info\n";
		cout << "(11) Logout\n";
    }
	static void back(Admin* admin) {
		cout << endl;
		system("pause");
		AdminOptions(admin);
	}

public:
	static Admin* login(int id, string password){
		for (aIt = allAdmins.begin(); aIt != allAdmins.end(); aIt++) {
			if (aIt->getId() == id && aIt->getPassword() == password) return aIt._Ptr;
		}
		return NULL;
	}
	static bool AdminOptions(Admin* admin){
		cout << "\n\nYour choice is: ";
		Employee e;
		int choice, id;
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			admin->displayFunction();
			break;
		case 2:
			system("cls");
			ClientManger::updatePassword(admin);
			FileManager::updateAdmins();
			break;
		case 3:
			system("cls");
			EmployeeManager::newClient(admin);
			break;
		case 4:
			system("cls");
			EmployeeManager::searchForClient(admin);
			break;
		case 5:
			system("cls");
			EmployeeManager::listAllClients(admin);
			break;
		case 6:
			system("cls");
			EmployeeManager::editClientInfo(admin);
			break;
		case 7:
			e.setName(Validation::enterName());
			e.setPassword(Validation::enterPassword());
			e.setSalary(Validation::enterSalary());
			e.setId(FileHelper::getLast("EmployeeLastId.txt" + 1));
			admin->addEmployee(e);
			FileManager::updateEmployees();
			cout << "\nEmployee added successfully.\n";
			break;
		case 8:
			system("cls");
			cout << "Enter employee id: ";
			cin >> id;
			if (admin->searchEmployee(id) == NULL)
				cout << "\nEmployee not found.\n";
			else admin->searchEmployee(id)->displayFunction();
			break;
		case 9:
			system("cls");
			cout << "All employees: \n" << endl;
			admin->listEmployee();
			break;
		case 10:
			system("cls");
			cout << "Enter employee id: ";
			cin >> id;
			if (admin->searchEmployee(id) == NULL)
				cout << "\nEmployee not found.\n";
			else {
				string name = Validation::enterName();
				string password = Validation::enterPassword();
				double salary = Validation::enterSalary();
				admin->editEmployee(id, name, password, salary);
				FileManager::updateEmployees();
				cout << "\nEmployee info updated.\n";
				}
			break;
		case 11:
			return false;
			break;
		default:system("cls");
			AdminOptions(admin);
			return true;
		}back(admin);
		return true;
	}
};

