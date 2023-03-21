#pragma once
#include"Parser.h"

using namespace std;
 class FileHelper
{
private:
    static void saveLast(string fileName, int id) {
        fstream lastFile;
        lastFile.open(fileName, ios::out);
        if (!lastFile) cout << "Error in open the file..!!\n";
        else {
            lastFile << id;
            lastFile.close();
        } 
    }
public:
    static int getLast(string fileName) {
        fstream file;
        file.open(fileName, ios::in);
        int id;
        file >> id;
        file.close();
        return id;
    }
   
    static void saveClient(Client client){
        int id = getLast("ClientLastId.txt");
        fstream file;
        file.open("Clients.txt", ios::app);
        file << id + 1 << ',' << client.getName() << ',' << client.getPassword() << ',' << client.getBalance()<<"\n";
        file.close();
        saveLast("ClientLastId.txt", id + 1);
    
    }
    static void saveEmployee(string fileName, string lastIdFile, Employee employee) {
        int id = getLast(lastIdFile);
        fstream file;
        file.open(fileName, ios::app);
        file << id + 1 << ',' << employee.getName() << ',' << employee.getPassword() << ',' << employee.getSalary() << "\n";
        file.close();
        saveLast(lastIdFile, id + 1);

    } 
   
    static void getClients(){
        string line;
        ifstream file;
        file.open("Clients.txt");
        while (getline(file, line)) {
            Client client = Parser::parseToClient(line);
            allClients.push_back(client);
        }file.close();
    }
    static void getEmployees(){
        string line;
        ifstream file;
        file.open("Employees.txt");
        while (getline(file, line)) {
            Employee employee = Parser::parseToEmployee(line);
            allEmployees.push_back(employee);
        }file.close();
    }
    static void getAdmins(){
        string line;
        ifstream file;
        file.open("Admins.text");
        while (getline(file, line)) {
            Admin admin = Parser::parseToAdmin(line);
            allAdmins.push_back(admin);
        }file.close();
    }

    static void clearFile(string fileName, string lastIdFile) {
        fstream file1, file2;
        file1.open(fileName, ios::out, ios::trunc);
        file1.close();
        file2.open(lastIdFile, ios::out);
        file2 << 0;
        file2.close();
        
    }
};
       
 