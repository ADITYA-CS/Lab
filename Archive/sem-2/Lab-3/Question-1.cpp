#include <iostream>
using namespace std;

struct node
{
	node *prev;
	int data;
	node *next;
	node(int x)
	{
		data = x;
		prev = next = NULL;
	}
};

class DL
{
private:
	node *head, *tail;
public:
	DL()
	{
		head = tail = NULL;
	}
	void insert(int x)
	{
		node *temp = new node(x);
		if(tail == NULL)
		{
			head = tail = temp;
			return;
		}
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	void display()
	{
		if(tail == NULL)
		{
			cout << " List is empty.\n";return;
		}
		cout << " List : ";
		node *temp = head;
		while(temp)
		{
			cout << " " << temp->data;
			temp = temp->next;
		}
	}
};
int main()
{
	DL l;
	int n, t;
	cout << " Number of element to insert in list : ";
	cin >> n;
	cout << " Element\n";
	while(n--)
	{
		cout << " :";
		cin >> t;
		l.insert(t);
	}
	l.display();
	cout << "\n";
}
