#include <iostream>
#include <new>
using namespace std;

struct node
{
	int usn,sem;
	long long phone;
	string name, branch;
	node *next;
};

class singly
{
private:
	node *head, *tail;
public:
	singly()
	{
		head = NULL;
		tail = NULL;
	}
	void insert_at_beg()
	{
		node *temp = new node;
		cout << " USN      : ";
		cin >> temp->usn;
		cout << " Name     : ";
		cin >> temp->name;
		cout << " Sem      : ";
		cin >> temp->sem;
		cout << " Branch   : ";
		cin >> temp->branch;
		cout << " Phone no : ";
		cin >> temp->phone;
		if(head == NULL)
		{
			head = tail = temp;
			return;
		}
		temp->next = head;
		head = temp;
	}
	void insert_at_end()
	{
		if(tail == NULL)
		{
			insert_at_beg();
			return;
		}
		node *temp = new node;
		cout << " USN      : ";
		cin >> temp->usn;
		cout << " Name     : ";
		cin >> temp->name;
		cout << " Sem      : ";
		cin >> temp->sem;
		cout << " Branch   : ";
		cin >> temp->branch;
		cout << " Phone no : ";
		cin >> temp->phone;
		tail->next = temp;
		temp->next = NULL;
		tail = temp;
	}
	void display()
	{
		node *p = head;
		if(head == NULL)
		{
			cout << " List is empty\n";return;
		}
		while(p)
		{
			cout << " USN       : " << p->usn << "\n";
			cout << " Name      : " << p->name << "\n";
			cout << " Sem       : " << p->sem << "\n";
			cout << " Branch    : " << p->branch << "\n";
			cout << " Phone no  : " << p->phone << "\n\v";
			p = p->next;
		}
		cout << "\n";
	}
	void delete_at_beg()
	{
		if(head == NULL)
		{
			cout << " List is empty.\n";return;
		}
		node *temp = head;
		if(head==tail)
		{
			delete temp;
			head = tail = NULL;
			return;
		}
		head = head->next;
		delete temp;
		cout << " Task completed\n";
	}
	void delete_at_end()
	{
		if(head == NULL)
		{
			cout << " List is empty.\n";return;
		}
		node *temp = head;
		if(head==tail)
		{
			delete temp;
			head = tail = NULL;
			cout << " Task completed\n";
			return;
		}
		while(temp->next != tail)
		{
			temp = temp->next;
		}
		temp->next = NULL;
		delete tail;
		tail = temp;
		cout << " Task completed\n";
	}
	int count()
	{
		int t = 0;
		node *temp = head;
		while(temp)
		{
			t++;temp = temp->next;
		}
		return t;
	}
};
int main()
{
	singly stu;
	int n, option;
	cout << " Number of student : ";
	cin >> n;

	while(n--)
	{
		stu.insert_at_beg();
		cout << "\n";
	}
	
		cout << " 0.\tExit\n";
		cout << " 1.\tStatus of list\n";
		cout << " 2.\tNumber of student\n";
		cout << " 3.\tInsert at beg\n";
		cout << " 4.\tInsert at end\n";
		cout << " 5.\tDelete at beg\n";
		cout << " 6.\tDelete at end\n";
	while(1)
	{
		cout << " Option : ";
		cin >> option;
		cout << "\n";
		switch(option)
		{
			case 0:
				exit(0);
			case 1:
				stu.display();
				break;
 			case 2:
				cout << " Number of student : " << stu.count() << "\n\n";
				break;
			case 3:
				stu.insert_at_beg();
				break;
			case 4:
				stu.insert_at_end();
				break;
			case 5:
				stu.delete_at_beg();
				break;
			case 6:
				stu.delete_at_end();
				break;
		}

	}
}
