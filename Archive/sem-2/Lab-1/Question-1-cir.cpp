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

class circular
{
private:
	node *tail;
public:
	circular()
	{
		tail = NULL;
	}
	void display()
	{
		if(!tail)
		{
			cout << " List is empty.\n";
			return;	
		}
		cout << " List\n : ";
		node *temp = tail->next;
		while(temp != tail)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << temp->data <<"\n";
	}
	void insert_at_beg()
	{
		int x;
		cout << " Data to insert : ";
		cin >> x;
		node *New = new node(x);
		if(!tail)
		{
			New->next = New;
			tail = New;
			return;	
		}
		New->next = tail->next;
		tail->next = New;
	}
	void insert_at_end()
	{
		if(!tail)
		{
			insert_at_beg();
			return;
		}
		int x;
		cout << " Data to insert : ";
		cin >> x;
		node *New = new node(x);
		New->next = tail->next;
		tail->next = New;
		tail = New;
	}
	void insert_at_position(int x)
	{
		if(!tail)
		{
			cout << " List is empty.\n";
			return;
		}
		int c;
		c = count();
		if(x > c+1)
		{
			cout << " position doesn't exit.\n";
			return;
		}
		else if(x == c+1)
		{
			insert_at_end();
			return;
		}
		node *ptr = tail;
		int i = 1;
		for(;i<x; i++)
		{
			ptr = ptr->next;
		}
		int y;
		cout << " Data to insert : ";
		cin >> y;
		node *New = new node(y);
		New->next = ptr->next;
		ptr->next = New;
	}
	void delete_at_beg()
	{
		if(!tail)
		{
			cout << "there is no thing to delete\n";
			return;
		}
		if(tail->next == tail)
		{
			delete tail;
			tail = NULL;
			return;
		}
		node *temp = tail->next;
		tail->next = temp->next;
		delete temp;
	}
	void delete_at_end()
	{
		if(!tail)
		{
			cout << "there is no thing to delete\n";
			return;
		}
		if(tail->next == tail)
		{
			delete tail;
			tail = NULL;
			return;
		}
		node *temp = tail;
		while(tail->next != temp)
		{
			tail =tail->next;
		}
		tail->next = temp->next;
		delete temp;
	}
	void delete_at_position(int x)
	{
		if(!tail)
		{
			cout << " List is empty.\n";
			return;
		}
		int c;
		c = count();
		if(x > c)
		{
			cout << " position doesn't exit.\n";
			return;
		}
		else if(x == c)
		{
			delete_at_end();
			return;
		}
		node *ptr = tail;
		int i = 1;
		for(;i<x; i++)
		{
			ptr = ptr->next;
		}
		node *temp = ptr->next;
		ptr->next = temp->next;
		delete temp;
	}
	int search(int x)
	{
		if(!tail)
			return 0;
		if(tail->next == tail && tail->data == x)
			return 1;
		int i = 0;
		node *p = tail->next;
		while(1)
		{
			i++;
			if(p->data == x)
				return i;
			if(p == tail)
				break;
			p = p->next;
		}
		return -1;
	}
	int count()
	{
		if(!tail)
		{
			return 0;
		}
		int i = 1;
		node *p = tail->next;
		while(p != tail)
		{
			i++;
			p  = p->next;
		}
		return i;
	}
};
int main()
{
	circular c;
	int option;
	while(1)
	{
		cout << " 0.\tExit\n";
		cout << " 1.\tDisplay\n";
		cout << " 2.\tInsert at beg\n";
		cout << " 3.\tInsert at end\n";
		cout << " 4.\tInsert at middle\n";
		cout << " 5.\tInsert at position\n";
		cout << " 6.\tDelete at beg\n";
		cout << " 7.\tDelete at end\n";
		cout << " 8.\tDelete at middle\n";
		cout << " 9.\tDelete at position\n";
		cout << " 10.\tData to search\n";
		cout << " 11.\tCount nodes\n";
		cout << " Option : ";
		cin >> option;
		switch(option)
		{
			case 0:
				exit(0);
			case 1:
				c.display();
				break;
			case 2:
				c.insert_at_beg();
				break;
			case 3:
				c.insert_at_end();
				break;
			case 4:
				c.insert_at_position(c.count()/2+1);
				break;
			case 5:
				cout << " Enter position : ";
				cin >> option;
				c.insert_at_position(option);
				break;
			case 6:
				c.delete_at_beg();
				break;
			case 7:
				c.delete_at_end();
				break;
			case 8:
				c.delete_at_position(c.count()/2+1);
				break;
			case 9:
				cout << " Enter position : ";
				cin >> option;
				c.delete_at_position(option);
				break;
			case 10:
				cout << " Data to search : ";
				cin >> option;
				cout << " Found at " << c.search(option) << " position\n";
				break;
			case 11:
				cout << " Number of nodes : " << c.count() << "\n";
				break;
		}

	}
}
