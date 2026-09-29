#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;
    
    // Static variable to keep track of total accounts
    static int totalAccounts; 

public:
    // Constructor to initialize object and increment static count
    BankAccount(string name, double bal) {
        accountHolder = name;
        balance = bal;
        totalAccounts++; // Jab bhi naya object banay ga, count +1 ho jaye ga
    }

    // Static function to display the total accounts count
    static int getTotalAccounts() {
        return totalAccounts;
    }

    // Normal function to display individual account details
    void displayInfo() {
        cout << "Account Holder: " << accountHolder << " | Balance: Rs. " << balance << endl;
    }
};

// Initializing the static variable outside the class (Must requirement in C++)
int BankAccount::totalAccounts = 0;

int main() {
    // 1. Creating multiple objects (3 different accounts)
    BankAccount acc1("Ali", 25000.0);
    BankAccount acc2("Ayesha", 50000.5);
    BankAccount acc3("Zain", 12000.0);

    // Displaying individual account details
    acc1.displayInfo();
    acc2.displayInfo();
    acc3.displayInfo();

    cout << "---------------------------------------------" << endl;

    // 2. Displaying total accounts created using static function
    cout << "Total Bank Accounts Created: " << BankAccount::getTotalAccounts() << endl;

    return 0;
}
