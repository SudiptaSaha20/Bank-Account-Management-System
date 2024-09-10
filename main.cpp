#include <iostream>
#include <string>
using namespace std;

class Account
{
private:
    string fullName;
    long long int accNum;
    float balance;

public:
    void createAccount(); // Makes an account based on user input
    void display();       // display account details
    void deposit();       // deposit money into account
    void withdraw();      // withdraw money from account
    void checkBalance(); // check account balance
    // ~Account();
};

void Account::createAccount()
{
    cout << "Enter user full name: ";
    cin >> fullName;
    cout << "Enter account number: ";
    cin >> accNum;
    cout << "Enter starting balance: ";
    cin >> balance;
}

void Account::deposit()
{
    float deposit;
    cout << "Enter amount to deposit: ";
    cin >> deposit;
    balance += deposit;
}

void Account::withdraw()
{
    float withdraw;
    cout << "Enter amount to withdraw: ";
    cin >> withdraw;
    balance += withdraw;
}

void Account::checkBalance()
{
    cout << balance << endl;
}

void Account::display()
{
    cout << "\nFull Name: " << fullName << endl;
    cout << "Account Number: " << accNum << endl;
    cout << "Balance: Rs. " << balance << endl;
}

int main()
{
    Account account;
    int choice;
    cout << "\033c";
    while(1){
        cout << "\nOperations: " << endl;
        cout << "1. Create a new account\n2.Deposit money\n3.Withdraw money\n4.Check balance\n5.View account details\n6.Exit" << endl;
        cout << "Enter your chocie: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            account.createAccount();
            break;
        case 2:
            account.deposit();
            break;
        case 3:
            account.withdraw();
            break;
        case 4:
            account.checkBalance();
            break;
        case 5:
            account.display();
            break;
        case 6:
            exit(0);
            break;

        default:
            break;
        }
    }
    return 0;
}