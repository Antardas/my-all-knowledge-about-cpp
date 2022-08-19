#include<bits/stdc++.h>

using namespace std;

class BankAccount {
public:
    string account_holder;
    string address;
    int age;
    int account_number;
protected:
    int balance;
private:
    string password;
public:
    BankAccount(string account_holder, string address, int age, string password) {
        this->account_holder = account_holder;
        this->account_number = rand() % 1000000000;
        this->address = address;
        this->age = age;
        this->balance = 0;
        this->password = password;
        cout << "Your Account Number is " << this->account_number << endl;
    }
    /**
     * @brief Get the Balance object
     *
     * @param password
     * @return int
     */
    int getBalance(string password) {
        if (password == this->password) {
            return this->balance;
        }
        else {
            return -1;
        }
    }
    void addMoney(string password, int balance) {
        if (password == this->password) {
            this->balance += balance;
            cout << "Added Money Successful" << this->balance << endl;
        }
        else {
            cout << "Password didn't match" << endl;
        }
    }
    /**
     * @brief Deposit Money
     *
     * @param password
     * @param balance
     */
    void depositMoney(string password, int balance) {
        if (password == this->password) {
            this->balance -= balance;
            cout << "Deposit Money Successful" << endl;
        }
        else {
            cout << "Password didn't match" << endl;
        }
    }

    friend class MyCash;



};


BankAccount* createAccount() {
    string account_holder, address, password;
    int age;
    cout << "Create Account" << endl;
    cin >> account_holder >> address >> age >> password;
    BankAccount* myAccount = new BankAccount(account_holder, address, age, password);
    return myAccount;
}

/**
 * @brief Add Money in your account
 *
 * @param myAccount
 */
void addMoney(BankAccount* myAccount) {
    string password;
    int amount;
    cout << "Add Money your Bank Account" << endl;
    cin >> password >> amount;
    myAccount->addMoney(password, amount);
}

void depositMoney(BankAccount* myAccount) {
    string password;
    int amount;
    cout << "Deposit Money" << endl;
    cin >> password >> amount;
    myAccount->depositMoney(password, amount);
}
// MYCash
class MyCash {
protected:
    int balance;

public:
    MyCash() {
        this->balance = 0;
    }
    void addMoneyFromBank(BankAccount* myAccount, string password, int amount) {
        if (myAccount->password == password) {
            this->balance += amount;
            myAccount->balance -= amount;
            cout << "Bank to Mycash money transfer successfully" << endl;
        }
        else {
            cout << "Password didn't Match" << endl;
        }
    }

};

void addMoneyBankToMycash(BankAccount* myAccount, MyCash myCashAccount) {
    string password;
    int amount;
    cout << "Bank to my cash add money" << endl;
    cin >> password >> amount;
    myCashAccount.addMoneyFromBank(myAccount, password, amount);
}


int main() {
    BankAccount* myAccount = createAccount();
    int myBalance = myAccount->getBalance("password");
    addMoney(myAccount);
    MyCash myCashAccount;

    addMoneyBankToMycash(myAccount, myCashAccount);

    cout << "Your Account balance is" << myBalance << endl;
    return 0;
}

/*
Antar
chittagong
19
2000
password
 */