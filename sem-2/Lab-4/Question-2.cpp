#include <iostream>
#include <stack>
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
	Node * reverseK(Node *head, int k)
    {
        Node *ptr, *prev, *next;
        ptr = head, prev = NULL;
        for(int i = 0; i < k && ptr; i++)
        {
            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
        }

        if(ptr)
            head->next = removeK(ptr, k);
        return prev;
    }
    void reverseK(int k)
    {
        head = reverseK(head, k);
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
		cout << " 2.\tReverse\n";
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
				cout << " K = ";
				cin >> option;
				L.reverseK(option);
			case 3:
				L.display();

		}
	}
}
