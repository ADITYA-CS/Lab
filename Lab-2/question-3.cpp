#include <iostream>
using namespace std;

int natural_sum(int n)
{
	return n ? n + natural_sum(n-1) : 0;
}
int main()
{
	int n;
	cout << " Enter a number : ";
	cin >> n;
	cout << " Natural sum upto " << n << " is " << natural_sum(n) << ".\n";
}
