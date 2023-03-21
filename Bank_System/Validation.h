#pragma once
#include<string>
#include<iostream>
using namespace std;
static class Validation
{
private:
	static bool isValidAlphabetic(string str)
	{
		for (int i = 0; i < (int)str.length(); i++)
		{
			if (!isalpha(str[i]) && !isspace(str[i])) return false;
		}
		return true;
	}
	static bool validateName(string name) {
		int len = (int)name.length();
		if (len < 5 || len > 20 || isValidAlphabetic(name) == false)
			return false;
	}
	static bool validatePassword(string password) {
		char temp;
		int alpha = 0, digit = 0;
		int len = (int)password.length();
		if (len < 8 || len>20) {
			cout << "Password must be with min size 8 and max size 20" << endl;
			return false;
		}
		for (int i = 0; i < len; i++) {
			temp = password[i];
			if (isalpha(temp)) alpha++;
			if (isdigit(temp)) digit++;
		}
		if (alpha <= 0 || digit <= 0)
		{
			cout << "The password must have an alphabetic letter and a digit." << endl;
			return false;
		}
		return true;
	}
public:
	static string enterName() {
		string name;
		system("cls");
		cout << "Enter name: ";
		cin >> name;
		while (!validateName(name)) {
			system("cls");
			cout << "Invalid name!\n";
			cout << "Name must be 5 to 20 alphabetic characters.\n" << endl;
			cout << "Enter name: ";
			cin >> name;
		}return name;
	}
	/*static string screenName() {
		string name;
		Person* person;
		do {
			cout << "Enter name:" << endl;
			while (name.length() == 0)getline(cin, name);
		} while (person->setName(name) == false);
		return name;
	}*/
	static string enterPassword() {
		string password;
		system("cls");
		cout << "Enter password: ";
		cin >> password;
		while (!validatePassword(password)) {
			system("cls");
			cout << "Invalid password!\n";
			cout << "Password must be with min size 8 and max size 20 and have an alphabetic letter and a digit." << endl;
			cout << "Enter password: ";
			cin >> password;
		}return password;
	}
	//static string screenPassword() {
	//	string password;
	//	Person p;
	//	do {
	//		cout << "Enter password:" << endl;
	//		cin >> password;
	//	} while (p.setPassword(password) == false);
	//	return password;
	//}
	static double enterBalance() {
		double balance;
		cout << "Enter balance: ";
		cin >> balance;
		while (balance < 1500) {
			system("cls");
			cout << "Invalid balance!\n";
			cout << "Balance must be at least 1500.\n" << endl;
			cout << "Enter balance: ";
			cin >> balance;
		}return balance;
	}
	static double enterSalary() {
		double salary;
		cout << "Enter salary: ";
		cin >> salary;
		while(salary < 5000) {
			system("cls");
			cout << "Invalid salary!\n";
			cout << "Salary must be at least 5000.\n" << endl;
			cout << "Enter salary: ";
			cin >> salary;
		}return salary;
	}

};

