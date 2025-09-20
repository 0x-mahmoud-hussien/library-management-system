#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ===================== User Class =====================
class User 
{
private:
    string name;
    string national_id;
    double balance;

public:
    User(string n, string id, double b) 
    {
        name = n;
        national_id = id;
        balance = b;
    }

    string getID() 
    {
        return national_id;
    }

    string getName() 
    {
        return name;
    }

    double getBalance() 
    {
        return balance;
    }

    void deposit(double amount) 
    {
        if (amount > 0) 
        {
            balance += amount;
            cout << "Deposit successful. Current balance: " << balance << "\n";
        } 
        else 
        {
            cout << "Amount must be greater than zero!\n";
        }
    }

    void withdraw(double amount) 
    {
        if (amount <= balance) 
        {
            balance -= amount;
            cout << "Withdrawal successful. Current balance: " << balance << "\n";
        } 
        else 
        {
            cout << "Insufficient balance!\n";
        }
    }

    void transfer(User &receiver, double amount) 
    {
        if (amount <= balance) 
        {
            balance -= amount;
            receiver.deposit(amount);
            cout << "Transferred to " << receiver.getName() << " successfully.\n";
        } 
        else 
        {
            cout << "Insufficient balance for transfer!\n";
        }
    }
};

// ===================== BankSystem Class =====================
class BankSystem 
{
private:
    vector<User> customers;

public:
    User* checkUser(string id) {
        for (int i = 0; i < customers.size(); i++) 
        {
            if (customers[i].getID() == id)
                return &customers[i];
        }
        return nullptr;
    }

    void createAccount(string name, string id, double initial_deposit) 
    {
        if (initial_deposit < 500) 
        {
            cout << "Initial deposit must be at least 500.\n";
            return;
        }
        User new_user(name, id, initial_deposit);
        customers.push_back(new_user);
        cout << "Account created successfully!\n";
    }

    void showAccountInfo(string id) 
    {
        User* user = checkUser(id);
        if (user != nullptr) {
            cout << "Name: " << user->getName() << "\n";
            cout << "Current balance: " << user->getBalance() << "\n";
        } else {
            cout << "User not found.\n";
        }
    }
};

// ===================== Main =====================
int main() 
{
    BankSystem bank;
    string id;

    cout << "Enter your national ID: ";
    cin >> id;

    User* currentUser = bank.checkUser(id);

    if (currentUser != nullptr) 
    {
        cout << "Welcome " << currentUser->getName() << "\n";
        bank.showAccountInfo(id);
    } 
    else 
    {
        cout << "User not found. Do you want to create a new account? (y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y') 
        {
            string name;
            double initial_deposit;
            cout << "Enter your name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter initial deposit (≥500): ";
            cin >> initial_deposit;
            bank.createAccount(name, id, initial_deposit);
            currentUser = bank.checkUser(id);
        } 
        else 
        {
            cout << "Thank you for using our bank.\n";
            return 0;
        }
    }

    // ===================== Operations =====================
    int option;
    do {
        cout << "\nSelect an operation:\n";
        cout << "1 - Deposit\n";
        cout << "2 - Withdraw\n";
        cout << "3 - Transfer\n";
        cout << "0 - Exit\n";
        cout << "Your choice: ";
        cin >> option;

        switch (option) 
        {
            case 1: 
            {
                double amount;
                cout << "Enter deposit amount: ";
                cin >> amount;
                currentUser->deposit(amount);
                break;
            }
            case 2: 
            {
                double amount;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                currentUser->withdraw(amount);
                break;
            }
            case 3: 
            {
                string receiver_id;
                double amount;
                cout << "Enter receiver national ID: ";
                cin >> receiver_id;
                User* receiver = bank.checkUser(receiver_id);
                if (receiver != nullptr) {
                    cout << "Enter transfer amount: ";
                    cin >> amount;
                    currentUser->transfer(*receiver, amount);
                } 
                else 
                {
                    cout << "Receiver not found.\n";
                }
                break;
            }
            case 0:
                cout << "Thank you for using our bank.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (option != 0);

    return 0;
}