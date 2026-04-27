#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Transaction
{
public:
    string type;
    double amount;

    void setTransaction(string t, double amt)
    {
        type = t;
        amount = amt;
    }

    void display()
    {
        cout << left << setw(15) << type
            << " : $" << fixed << setprecision(2) << amount << endl;
    }
};

class Account
{
private:
    int accountNumber;
    double balance;
    Transaction* transactions;
    int transactionCount;
    int maxTransactions;

public:
    Account()
    {
        accountNumber = 0;
        balance = 0;
        transactionCount = 0;
        transactions = NULL;
        maxTransactions = 0;
    }

    void createAccount(int accNo, int maxT)
    {
        accountNumber = accNo;
        balance = 0;
        transactionCount = 0;
        maxTransactions = maxT;
        transactions = new Transaction[maxTransactions];
    }

    int getAccountNumber()
    {
        return accountNumber;
    }

    double getBalance()
    {
        return balance;
    }

    void addTransaction(string type, double amount)
    {
        if (transactionCount < maxTransactions)
        {
            transactions[transactionCount].setTransaction(type, amount);
            transactionCount++;
        }
        else
        {
            cout << "Error: Transaction limit reached." << endl;
        }
    }

    void deposit(double amount)
    {
        balance += amount;
        addTransaction("Deposit", amount);
        cout << "Amount deposited successfully." << endl;
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Error: Insufficient balance." << endl;
            return;
        }

        balance -= amount;
        addTransaction("Withdraw", amount);
        cout << "Amount withdrawn successfully." << endl;
    }

    void displayTransactions()
    {
        cout << "\n=========== Transactions ===========\n";

        for (int i = 0; i < transactionCount; i++)
        {
            transactions[i].display();
        }

        cout << "====================================\n";
    }

    void displayAccount()
    {
        cout << "\n=========== Account Info ===========\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Balance        : PKR" << fixed << setprecision(2) << balance << endl;
        cout << "====================================\n";
    }
};

class Customer
{
private:
    int customerId;
    string name;
    Account* accounts;
    int accountCount;
    int maxAccounts;

public:
    Customer()
    {
        customerId = 0;
        name = "";
        accountCount = 0;
        accounts = NULL;
        maxAccounts = 0;
    }

    void createCustomer(int id, string n, int maxAcc)
    {
        customerId = id;
        name = n;
        maxAccounts = maxAcc;
        accountCount = 0;
        accounts = new Account[maxAccounts];
    }

    void addAccount(int accNo, int maxTransactions)
    {
        if (accountCount < maxAccounts)
        {
            accounts[accountCount].createAccount(accNo, maxTransactions);
            accountCount++;
            cout << "Account created successfully." << endl;
        }
        else
        {
            cout << "Error: Account limit reached." << endl;
        }
    }

    Account* getAccount(int accNo)
    {
        for (int i = 0; i < accountCount; i++)
        {
            if (accounts[i].getAccountNumber() == accNo)
            {
                return &accounts[i];
            }
        }

        return NULL;
    }

    void displayCustomer()
    {
        cout << "\n====================================\n";
        cout << "         Customer Info\n";
        cout << "====================================\n";
        cout << "Customer ID : " << customerId << endl;
        cout << "Name        : " << name << endl;
        cout << "====================================\n";
    }
};

void transfer(Account* from, Account* to, double amount)
{
    cout << "\n=========== Transfer ===========\n";

    if (from->getBalance() < amount)
    {
        cout << "Error: Insufficient balance." << endl;
        return;
    }

    from->withdraw(amount);
    to->deposit(amount);

    cout << "Transfer successful." << endl;
    cout << "================================\n";
}

int main()
{
    int choice;

    cout << "====================================\n";
    cout << "     Banking Management System      \n";
    cout << "====================================\n";

    Customer* customers = new Customer[100];
    int customerCount = 0;

    do
    {
        cout << "\n1. Create Customer";
        cout << "\n2. Add Account";
        cout << "\n3. Deposit";
        cout << "\n4. Withdraw";
        cout << "\n5. Display Account";
        cout << "\n6. Display Transactions";
        cout << "\n7. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int id, maxAcc;
            string name;

            cout << "\nEnter Customer ID: ";
            cin >> id;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter max accounts: ";
            cin >> maxAcc;

            customers[0].createCustomer(id, name, maxAcc);
            customerCount++;

            cout << "Customer created successfully." << endl;
        }
        else if (choice == 2)
        {
            int accNo, maxTrans;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            cout << "Enter max transactions: ";
            cin >> maxTrans;

            customers[0].addAccount(accNo, maxTrans);
        }
        else if (choice == 3)
        {
            int accNo;
            double amount;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            Account* acc = customers[0].getAccount(accNo);

            if (acc != NULL)
            {
                cout << "Enter amount: ";
                cin >> amount;
                acc->deposit(amount);
            }
            else
            {
                cout << "Error: Account not found." << endl;
            }
        }
        else if (choice == 4)
        {
            int accNo;
            double amount;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            Account* acc = customers[0].getAccount(accNo);

            if (acc != NULL)
            {
                cout << "Enter amount: ";
                cin >> amount;
                acc->withdraw(amount);
            }
            else
            {
                cout << "Error: Account not found." << endl;
            }
        }
        else if (choice == 5)
        {
            int accNo;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            Account* acc = customers[0].getAccount(accNo);

            if (acc != NULL)
            {
                customers[0].displayCustomer();
                acc->displayAccount();
            }
            else
            {
                cout << "Error: Account not found." << endl;
            }
        }
        else if (choice == 6)
        {
            int accNo;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            Account* acc = customers[0].getAccount(accNo);

            if (acc != NULL)
            {
                acc->displayTransactions();
            }
            else
            {
                cout << "Error: Account not found." << endl;
            }
        }
        else if (choice == 7)
        {
            cout << "Exiting program! Thanks for using system." << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 7);

    system("pause");
    return 0;
}