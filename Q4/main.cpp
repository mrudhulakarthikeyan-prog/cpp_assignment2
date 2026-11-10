#include <iostream>
#include <string>
using namespace std;

class SavingsAccount {
private:
    string accountNumber;
    double balance;
    double transactions[10];
    int count;

    void record(double amount) {
        if (count < 10) {
            transactions[count++] = amount;
        } else {
            // Shift left: discard the oldest transaction.
            for (int i = 1; i < 10; ++i) transactions[i - 1] = transactions[i];
            transactions[9] = amount;
        }
    }

public:
    SavingsAccount(const string& number, double openingBalance)
        : accountNumber(number), balance(openingBalance), transactions{}, count(0) {}

    void deposit(double amount);   // Defined outside the class.
    bool withdraw(double amount);  // Defined outside the class.
    void miniStatement() const;    // Defined outside the class.
};

void SavingsAccount::deposit(double amount) {
    if (amount <= 0) {
        cout << "Deposit must be positive.\n";
        return;
    }
    balance += amount;
    record(amount);
}

bool SavingsAccount::withdraw(double amount) {
    if (amount <= 0 || amount > balance) {
        cout << "Withdrawal rejected: invalid amount or insufficient balance.\n";
        return false;
    }
    balance -= amount;
    record(-amount);
    return true;
}

void SavingsAccount::miniStatement() const {
    cout << "Account: " << accountNumber << "\nBalance: " << balance
         << "\nRecent transactions (oldest to newest):\n";
    for (int i = 0; i < count; ++i) {
        cout << (transactions[i] >= 0 ? "Credit: " : "Debit: ")
             << (transactions[i] >= 0 ? transactions[i] : -transactions[i]) << '\n';
    }
}

int main() {
    SavingsAccount account("SA1024", 5000.0);
    account.deposit(500);
    account.withdraw(250);
    account.deposit(1000);
    account.withdraw(300);
    account.deposit(750);
    account.withdraw(100);
    account.deposit(200);
    account.withdraw(50);
    account.deposit(900);
    account.withdraw(400);
    account.deposit(650); // 11th transaction: oldest is discarded.
    account.miniStatement();
    return 0;
}
