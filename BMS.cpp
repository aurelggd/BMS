#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>

using namespace std;

class BankAccount{
    int accountNumber;
    char name[50];
    char type;
    int moneyDeposit;

public:
    void createAccount();
    void showAccount() const;
    // void modify();
    // void deposit(int);
    // void withdraw(int);
    // void report() const;
    // int retAccountNumber() const;
    // int retDeposit() const;
    // char retType() const;
};

void BankAccount::createAccount(){

    system("cls");
    cout << "Enter the account number : ";
    cin >> accountNumber;
    cout << "Enter the name of the account holder : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "Enter the type of account (C/S) : ";
    cin >> type;
    type = toupper(type);
    cout << "Enter the initial amount( >= 500 for saving and >= 1000 for current) :  ";
    cin >> moneyDeposit;
    cout << "Account created successfully !" << endl;

}

void BankAccount::showAccount() const{
    cout << "Account Number : " << accountNumber << endl;
    cout << "Account Holder Name : " << name << endl;
    cout << "Type of Account : " << type << endl;
    cout << "Balance amount : " << moneyDeposit << endl;
}