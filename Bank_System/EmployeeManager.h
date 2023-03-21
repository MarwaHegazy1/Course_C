#pragma once
#include "ClientManger.h"
class EmployeeManager
{
private:
	static void printEmployeeMenu() {
		system("cls");
		cout << "(1) Display my info\n";
		cout << "(2) Update Password\n";
		cout << "(3) Add new client\n";
		cout << "(4) Search for client\n";
		cout << "(5) List all clients\n";
		cout << "(6) Edit client info\n";
		cout << "(7) Logout\n" << endl;
	}
	static void back(Employee* employee) {
		cout << endl;
		system("pause");
		employeeOptions(employee);
	}
public:
    static void newClient(Employee* employee){
		Client client;
		client.setId(FileHelper::getLast("ClientLastId.txt") + 1);
		client.setName(Validation::enterName());
		string password;
		client.setPassword(Validation::enterPassword());
		employee->addClient(client);
		FileManager::updateClients();
		cout << "\nClient added successfully.\n";
	}
	static void listAllClients(Employee* employee){
		system("cls");
		cout << "All clients: \n" << endl;
		employee->listClient();
	}
	static void searchForClient(Employee* employee) {
		int id;
		system("cls");
		cout<< "Enter client id: ";
		cin >> id;
		if (employee->searchClient(id) == NULL)cout << "\nClient not found.\n";
		else employee->searchClient(id)->displayFunction();
	}
	static void editClientInfo(Employee* employee){
		int id;
		system("cls");
		cout << "Enter client id: ";
		cin >> id;
		if(employee->searchClient(id)==NULL)
			cout << "\nClient not found.\n";
		else {
			string name = Validation::enterName();
			string password = Validation::enterPassword();
			double balance = Validation::enterBalance();
			employee->editClient(id, name, password, balance);
			FileManager::updateClients();
			cout << "\nClient info updated.\n";
		}
	}
    static Employee* login(int id, string password){
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			if (eIt->getId() == id && eIt->getPassword() == password) return eIt._Ptr;
		}
		return NULL;
	}
	static bool employeeOptions(Employee* employee){
		printEmployeeMenu();
		cout << "\n\nYour choice is: ";
		int choice;
			printEmployeeMenu();
			cin >> choice;
			switch (choice) {
			case 1:
				system("cls");
				employee->displayFunction();
				break;
			case 2:
				system("cls");
				ClientManger::updatePassword(employee);
				FileManager::updateEmployees();
				break;
			case 3:
				system("cls");
				newClient(employee);
				break;
			case 4:
				system("cls");
				searchForClient(employee);
				break;
			case 5:
				system("cls");
				listAllClients(employee);
				break;
			case 6:
				system("cls");
				editClientInfo(employee);
				break;
			case 7:
				return false;
				break;
			default:
				system("cls");
				employeeOptions(employee);
				return true;
			}
			back(employee);
			return true;
	}
};
