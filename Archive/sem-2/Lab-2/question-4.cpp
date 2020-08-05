#include <iostream>
using namespace std;

int pow(int n, int p)
{
	if(p == 0)
		return 1;
	if(p == 1)
		return n;
	int temp = pow(n,p/2);
	if(p%2)
		return temp*temp*n;
	return temp*temp;
}

int main()
{
	int n, p;
	cout << " To calculate n^p, Enter\n";
	cout << " n = ";
	cin >> n;
	cout << " p = ";
	cin >> p;
	cout << " " <<  n << "^" << p << " = " << pow(n,p) << "\n";
}
