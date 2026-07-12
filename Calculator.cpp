#include <iostream>
#include <stdlib.h>
using namespace std;
void sum(int a, int b)
{
    int c = a + b;
    cout << "The Sum = " << c << endl;
}
void subtraction(int a, int b)
{
    int c = a - b;
    cout << "The Difference = " << c << endl;
}
void mul(int a, int b)
{
    int c = a * b;
    cout << "The Multiplication = " << c << endl;
}
void Division(int a, int b)
{
    if (b == 0)
    {
        cout << "Division by zero is not possible." << endl;
        return;
    }

    cout << "The Division = " << (float)a / b << endl;
}
void Rem(int a, int b)
{
    if (b == 0)
    {
        cout << "Remainder by zero is not possible." << endl;
        return;
    }
    int c = a % b;
    cout << "The Remainder = " << c << endl;
}

int main()
{
    do
    {
        cout << "=============================\n";
        cout << "      SIMPLE CALCULATOR      \n";
        cout << "=============================\n";
        int choice;
        cout << "\n1 -> Addition\n2 -> Subtraction\n3 -> Multiplication\n4 -> Division\n5 -> Remainder\n6 -> Exit\n";
        cout << "\nEnter Your Choice:";
        cin >> choice;

        if (choice < 1 || choice > 6)
        {
            cout << "Invalid Choice!" << endl;
            continue;
        }
        cout << "\n------------------------------------\n";
        int a, b;
        cout << "Enter First Number  :";
        cin >> a;
        cout << "Enter Second Number :";
        cin >> b;
        cout << endl;

        switch (choice)
        {
        case 1:
            sum(a, b);
            break;

        case 2:
            subtraction(a, b);
            break;

        case 3:
            mul(a, b);
            break;

        case 4:
            Division(a, b);
            break;

        case 5:
            Rem(a, b);
            break;

        case 6:
            return 0;
        }

        char ch;
        cout << endl;
        cout << "\n------------------------------------\n";
        cout << "Do You Want To Continue Y or N:";
        cin >> ch;

        if (ch == 'Y' || ch == 'y')
        {
            continue;
        }
        else
        {
            cout << "\nThank You for using the Calculator!" << endl;
            return 0;
        }

    } while (1);
}