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
	void swap()
	{
		node *temp = head;
		while(temp && temp->next)
		{
			temp->data += temp->next->data;
			temp->next->data = temp->data - temp->next->data;
			temp->data = temp->data - temp->next->data;
			temp = temp->next->next;
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
		cout << " 2.\tswap\n";
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
				L.swap();
			case 3:
				L.display();
		
		}
	}
}
