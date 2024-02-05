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
    int retAccountNumber() const;
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

int BankAccount::retAccountNumber() const {
    return accountNumber;
}


void writeAccount();
void displayDetails(int);
void deleteAccount();
    

int main(){

    char ch;
    int num;

    do{
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
    cout << "                                                                \t Enter your choice beetween 1-8 : " << endl;
    cin >> ch;
    cout << endl;

    switch(ch){
        case '1':
            writeAccount();
            break;
        case '2':
            // deposit();
            system("cls");
            cout << "                                                                 \tEnter the account number : ";
            cin >> num;
            break;
        case '3':
            // withdraw();
            system("cls");
            cout << "                                                                 \tEnter the account number : ";
            cin >> num;
            break;
        case '4':
            // report();
            system("cls");
            cout << "                                                                 \tEnter the account number : ";
            cin >> num;
            displayDetails(num);
            break;
        case '5':
            // showAll();
            system("cls");
            break;
        case '6':
            // closeAccount();
            system("cls");
            cout << "                                                                 \tEnter the account number : ";
            cin >> num;
            deleteAccount();
            break;
        case '7':
            // modifyAccount();
            system("cls");
            cout << "                                                                 \tEnter the account number : ";
            cin >> num;
            break;
        case '8':
            // exit();
            cout << "                                                                 \tThank you for using the Bank Management System !";
            break;
        default:
            cout << "Invalid choice !" << endl;
    }
    cin.ignore();
    cin.get();

    cout << "\t -----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    }while(ch != '8');

    return 0;
}

void writeAccount(){
    BankAccount bankAccount;
    ofstream outFile;
    outFile.open("account.dat", ios::binary | ios::app);
    bankAccount.createAccount();
    outFile.write(reinterpret_cast<char *> (&bankAccount), sizeof(BankAccount));
    outFile.close();
}

void deleteAccount(){
    BankAccount bankAccount;
    ifstream inFile;
    ofstream outFile;
    int accountNumber;
    cout << "Enter the account number you want to delete : ";
    cin >> accountNumber;
    inFile.open("account.dat", ios::binary);
    if(!inFile){
        cout << "File could not be opened. Press any key to continue...";
        return;
    }
    outFile.open("Temp.dat", ios::binary);
    inFile.seekg(0, ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&bankAccount), sizeof(BankAccount))){
        if(bankAccount.retAccountNumber() != accountNumber){
            outFile.write(reinterpret_cast<char *> (&bankAccount), sizeof(BankAccount));
        }
    }
    inFile.close();
    outFile.close();
    remove("account.dat");
    rename("Temp.dat", "account.dat");
    cout << "Account deleted successfully !" << endl;
}

void displayDetails(int n){
    BankAccount bankAccount;
    bool flag = false;
    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if(!inFile){
        cout << "File could not be opened. Press any key to continue...";
        return;
    }
    cout << "Balance Details" << endl;
    while(inFile.read(reinterpret_cast<char *> (&bankAccount), sizeof(BankAccount))){
        if(bankAccount.retAccountNumber() == n){
            bankAccount.showAccount();
            flag = true;
        }
    }
    inFile.close();
    if(flag == false){
        cout << "Account number does not exist !" << endl;
    }
}