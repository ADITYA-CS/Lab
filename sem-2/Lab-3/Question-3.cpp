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
	int sum()
	{
		if(tail == NULL)
		{
			return -1;
		}
		int sum = 0;
		node *temp = head;
		while(temp)
		{
			if(temp->data%2 == 0)
				sum += temp->data;
			temp = temp->next;
		}
		return sum;
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
	t = l.sum();
	if(t == -1)
		cout << " List is empty.\n";
	else 
		cout << " Sum : " << t << "\n";
	cout << "\n";
}
