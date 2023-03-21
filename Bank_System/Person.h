#pragma once
#include <iostream>
#include<string>
#include"Validation.h"
#include<vector>

using namespace std;
class Person {
private:
	int id;
	string name;
	string password;
public:

	Person() {
		this->id = 0;
		this->name = "";
		this->password = "";
	}
	Person(int id, string name, string password) {
		setId(id);
		setName(name);
		setPassword(password);
	}
	void setId(int id) {
		this->id = id;
	}
	void setName(string name) {
		this->name = name;
	}
	void setPassword(string password) {
		this->password = password;
	}
	int getId() {
		return id;
	}
	string getName() {
		return name;
	}
	string getPassword() {
		return password;
	}
	void displayFunction() {
		cout << "Name: " << getName() << endl;
		cout << "ID: " << getId() << endl;
		cout << "Password: " << getPassword() << endl;
	}

};


