#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Account {
protected:
    string customerName; 
    int accountNumber;   
    char accountType;
    float balance;        

public:
    
    Account(const string &name, int accNumber, char accType, float initialBalance)
        : customerName(name), accountNumber(accNumber), accountType(accType), balance(initialBalance) {}

    void deposit(float amount) {
        balance += amount;
        cout << "Deposit Amount " << amount <<" is Successful. Updated balance: " << balance << endl;
    }

    void displayBalance() const {
        cout << "Account Number: " << accountNumber << "\nBalance: " << balance << endl;
    }

    virtual void withdraw(float amount) = 0;

    virtual void checkMinimumBalance() = 0;
};

class SavingsAccount : public Account {
private:
    float interestRate;

public:
    SavingsAccount(const string &name, int accNumber, float initialBalance, float interest)
        : Account(name, accNumber, 'S', initialBalance), interestRate(interest) {}

    void calculateInterest() {
        float compoundInterest = balance * pow((1 + interestRate / 100), 1); 
        balance = compoundInterest;
    }

    void withdraw(float amount) override {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal amount : " << amount <<" successful. Updated balance: " << balance << endl;
        } else {
            cout << "Insufficient funds for withdrawal." << endl;
        }
    }

    void checkMinimumBalance() override {

    }
};

class CurrentAccount : public Account {
private:
    float minimumBalance;  
    float serviceCharge; 

public:

    CurrentAccount(const string& name, int accNumber, float initialBalance, float minBalance, float charge)
        : Account(name, accNumber, 'C', initialBalance), minimumBalance(minBalance), serviceCharge(charge) {}

    void withdraw(float amount) override {
        if (amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawal amount " << amount <<" successful. Updated balance: " << balance << endl;
        } else {
            cout << "Insufficient funds for withdrawal." << endl;
        }
    }

    void checkMinimumBalance() override {
        if (balance < minimumBalance) {
            balance -= serviceCharge;
            cout << "Minimum balance not maintained. Service charge :" << serviceCharge <<"  imposed. Updated balance: " << balance << endl;
        }
    }
};

int main() {
    // Create a SavingsAccount and a CurrentAccount
    SavingsAccount savings("Md Afsarul Hoque", 1038, 5000.0, 5.0); // 5% annual interest
    CurrentAccount current("Alfaj Hok", 13045, 10000.0, 2000.0, 5.0);

    // Deposit and display balance for both accounts
    savings.deposit(2000.0);
    savings.displayBalance();

    current.deposit(3000.0);
    current.displayBalance();

    // Withdraw and display balance for both accounts
    savings.withdraw(1000.0);
    savings.displayBalance();
    // Insufficient funds for withdrawal
    current.withdraw(12000.0); 
    current.displayBalance();

    // Check minimum balance and impose penalty if necessary
    savings.checkMinimumBalance();
    savings.displayBalance();

    current.checkMinimumBalance();
    current.displayBalance();

    // Calculate interest for the savings account and update the balance
    savings.calculateInterest();
    savings.displayBalance();

    return 0;
}
