#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    scanf("%d", &test);
    for(int test_case = 1; test_case <= test; test_case++)
    {
        int n;
        scanf("%d", &n);
        int arr[n][n];
        int trace = 0, row = 0, column = 0;
        bool balance[n], added = false;
        memset(balance, false, n);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%d", &arr[i][j]);
                if(i == j)
                    trace += arr[i][j];
                balance[arr[i][j]-1] = true;
            }
            added = false;
            for(int j = 0; j < n; j++)
            {
                if(!balance[j] && !added)
                {
                    added = true;
                    row++;
                }
                balance[j] = false;
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                balance[arr[j][i]-1] = true;
            }
            added = false;
            for(int j = 0; j < n; j++)
            {
                if(!balance[j] && !added)
                {
                    added = true;
                    column++;
                }
                balance[j] = false;
            }
        }
        printf("Case #%d: %d %d %d\n", test_case, trace, row, column);
    }
}
