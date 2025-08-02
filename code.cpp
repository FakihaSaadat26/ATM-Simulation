#include <iostream>
using namespace std;

// ATM Class to encapsulate logic
class ATM {
private:
    double balance;

public:
    ATM(double initialBalance = 0.0) {
        balance = initialBalance;
    }

    void checkBalance() const {
        cout << "💰 Current Balance: Rs. " << balance << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "✅ Rs. " << amount << " deposited successfully.\n";
        } else {
            cout << "❌ Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "❌ Withdrawal amount must be positive.\n";
        } else if (amount > balance) {
            cout << "❌ Insufficient balance.\n";
        } else {
            balance -= amount;
            cout << "💸 Rs. " << amount << " withdrawn successfully.\n";
        }
    }
};

// Controller Class to handle user interaction
class ATMController {
public:
    void start() {
        ATM atm(5000); // starting balance

        int choice;
        double amount;

        do {
            cout << "\n====== ATM Menu ======\n";
            cout << "1. Check Balance\n";
            cout << "2. Deposit Money\n";
            cout << "3. Withdraw Money\n";
            cout << "4. Exit\n";
            cout << "Choose an option: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    atm.checkBalance();
                    break;
                case 2:
                    cout << "Enter amount to deposit: Rs. ";
                    cin >> amount;
                    atm.deposit(amount);
                    break;
                case 3:
                    cout << "Enter amount to withdraw: Rs. ";
                    cin >> amount;
                    atm.withdraw(amount);
                    break;
                case 4:
                    cout << "👋 Thank you for using the ATM.\n";
                    break;
                default:
                    cout << "❌ Invalid option. Please try again.\n";
            }
        } while (choice != 4);
    }
};

// Main Function
int main() {
    ATMController controller;
    controller.start();
    return 0;
}
