#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n, r, m;
        cin >> n >> r >> m;
        vector<int> a, b;
        int  i = log10(n) / log10(m);
        int  j = log10(r) / log10(m);

        for(int k = j; k < i; k++)
            b.push_back(0);

        long long temp = pow(m, i);
        for(; i >= 0; i--)
        {
            a.push_back(n/temp);
            n %= temp;
            temp /= m;
        }

        temp = pow(r, j);
        for(; j >= 0; j--)
        {
            a.push_back(r/temp);
            r %= temp;
            temp /= r;
        }
    }
}
