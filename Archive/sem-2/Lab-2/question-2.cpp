#include <iostream>
using namespace std;

int length(string s, int i = 0)
{
	if(s[i])
	{
		return 1 + length(s,i+1);
	}
	return 0;
}

int main()
{
	string str;
	cout << " Enter a string : ";
	cin >> str;
	cout << " Length of the string is " << length(str) <<".\n";
}
