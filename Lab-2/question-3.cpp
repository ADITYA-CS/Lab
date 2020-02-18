#include <iostream>
using namespace std;

void print(int n)
{
	if(n)
	{
		print(n-1);
		cout << "\n" << n;
	}
}
int main()
{
	int n;
	cout << " n = ";
	cin >> n;
	print(n);
	cout << "\n";
}
