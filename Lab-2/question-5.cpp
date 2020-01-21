#include <iostream>
using namespace std;

void copy(string &s, string &cs, int i = 0)
{
	if(s[i])
	{
		cs += s[i];
		copy(s,cs,i+1);
	}
}

int main()
{
	string str,s="";
	cout << " Enter string : ";
	cin >> str;
	copy(str,s);
	cout << " Copied string : "<< s <<"\n";
}
