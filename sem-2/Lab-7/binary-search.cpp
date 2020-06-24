#include <iostream>
#include <algorithm>
using namespace std;

struct Loan
{
    string name;
    int number;
    double amount;
};

void Print(const Loan loan)
{
    cout <<  "---------------------------------------\n";
    cout << "Branch-name : " << loan.name;
    cout << "\nLoan-number : " << loan.number;
    cout << "\nLoan-amount : " << loan.amount;
    cout <<  "\n---------------------------------------\n";
}

bool SortByName(const Loan &a, const Loan &b)
{
    return a.name < b.name;
}

bool SortByNumber(const Loan &a, const Loan &b)
{
    return a.number < b.number;
}
bool SortByAmount(const Loan &a, const Loan &b)
{
    return a.amount < b.amount;
}

pair<bool,int> BinarySearch(const Loan loan[],string key, int up, int lo = 0)
{
    if(lo > up)
        return make_pair(false, -1);

    int mid = lo + (up - lo)/2;

    if(loan[mid].name == key)
        return make_pair(true, mid);
    else if(loan[mid].name > key)
        BinarySearch(loan, key, up, mid + 1);
    else
        BinarySearch(loan, key, mid - 1, lo);
}
pair<bool,int> BinarySearch(const Loan loan[], int key, int up, int lo = 0)
{
    if(lo > up)
        return make_pair(false, -1);

    int mid = lo + (up - lo)/2;

    if(loan[mid].number == key)
        return make_pair(true, mid);
    else if(loan[mid].number > key)
        BinarySearch(loan, key, up, mid + 1);
    else
        BinarySearch(loan, key, mid - 1, lo);
}
pair<bool,int> BinarySearch(const Loan loan[], double key, int up, int lo = 0)
{
    if(lo > up)
        return make_pair(false, -1);

    int mid = lo + (up - lo)/2;

    if(loan[mid].amount == key)
        return make_pair(true, mid);
    else if(loan[mid].amount > key)
        BinarySearch(loan, key, up, mid + 1);
    else
        BinarySearch(loan, key, mid - 1, lo);
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
        cout << "1. Binary search\n";
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
        if(search_op == 1)
        {
            sort(loan, loan + n, SortByName);
            for(int j = 0; j < n; j++) Print(loan[j]);
            auto pp = BinarySearch(loan, name, n-1);
            if(pp.first)
            {
                found = true;
                i = pp.second;
            }
        }
        else if(search_op == 2)
        {
            sort(loan, loan + n, SortByNumber);
            for(int j = 0; j < n; j++) Print(loan[j]);
            auto pp = BinarySearch(loan, number, n-1);
            if(pp.first)
            {
                found = true;
                i = pp.second;
            }
        }
        else
        {
            sort(loan, loan + n, SortByAmount);
            for(int j = 0; j < n; j++) Print(loan[j]);
            auto pp = BinarySearch(loan, amount, n-1)
            if()
            {
                found = true;
                i = pp.second;
            }
        }

        if(found)
            cout << "Record is found\n", Print(loan[i]);
        else
            cout << "Record is not found\n";
    }
}
