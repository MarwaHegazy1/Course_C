#pragma once
#include <fstream>
#include"DataSourceInterface.h"
#include"FileHelper.h"

using namespace std;

 class FileManager :public DataSourceInterface
{
private:
    static void addClient(Client client) {
            FileHelper::saveClient(client);
    }
    static void addEmployee(Employee employee) {
        FileHelper::saveEmployee("Employees.txt","EmployeeLastId.txt",employee);
    }

    static void getAllClients() {
        FileHelper::getClients();
    }
    static void getAllEmployees() {
        FileHelper::getEmployees();
    }
    static void getAllAdmins() {
        FileHelper::getAdmins();
    }

   /* static void removeAllClient() {
        remove("Clients.txt");
        cout << "\nAll clients deleted\n";
    }
    static void removeAllEmployee() {
        remove("Employees.txt");
        cout << "\nAll employee deleted\n";
    }
    static void removeAllAdmin() {
        remove("Admins.txt");
        cout << "\nAll admin deleted\n";
    }*/

    static void removeAllClient() {
        FileHelper::clearFile("Clients.txt", "ClientLastId.txt");
        cout << "\nAll clients deleted\n";
    }
    static void removeAllEmployee() {
        FileHelper::clearFile("Employees.txt", "EmployeeLastId.txt");
        cout << "\nAll employee deleted\n";
    }
    static void removeAllAdmin() {
        FileHelper::clearFile("Admins.txt", "AdminLastId.txt");
        cout << "\nAll admin deleted\n";
    }
     
public:
    static void addAdmin(Admin admin) {
        FileHelper::saveEmployee("Admins.txt", "AdminLastId.txt", admin);
    }

    static void getAllData() {
        getAllClients();
        getAllEmployees();
        getAllAdmins();
    }

    static void updateClients() {
        removeAllClient();
        for (clIt = allClients.begin();clIt != allClients.end();clIt++)
            addClient(*clIt);
    }
    static void updateEmployees() {
        removeAllEmployee();
        for (eIt = allEmployees.begin();eIt != allEmployees.end();eIt++)
            addEmployee(*eIt);
    }
    static void updateAdmins() {
        removeAllAdmin();
        for (aIt = allAdmins.begin(); aIt != allAdmins.end(); aIt++)
            addAdmin(*aIt);
    }
};
