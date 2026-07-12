#include <iostream>
#include <stdlib.h>
using namespace std;
struct Bank
{
    int accountno;
    string name;
    float balance;
    bool accountCreated = false;
} account;
void createAccount()
{
    if (account.accountCreated)
    {
        cout << "Account already exists!" << endl;
        return;
    }
    cout << "Enter Account Number : ";
    cin >> account.accountno;
    cout << "Enter Account Holder Name : ";
    cin >> account.name;
    cout << "Enter Initial Balance : ";
    cin >> account.balance;
    cout << "\nAccount Created Successfully!\n";
    account.accountCreated = true;
    cout << "\nAccount Number : " << account.accountno;
    cout << "\nName           : " << account.name;
    cout << "\nBalance        : " << account.balance;
}
void depositMoney()
{
    if (!account.accountCreated)
    {
        cout << "Please Create Account First!" << endl;
        return;
    }
    int accountNo;
    float amount;
    cout << "Enter Account Number : ";
    cin >> accountNo;

    while (true)
    {
        cout << "Enter Deposit Amount : ";
        cin >> amount;

        if (amount > 0)
        {
            break;
        }

        cout << "Wrong Amount! Please enter a positive amount.\n";
    }
    if (accountNo == account.accountno)
    {
        account.balance += amount;
        cout << "Money Deposited Successfully!" << endl;
        cout << "Current Balance : " << account.balance;
    }
    else
    {
        cout << "Account Not Found!" << endl;
    }
}
void withdrawMoney()
{
    if (!account.accountCreated)
    {
        cout << "Please Create Account First!" << endl;
        return;
    }
    int accountNo;
    float amount;
    cout << "Enter Account Number : ";
    cin >> accountNo;
    while (true)
    {
        cout << "Enter Withdraw Amount : ";
        cin >> amount;

        if (amount > 0)
        {
            break;
        }

        cout << "Wrong Amount! Please enter a positive amount.\n";
    }
    if (accountNo == account.accountno)
    {
        if (account.balance >= amount)
        {
            account.balance -= amount;
            cout << "\nMoney Withdraw Successfully!" << endl;
            cout << "Current Balance : " << account.balance;
        }
        else
        {
            cout << "Insufficient Balance!" << endl;
            cout << "Current Balance : " << account.balance;
        }
    }
    else
    {
        cout << "Account Not Found!" << endl;
    }
}

void checkBalance()
{
    if (!account.accountCreated)
    {
        cout << "Please Create Account First!" << endl;
        return;
    }
    int accountNo;
    cout << "Enter Account Number : ";
    cin >> accountNo;
    if (accountNo == account.accountno)
    {
        cout << "\n==================================\n";
        cout << "           ACCOUNT DETAILS            ";
        cout << "\n===================================\n";
        cout << "\nAccount Number : " << account.accountno;
        cout << "\nName           : " << account.name;
        cout << "\nBalance        : " << account.balance;
    }
    else
    {
        cout << "Account Not Found!" << endl;
    }
}
void deleteAccount()
{
    if (!account.accountCreated)
    {
        cout << "Please Create Account First!" << endl;
        return;
    }
    int accountNo;
    cout << "Enter Account Number :";
    cin >> accountNo;
    if (accountNo == account.accountno)
    {
        char ch;
        while (true)
        {
            cout << "Are You Sure You Want To Delete Account? (Y/N): ";
            cin >> ch;
            if (ch == 'Y' || ch == 'y')
            {
                account.accountCreated = false;
                account.accountno = 0;
                account.name = "";
                account.balance = 0;
                cout << "Account Deleted Successfully!";
                break;
            }
            else if (ch == 'n' || ch == 'N')
            {
                cout << "Account Deletion Cancelled!";
                break;
            }
            else
            {
                cout << "Invalid Choice!";
                continue;
            }
        }
    }
    else
    {
        cout << "Account Not Found!";
        return;
    }
}

void updateAccount()
{
    if (!account.accountCreated)
    {
        cout << "Please Create Account First!" << endl;
        return;
    }
    int accountNo;
    cout << "Enter Account Number : ";
    cin >> accountNo;
    if (accountNo == account.accountno)
    {
        cout << "\n==================================\n";
        cout << "           UPDATE ACCOUNT             ";
        cout << "\n===================================\n";

        int choice;
        cout << "1. Update Name\n2. Update Account Number\n3. Cancel\n";
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            char ch;
            string name;
            cout << "Enter New Name : ";
            cin >> name;
            cout << "Are You Sure? (Y/N): ";
            cin >> ch;
            if (ch == 'Y' || ch == 'y')
            {
                account.name = name;
                cout << "Name Updated Successfully!";
            }
            else
            {
                cout << "Update Cancelled!";
            }

            break;
        }

        case 2:
        {
            char ch;
            int accountno;
            cout << "Enter New Account NO : ";
            cin >> accountno;
            cout << "Are You Sure? (Y/N): ";
            cin >> ch;
            if (ch == 'Y' || ch == 'y')
            {
                account.accountno = accountno;
                cout << "Account Number Updated Successfully!";
            }
            else
            {
                cout << "Update Cancelled!";
            }
            break;
        }

        case 3:
            cout << "Update Cancelled!";
            break;

        default:
            cout << "Invalid Choice!";
        }
        cout << "\nAccount Number : " << account.accountno;
        cout << "\nName           : " << account.name;
        cout << "\nBalance        : " << account.balance;
    }
    else
    {
        cout << "Account Not Found!" << endl;
    }
}

int main()
{
    do
    {
        cout << "\n==================================\n";
        cout << "       BANK MANAGEMENT SYSTEM       \n";
        cout << "====================================\n";

        cout << "1. Create Account\n2. Deposit Money\n3. Withdraw Money\n4. Check Balance\n5. Delete Account\n6. Update Account\n7. Exit\n";

        int choice;
        cout << "\nEnter Your Choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createAccount();
            break;
        case 2:
            depositMoney();
            break;
        case 3:
            withdrawMoney();
            break;
        case 4:
            checkBalance();
            break;
        case 5:
            deleteAccount();
            break;
        case 6:
            updateAccount();
            break;
        case 7:
            cout << "Thank You for Using Bank Management System!";
            exit(0);
        default:
            cout << "Invalid Choice!";
        }
    } while (1);
}