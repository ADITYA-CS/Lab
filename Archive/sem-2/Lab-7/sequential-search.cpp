#include <iostream>
using namespace std;

struct Loan
{
    string name;
    int number;
    double amount;
};

void print(const Loan loan)
{
    cout <<  "---------------------------------------\n";
    cout << "Branch-name : " << loan.name;
    cout << "\nLoan-number : " << loan.number;
    cout << "\nLoan-amount : " << loan.amount;
    cout <<  "\n---------------------------------------\n";
}
int main()
{
    int n;
    char ch;
    cout << "Number of Loan's detail : ";
    cin >> n;
    Loan loan[n];

    for(int i = 0; i < n; i++)
    {
        cout <<  "---------------------------------------\n";
        cout << "Branch-name : ";
        cin.ignore(1);
        getline(cin, loan[i].name);
        cout << "Loan-number : ";
        cin >> loan[i].number;
        cout << "Loan-amount : ";
        cin >> loan[i].amount;
    }

    cout <<  "---------------------------------------\n";
    while(1)
    {
        int op, search_op;
        string  name;
        int number = 0;
        double amount = 0;
        cout << "\n0. Exit\n";
        cout << "1. Sequential search\n";
        cout << "Choice : ";
        cin >> op;
        if(!op) break;

        cout << "1. search by Branch-name\n";
        cout << "2. search by Loan-number\n";
        cout << "3. search by Loan-amount\n";
        cout << "Choice : ";
        cin >> search_op;
        cin.clear();
        if(search_op == 1)
            cout << " Branch-name : ",  cin.ignore(1), getline(cin, name);
        else if(search_op == 2)
            cout << " Loan-number : ", cin >> number;
        else
            cout << " Loan-amount : ", cin >> amount;

        cout << name << "\n";
        cout << number << "\n";
        cout << amount << "\n";
        bool found = false;
        int i;
        for(i = 0; i < n; i++)
        {
            if(search_op == 1)
            {
                if(loan[i].name == name)
                {
                    found = true;
                    break;
                }
            }
            else if(search_op == 2)
            {
                if(loan[i].number == number)
                {
                    found = true;
                    break;
                }
            }
            else
            {
                if(loan[i].amount == amount)
                {
                    found = true;
                    break;
                }
            }
        }

        if(found)
            cout << "Record is found\n", print(loan[i]);
        else
            cout << "Record is not found\n";
    }
}
