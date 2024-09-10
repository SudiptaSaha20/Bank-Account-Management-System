#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cctype>
#include <algorithm>

using namespace std;

class Account
{
private:
    string firstName;
    string lastName;
    string houseNum;
    string street;
    string townCity;
    string district;
    string pinNum;
    string state;
    string country;
    string accType;
    long long int accNum;
    float balance;

public:
    void createAccount();
    void display();
    void deposit();
    void withdraw();
    void checkBalance();
};

int main()
{
    Account account;
    int choice;
    cout << "\033c" << "--------------BANK MANAGEMENT SYSTEM--------------";
    while (1)
    {
        cout << "\nOperations: " << endl;
        cout << "1. Create a new account\n2. Deposit money\n3. Withdraw money\n4. Check balance\n5. View account details\n6. Exit" << endl;
        cout << "Enter your choice: ";
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

void Account::createAccount()
{
    cout << "\nEnter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;
    cout << "Enter house number: ";
    cin >> houseNum;
    cout << "Enter street/area: ";
    cin >> street;
    cout << "Enter town/city: ";
    cin >> townCity;
    cout << "Enter district/province: ";
    cin >> district;
    cout << "Enter PIN code: ";
    cin >> pinNum;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter state: ";
    getline(cin, state);
    cout << "Enter country: ";
    cin >> country;
    cout << "Enter account type(savings/current): ";
    while (true)
    {
        cin >> accType;

        transform(accType.begin(), accType.end(), accType.begin(), ::tolower);
        if (accType != "savings" && accType != "current")
        {
            cout << "Account type can be only savings/current. Try again: ";
        }
        else
        {
            break;
        }
    }
    cout << "Enter account number: ";
    while (true)
    {
        cin >> accNum;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid account number: ";
        }
        else
        {
            break;
        }
    }
    cout << "Enter starting balance: ";
    while (true)
    {
        cin >> balance;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid starting balance: ";
        }
        else if (balance < 500)
        {
            cout << "You need to put a minimum amount of Rs. 500 as starting balance: ";
        }
        else
        {
            break;
        }
    }
    cout << "Account Created Successfully!"<<endl;
}

void Account::deposit()
{
    float deposit;
    cout << "\nEnter amount to deposit: ";
    while (true)
    {
        cin >> deposit;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid deposit amount: ";
        }
        else
        {
            break;
        }
    }
    cout << fixed << setprecision(2);
    cout << "Successfully deposited Rs. " << deposit << " into your account."<<endl;
    balance += deposit;
}

void Account::withdraw()
{
    float withdraw;
    cout << "\nEnter amount to withdraw: ";
    while (true)
    {
        cin >> withdraw;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid floating-point number: ";
        }
        else if (withdraw > balance || withdraw == balance)
        {
            cout << "Cannot withdraw an amount more than/equal to the account balance! Please try again: ";
        }
        else
        {
            break;
        }
    }
    cout << fixed << setprecision(2);
    cout << "Rs. " << withdraw << " successfully withdrawn from your account."<<endl;
    balance -= withdraw;
}

void Account::checkBalance()
{
    cout << fixed << setprecision(2);
    cout << "\nCurrently you have Rs." << balance << " in your bank account." << endl;
}

void Account::display()
{
    cout << "\nAccount Holder: " << firstName + " " + lastName << endl;
    cout << "House Adress: " << houseNum + ", " + street + ", " + townCity + ", " + district + ", " + pinNum + ", " + state + ", " + country << endl;
    cout << "Account Type: " << accType << endl;
    cout << "Account Number: " << accNum << endl;
    cout << fixed << setprecision(2);
    cout << "Balance: Rs. " << balance << endl;
}
