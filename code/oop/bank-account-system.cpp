// Bank Account - Encapsulation Exercise
// Demonstrates encapsulation using private member variables and public methods
// to control access to account data and validate deposits and withdrawals.

#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
public:
    BankAccount(string accountHolder, int accountNumber, double balance = 0)
    {
        mAccountHolder = accountHolder;
        mAccountNumber = accountNumber;

        if (balance < 0)
        {
            mBalance = 0;
        }
        else
        {
            mBalance = balance;
        }
    }

    double deposit(double amount)
    {
        if (amount > 0)
        {
            mBalance += amount;
            cout << "Deposit successful." << endl;
        }
        else
        {
            cout << "Amount must be greater than 0" << endl;
        }

        return mBalance;
    }

    double withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Withdrawal must be greater than 0" << endl;
        }
        else if (amount > mBalance)
        {
            cout << "Insufficient funds." << endl;
        }
        else
        {
            mBalance -= amount;
            cout << "Withdrawal successful." << endl;
        }

        return mBalance;
    }

    double getBalance()
    {
        return mBalance;
    }

    string getAccountHolder()
    {
        return mAccountHolder;
    }

    void displayAccount()
    {
        cout << "===== BANK ACCOUNT =====\n"
             << endl;

        cout << "Account Holder: " << getAccountHolder() << endl;
        cout << "Account Number: " << mAccountNumber << endl;
        cout << "Current Balance: $" << getBalance() << endl;

        cout << endl;
    }

private:
    string mAccountHolder;
    int mAccountNumber;
    double mBalance;
};

int main()
{
    BankAccount account1("Cailee Averill", 11111, 1000);

    account1.displayAccount();

    account1.deposit(500);
    cout << "Current Balance: $" << account1.getBalance() << endl;

    account1.withdraw(200);
    cout << "Current Balance: $" << account1.getBalance() << endl;

    account1.withdraw(2000);
    cout << "Current Balance: $" << account1.getBalance() << endl;
}