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
	void display_mid()
	{
		node *fptr, *sptr;
		if(tail == NULL)
		{
			cout << " " <<  " List is empty.\n";return;
		}
		if(head==tail)
		{
			cout << head->data << "\n";return;
		}
		fptr = head->next;
		sptr = head;
		while(fptr->next && fptr->next->next)
		{
			sptr = sptr->next;
			fptr = fptr->next->next;
		}
		cout << " Mid-Element : " <<  sptr->next->data << "\n";
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
	l.display_mid();
}
