#include <iostream>
using namespace std;

int reverse(int n, int m = 0)
{
    if(n==0)
        return m;
    m = m * 10 + n % 10;
    return reverse(n/10, m);
}

int main()
{
    int n;
    cout << " n = ";
    cin >> n;
    if(n==reverse(n))
        cout << " It is a palindrome.\n";
    else
        cout << " It is not a palindrome.\n";
}

