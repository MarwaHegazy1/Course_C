#pragma once
#include<sstream>
#include"Admin.h"
using namespace std;

 class Parser
{
public:
	static vector<string> split(string line)
	{
		vector<string> ret;
		stringstream str(line);//to divide(parse )
		while (str.good()) { //if there a line 
			string substr;                    
			       //cut line  //put in string the push_back in vector       
								//find
			getline(str, substr, ',');
			ret.push_back(substr);
		}
		return ret;
	}
	static Client parseToClient(string line)
	{
		Client client;
		vector<string> ret = split(line);
		client.setId(stoi(ret[0]));
		client.setName(ret[1]);
		client.setPassword(ret[2]);
		client.setBalance(stod(ret[3]));
		return client;
	}
	static Employee parseToEmployee(string line)
	{
		Employee employee;
		vector<string> ret = split(line);
		employee.setId(stoi(ret[0]));
		employee.setName(ret[1]);
		employee.setPassword(ret[2]);
		employee.setSalary(stod(ret[3]));
		return employee;
	}
	static Admin parseToAdmin(string line)
	{
		Admin admin;
		vector<string> ret = split(line);
		admin.setId(stoi(ret[0]));
		admin.setName(ret[1]);
		admin.setPassword(ret[2]);
		admin.setSalary(stod(ret[3]));
		return admin;
	}

};



