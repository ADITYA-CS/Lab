
#include <iostream>
#include <new>
using namespace std;

struct node
{
	int data;
	node *next;
};

class singly
{
private:
	node *head, *tail;
public:
  	singly ()
  	{
    	head = NULL;
    	tail = NULL;
  	}
  	void insert_at_beg (int t)
  	{
    	
    	node *temp = new node;
    	temp->data = t;
    	if (head == NULL)
    	{
			head = tail = temp;
			return;
    	}
    	temp->next = head;
    	head = temp;
  	}
  	void display ()
  	{
    	node *temp = head;
    	if (head == NULL)
    	{
			cout << " List is empty\n";
			return;
    	}
    	cout << " List\n :";
    	while (temp)
    	{
			cout << " " << temp->data;
			temp = temp->next;
    	}
    	cout << "\n";
  	}

};

int main ()
{
	singly s;
	int n;
	cout << " n = ";
	cin >> n;
	n++;
	while(n)
	{
		s.insert_at_beg(n%10);
		n /= 10;
	}
	s.display();	
}
