#pragma once
#include "Admin.h"
class ClientManger
{
private:
	static void printClientMenu() {
		system("cls");
		cout << "(1) Display my info\n";
		cout << "(2) Update Password\n";
		cout << "(3) Deposit\n";
		cout << "(4) Withdraw \n";
		cout << "(5) TransferTo\n";
		cout << "(6) Check Balance\n";
		cout << "(7) Logout\n" << endl;
	}
	static void back(Client* client) {
		cout << endl;
		system("pause");
		clientOptions(client);
	}
public:
	 static void updatePassword(Person* person){
		person->setPassword(Validation::enterPassword());
		cout << "\nPassword updated.\n";
	 }
	 static Client* login(int id, string password){
		 for (clIt = allClients.begin();clIt != allClients.end();clIt++) {
			 if (clIt->getId() == id&& clIt->getPassword() == password)
				 return clIt._Ptr; 
		 }return NULL; 
	 }
	 static bool clientOptions(Client* client) {
		 printClientMenu();
		 cout << "\n\nYour choice is: ";
		 int choice, id;
		 double amount = 0;
		 Employee e;
			 cin >> choice;
			 switch (choice) {
			 case 1:
				 system("cls");
				 client->displayFunction();
				 break;
			 case 2:
				 system("cls");
				 updatePassword(client);
				 FileManager::updateClients();
				 break;
			 case 3:
				 system("cls");
				 cout << "Enter amount to deposit: ";
				 cin >> amount;
				 client->deposit(amount);
				 FileManager::updateClients();
				 break;
			 case 4:
				 system("cls");
				 cout << "Enter amount to  withdraw: ";
				 cin >> amount;
				 client->withdraw(amount);
				 FileManager::updateClients();
				 break;
			 case 5:
				 system("cls");
				 cout << "Enter id of the recipient: ";
				 cin >> id;
				 while (e.searchClient(id) == NULL) {
					 system("cls");
					 cout << "Invalid id.\n";
					 cout << "\nEnter id of the recipient: ";
					 cin >> id;
				 }
				 cout << "\nEnter amount to transfer: ";
				 cin >> amount;
				 client->transferTo(amount, *e.searchClient(id));
				 FileManager::updateClients();
				 break;
			 case 6:
				 system("cls");
				 client->checkBalance();
				 break;
			 case 7:
				 return false;
				 break;
			 default:
				 system("cls");
				 clientOptions(client);
				 return true;
			 }back(client);
			 return true;
	 }
};

