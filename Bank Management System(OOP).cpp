#include <iostream>
#include <vector>
using namespace std;

class Customer {
public:
    int customerID;
    string name, email, phone;

    Customer(int id, string n, string e, string p) {
        customerID = id;
        name = n;
        email = e;
        phone = p;
    }

    void displayCustomer() const {
        cout << "Customer ID: " << customerID << " | Name: " << name << " | Email: " << email << " | Phone: " << phone << endl;
    }
};

class Account {
public:
    int accountID;
    int customerID;
    string accountType;
    double balance;

    Account(int accID, int custID, string type, double bal) {
        accountID = accID;
        customerID = custID;
        accountType = type;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful! New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful! New Balance: " << balance << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void displayAccount() const {
        cout << "Account ID: " << accountID << " | Customer ID: " << customerID << " | Type: " << accountType << " | Balance: " << balance << endl;
    }
};

class BankManagementSystem {
private:
    vector<Customer> customers;
    vector<Account> accounts;
    int customerCounter = 1;
    int accountCounter = 1;

public:
    void addCustomer(string name, string email, string phone) {
        customers.emplace_back(customerCounter, name, email, phone);
        cout << "Customer added with ID: " << customerCounter << endl;
        customerCounter++;
    }

    void createAccount(int customerID, string accountType, double balance) {
        accounts.emplace_back(accountCounter, customerID, accountType, balance);
        cout << "Account created with ID: " << accountCounter << endl;
        accountCounter++;
    }

    void deposit(int accountID, double amount) {
        for (auto &acc : accounts) {
            if (acc.accountID == accountID) {
                acc.deposit(amount);
                return;
            }
        }
        cout << "Account not found!" << endl;
    }

    void withdraw(int accountID, double amount) {
        for (auto &acc : accounts) {
            if (acc.accountID == accountID) {
                acc.withdraw(amount);
                return;
            }
        }
        cout << "Account not found!" << endl;
    }

    void displayCustomers() const {
        for (const auto &cust : customers) {
            cust.displayCustomer();
        }
    }

    void displayAccounts() const {
        for (const auto &acc : accounts) {
            acc.displayAccount();
        }
    }
};

int main() {
    BankManagementSystem bank;
    int choice;

    while (true) {
        cout << "\nBank Management System" << endl;
        cout << "1. Add Customer" << endl;
        cout << "2. Create Account" << endl;
        cout << "3. Deposit Money" << endl;
        cout << "4. Withdraw Money" << endl;
        cout << "5. View Customers" << endl;
        cout << "6. View Accounts" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name, email, phone;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Email: ";
            cin >> email;
            cout << "Enter Phone: ";
            cin >> phone;
            bank.addCustomer(name, email, phone);
        } else if (choice == 2) {
            int custID;
            string type;
            double balance;
            cout << "Enter Customer ID: ";
            cin >> custID;
            cout << "Enter Account Type (Saving/Current): ";
            cin >> type;
            cout << "Enter Initial Balance: ";
            cin >> balance;
            bank.createAccount(custID, type, balance);
        } else if (choice == 3) {
            int accID;
            double amount;
            cout << "Enter Account ID: ";
            cin >> accID;
            cout << "Enter Amount: ";
            cin >> amount;
            bank.deposit(accID, amount);
        } else if (choice == 4) {
            int accID;
            double amount;
            cout << "Enter Account ID: ";
            cin >> accID;
            cout << "Enter Amount: ";
            cin >> amount;
            bank.withdraw(accID, amount);
        } else if (choice == 5) {
            bank.displayCustomers();
        } else if (choice == 6) {
            bank.displayAccounts();
        } else if (choice == 7) {
            break;
        } else {
            cout << "Invalid choice! Try again." << endl;
        }
    }
    return 0;
}

