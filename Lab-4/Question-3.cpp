#include <iostream>
using namespace std;

struct node
{
	int data;
	node * next;
	node(int y)
	{
		data = y;
		next = NULL;
	}
};

class list
{
private:
	node *head, *tail;
	void show(node *ptr)
	{
		if(ptr)
		{
			cout << ptr->data << " ";
			show(ptr->next);
		}
	}
public:
	list()
	{
		head = NULL;
		tail = NULL;
	}
	void insert(int x)
	{
		node *temp = new node(x);
		if(head == NULL)
		{
			head = tail = temp;
			return;
		}
		tail->next = temp;
		tail = temp;
	}
	void display()
	{
		cout << " ";show(head);
	}
	void RemoveDuplicate()
	{
		node *ptr = head, *p = head;
		while(ptr)
		{
			p = ptr;
			while(p)
			{
				if(p->next && p->next->data == ptr->data)
				{
					node *temp = p->next;	
					p->next = temp->next;
					delete temp;
				}
				p = p->next;
			}
			ptr = ptr->next;
		}
	}
};

int main()
{
	list L;
	int option;
	while(1)
	{
		cout << "\n 0.\tExit\n";
		cout << " 1.\tInsert\n";
		cout << " 2.\tRemove Duplicate\n";
		cout << " 3.\tDisplay\n";
		cout << " Option : ";
		cin >> option;
		switch(option)
		{
			case 0:
				exit(0);
			case 1:
				cout << " Data to insert : ";
				cin >> option;
				L.insert(option);
				break;
			case 2:
				L.RemoveDuplicate();
			case 3:
				L.display();
		
		}
	}
}
