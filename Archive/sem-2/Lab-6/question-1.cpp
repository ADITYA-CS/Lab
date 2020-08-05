#include <iostream>
#include <stack>
using namespace std;

string infixToPostfix(string);
bool isOperator(char ch);
int precedence(char ch);


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
	       string infix;
	       cin >> infix;
	       string postfix = infixToPostfix(infix);
	       cout << postfix << "\n";
    }
}

string infixToPostfix(string s)
{
	string res = "";
	stack<char> st;

	int i = 0;
	while(s[i])
	{
		if(!isOperator(s[i]))
		{
			res += s[i++];
				continue;
		}
		else
		{
			if(st.empty() || (st.top() == '(' && s[i] != ')'))
			{
				st.push(s[i++]);
				continue;
			}
			if(s[i] == '(')
			{
				st.push(s[i++]);
				continue;
			}
			else if(s[i] == ')')
			{
				while(st.top() != '(')
				{
					res += st.top();
					st.pop();
				}
				st.pop();
				i++;
				continue;
			}
			else if(s[i] == '^')
			{
				st.push(s[i++]);
				continue;
			}
			else if(precedence(s[i]) > precedence(st.top()))
			{
				st.push(s[i]);
				i++;
				continue;
			}
			else if(precedence(s[i]) <= precedence(st.top()))
			{
				while(!st.empty() && st.top() != '(' && precedence(s[i]) <= precedence(st.top()))
				{
					res += st.top();
					st.pop();
				}
				st.push(s[i]);
				i++;
				continue;
			}
		}
	}
	while(!st.empty())
	{
        if(st.top() != '(')
		      res += st.top();
		st.pop();
	}

	return res;
}

int precedence(char ch)
{
	if(ch == '+' || ch == '-')
		return 1;
	if(ch == '*' || ch == '/' || ch == '%')
		return 2;
	return 3;
}

bool isOperator(char ch)
{
	return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^' || ch == '(' || ch == ')';
}
