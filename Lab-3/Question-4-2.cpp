#include <iostream>
using namespace std;

struct node
{	
	int data;
	node *next;
	node(int x)
	{
		data = x;
		next = NULL;
	}
};

class stack
{
private:
	node *top;
public:
	stack()
	{
		top = NULL;
	}
	void push(int x)
	{
		node * temp = new node(x);
		if(top == NULL)
		{
			top = temp;
			return;
		}
		temp->next = top;
		top = temp;
	}
	void pop()
	{
		if(isEmpty())
		{
			cout << " Stack is empty.\n";
			return;
		}
		node * temp = top;
		top = top->next;
		delete temp;
	}
	int peek()
	{
		if(top==NULL)
			return -1;
		return top->data;
	}
	bool isEmpty()
	{
		return top == NULL;
	}
};

int main()
{
	int temp, op;
	stack s;
	while(1)
	{
		cout << " 0.\tExit\n";
		cout << " 1.\tPush\n";
		cout << " 2.\tPop\n";
		cout << " 3.\tPeek\n";
		cout << " 4.\tisEmpty\n";
		cout << " Option : ";
		cin >> op;
		switch(op)
		{
			case 0:
				exit(0);
			case 1:
				cout << " Data to push : ";
				cin >> temp;
				s.push(temp);
				break;
			case 2:
				s.pop();
				break;
			case 3:
				temp = s.peek();
				if(temp == -1)
					cout << " Stack is empty.\n";
				else
					cout << " Top element is " << temp << "\n";
				break;
			case 4:
				if(s.isEmpty())
					cout << " Stack is empty.\n";
				else
					cout << " Stack is not empty.\n";
				break;
		}
	}
}


