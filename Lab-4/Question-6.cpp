#include <iostream>
using namespace std;

struct node
{
	int data ;
	node *next,*prev;
	node(int x)
	{
		data = x;
		next = prev = NULL;
	}
};

class DL
{
private:
	node *head, *tail;
	void show(node *ptr)
	{
		if(ptr)
		{
			cout << " " << ptr->data;
			show(ptr->next);
		}
	}
public:
	DL()
	{
		head=tail=NULL;
	}
	void insert(int x)
	{
		node *temp = new node(x);
		if(!head)
		{
			head = tail = temp;	
			return;
		}
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
	int smallest()
	{
		int x  = head->data;
		node *temp = head;
		while(temp)
		{
			if(temp->data < x)
				x = temp->data;
			temp =temp->next;
		}
		return x;
	}
	void Display()
	{
		show(head);
	}
};

int main()
{
	int n, temp;
	cout << " n = ";
	cin >> n;
	DL l;
	cout << " Elements\n";
	while(n--)
	{
		cout << " : ";
		cin >> temp;
		l.insert(temp);
	}
	l.Display();
	cout << "\n";
	cout << " Smallest Number: " << l.smallest() <<"\n";
}
