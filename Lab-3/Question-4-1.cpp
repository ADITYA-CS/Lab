#include <iostream>
using namespace std;

class stack
{
private:
	int size;
	int top;
	int *array;
public:
	stack(int x)
	{
		size = x;
		top = -1;
		array = new int[x];
	}
	void push(int x)
	{
		if(isFull())
		{
			cout << " Stack is Full\n";
			return;
		}
		array[++top] = x;
	}
	void pop()
	{
		if(isEmpty())
		{
			cout << " Stack is empty\n";
			return;
		}
		top--;
	}
	int peek()
	{
		if(isEmpty())
		{
			return -1;
		}
		return array[top];
	}
	bool isFull()
	{
		return top == size-1;
	}
	bool isEmpty()
	{
		return top == -1;
	}
};

int main()
{
	int temp, op;
	cout << " Size of stack : ";
	cin >> temp; 
	stack s(temp);
	while(1)
	{
		cout << " 0.\tExit\n";
		cout << " 1.\tPush\n";
		cout << " 2.\tPop\n";
		cout << " 3.\tPeek\n";
		cout << " 4.\tisFull\n";
		cout << " 5.\tisEmpty\n";
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
				if(s.isFull())
					cout << " Stack is full.\n";
				else
					cout << " Stack is not full.\n";
				break;
			case 5:
				if(s.isEmpty())
					cout << " Stack is empty.\n";
				else
					cout << " Stack is not empty.\n";
				break;
		}
	}
}
