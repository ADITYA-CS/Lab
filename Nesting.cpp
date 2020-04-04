#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    scanf("%d",&test );
    for(int test_case = 0; test_case < test; test_case++)
    {
        char input[101];
        scanf("%s", input);
        string ans = "";
        int p = 0;
        for(int i = 0, j = strlen(input); i < j; i++)
        {
            t = input[i] - '0';
            while(p < t)
            {
                ans += '(';
                p++;
            }
            while(p > t)
            {
                ans += ')';
                p--;
            }
            ans += '0' + t;
        }
        while(p)
        {
            ans += ')';
            p--;
        }
        cout << str << '\n';
    }
}
