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

    cout << "                                                                 \tEnter the account number : ";
    cin >> accountNumber;
    cout << "                                                                 \tEnter the name of the account holder : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "                                                                 \tEnter the type of account (C/S) : ";
    cin >> type;
    type = toupper(type);
    cout << "                                                                 \tEnter the initial amount( >= 500 for saving and >= 1000 for current) : ";
    cin >> moneyDeposit;
    cout << "                                                                    \tAccount created successfully !" << endl;
    cout << endl;

    cout << "\t -----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    cout << endl;

}

void BankAccount::showAccount() const{
    cout << "                                                                \t Account Number : " << accountNumber << endl;
    cout << "                                                                \t Account Holder Name : " << name << endl;
    cout << "                                                                \t Type of Account : " << type << endl;
    cout << "                                                                \t Balance amount : " << moneyDeposit << endl;
}

int main(){

    char ch;
    int num;


    system("cls");

    cout << "###################################################################################################################################################################" << endl;
    
    cout << "#                                                               Welcome to the Bank Management System                                                             #" << endl;
    
    cout << "###################################################################################################################################################################" << endl;
    
    cout << endl;

    cout << "\t ----------------------------------------------------------------------Main Menu----------------------------------------------------------------------" << endl;
    cout << endl;

    cout << "                                                                \t 1. Create a new account                                                                   " << endl;
    cout << "                                                                \t 2. Deposit money                                                                " << endl;
    cout << "                                                                \t 3. Withdraw money                                                                " << endl;
    cout << "                                                                \t 4. Balance enquiry                                                                " << endl;
    cout << "                                                                \t 5. All account holder list                                                                " << endl;
    cout << "                                                                \t 6. Close an account                                                                " << endl;
    cout << "                                                                \t 7. Modify an account                                                                " << endl;
    cout << "                                                                \t 8. Exit                                                                " << endl;
    cout << endl;

    cout << "\t -----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;

    BankAccount zen;
    zen.createAccount();
    zen.showAccount();

    return 0;
}