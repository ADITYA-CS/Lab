#include <iostream>
using namespace std;

bool palindrome(string str, int i = 0)
{
    return i < str.size()/2 ? str[i] == str[str.size()-i-1] && palindrome(str, i+1) : true;
}

int main()
{
    string n;
    cout << " n = ";
    cin >> n;
    if(palindrome(n))
        cout << " It is a palindrome.\n";
    else
        cout << " It is not a palindrome.\n";
}
