#pragma once
#include"Admin.h"
#include"AdminManager.h"
#include <windows.h>

using namespace std;
class Screens
{
private:
	static void bankName(){
		cout << "\n\n\n\n\n\t\t\t\t\t\t****WELCOME TO OUR BANK****";
	}
	static void welcome(){
		bankName();
		Sleep(3000);
		system("cls");
	}
	static void loginOptions(){
		cout << "(1) Admin\n";
		cout << "(2) Employee\n";
		cout << "(3) Client\n";
		cout << "\n\nLogin as: ";
	}
	static int loginAs(){
		loginOptions();
		int choice;
		cin >> choice;
		if (choice == 1 || choice == 2 || choice == 3) {
			system("cls");
			return choice;
		}
		else {
			system("cls");
			return loginAs();
		}
	}
	static void invalid(int c){
		system("cls");
		cout << "Incorrect id or password.\n" << endl;
		loginScreen(c);
	}
    static void logout(){
		system("cls");
		loginScreen(loginAs());
	}
	static void loginScreen(int c){
		int choice = c, id;
		string pass;
		cout << "Enter id: ";
		cin >> id;
		cout << "Enter password: ";
		cin >> pass;
		switch (choice) {
		case 1:
			if (AdminManager::login(id, pass) != NULL) {
				while (AdminManager::AdminOptions(AdminManager::login(id, pass)) != false);
				logout();
			}
			else invalid(1);
			break;
		case 2:
			if (EmployeeManager::login(id, pass) != NULL) {
				while (EmployeeManager::employeeOptions(EmployeeManager::login(id, pass)) != false);
				logout();
			}
			else invalid(2);
			break;
		case 3:
			if (ClientManger::login(id, pass) != NULL) {
				while (ClientManger::clientOptions(ClientManger::login(id, pass)) != false);
				logout();
			}
			else invalid(3);
			break;
		default:
			system("cls");
			loginOptions();
		}
	}	
public:
	static void runApp(){
		FileManager::getAllData();
		welcome();
		loginScreen(loginAs());
	}
};

