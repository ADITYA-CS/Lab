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
  	void insert_at_beg ()
  	{
    	int t;
    	cout << " Data to insert : ";
    	cin >> t;
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
  	void insert_at_end ()
  	{
    	if (tail == NULL)
    	{
			insert_at_beg ();
			return;
    	}
    	int t;
    	cout << " Data to insert : ";
    	cin >> t;
    	node *temp = new node;
    	temp->data = t;
    	tail->next = temp;
    	tail = temp;
  	}
  	void insert_at_middle ()
  	{
    	int t = count ();
    	if (t == 1)
    	{
			insert_at_beg ();
			return;
    	}
    	t = t / 2 - 1;
    	node *temp = head;
    	while (t--)
    	{
			temp = temp->next;
    	}
    	node *p = new node;
    	cout << " Data to insert : ";
    	cin >> p->data;
    	p->next = temp->next;
    	temp->next = p;
  	}
  	void insert_at_position ()
  	{
    	int t;
    	cout << " Position : ";
    	cin >> t;
    	if (t == 0)
    	{
			insert_at_beg ();
			return;
    	}
    	t--;
    	node *temp = head;
    	while (t--)
    	{
			temp = temp->next;
    	}
    	node *p = new node;
    	cout << " Data to insert : ";
    	cin >> p->data;
    	p->next = temp->next;
    	temp->next = p;
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
  	void delete_at_beg ()
  	{
    	if (head == NULL)
    	{
			cout << " List is empty.\n";
			return;
    	}
    	node *temp = head;
    	if (head == tail)
    	{
			delete temp;
			head = tail = NULL;
			return;
    	}
    	head = head->next;
    	delete temp;
  	}
  	void delete_at_end ()
  	{
    	if (head == NULL)
    	{
			cout << " List is empty.\n";
			return;
    	}
    	node *temp = head;
    	if (head == tail)
    	{
			delete temp;
			head = tail = NULL;
			return;
    	}
    	while (temp->next != tail)
    	{
			temp = temp->next;
    	}
    	temp->next = NULL;
    	delete tail;
    	tail = temp;
  	}
  	void delete_at_position ()
  	{
    	int t, k;
    	cout << " Position : ";
    	cin >> t;
    	k = count ();
    	if (t < 0 && t > k)
    	{
			cout << " --invlid position--\n";
			return;
    	}
    	if (t == 0)
    	{
			delete_at_beg ();
			return;
    	}
    	else if (t == k)
    	{
			delete_at_end ();
			return;
    	}
    	node *temp = head;
    	t--;
    	while (t--)
    	{
			temp = temp->next;
    	}
    	node *T = temp->next;
    	temp->next = T->next;
    	delete T;
  	}
  	void delete_at_middle ()
  	{
    	int t = count ();
    	if (t == 1)
    	{
			return;
    	}
    	else if (t == 2)
    	{
			delete_at_beg ();
			return;
    	}
    	t = t / 2;
    	t--;
    	node *temp = head;
    	while (t--)
    	{
			temp = temp->next;
    	}
    	node *T = temp->next;
    	temp->next = T->next;
    	delete T;
  	}
  	void display_rev ()
  	{
    	if (head == NULL)
    	{
			cout << " List is empty.\n";
			return;
    	}
    	cout << " List\n :";
		dis (head);
    	cout << "\n";
  	}
  	void dis (node * ptr)
  	{
    	if (ptr)
    	{
			dis (ptr->next);
			cout << " " << ptr->data;
    	}
  	}
  	void search (int key)
  	{
    	node *temp = head;
    	int p = -1;
    	while (temp)
    	{
			p++;
			if (temp->data == key)
	  		{
	    		cout << " " << key << " is present at position : " << p << "\n";
	    		return;
	  		}
			temp = temp->next;
		}
    	cout << " " << key << " is not present\n";
  	}
  	int count ()
  	{
    	int t = 0;
    	node *temp = head;
    	while (temp)
    	{
			t++;
			temp = temp->next;
    	}
    	return t;
  	}
  	void swap_adjacent ()
  	{
    	node *temp = head, *p, *q;
    	while (temp)
    	{
			p = temp;
			temp = temp->next;
			if (!temp)
	  			return;
				q = temp;
				temp = temp->next;
				p->data += q->data;
				q->data = p->data - q->data;
				p->data -= q->data;
    	}
  	}
	Node * swapTwo( Node *ptr)
	{
		if(!ptr || !(ptr->next))
			return ptr;

		Node *p, *n;
		p = ptr->next;
		n = p->next;

		p->next = ptr;
		ptr->next = swapTwo(n);
		return p;
	}
	void swapAdj()
	{
		head = swapTwo(head);
	}
};

int main ()
{
	singly list;
  	int option, key;
      	cout << "\n";
      	cout << " 0.\tExit\n";
      	cout << " 1.\tInsert at the begining\n";
      	cout << " 2.\tInsert at the end\n";
      	cout << " 3.\tInsert at middle\n";
      	cout << " 4.\tInsert at position\n";
      	cout << " 5.\tDisplay\n";
      	cout << " 6.\tcount\n";
      	cout << " 7.\tDelete at begining\n";
      	cout << " 8.\tDelete at end\n";
      	cout << " 9.\tDelete at position\n";
      	cout << " 10.\tDelete at middle\n";
      	cout << " 11.\tSearch\n";
      	cout << " 12.\tReverse display\n";	//question 3rd
      	cout << " 13:\tSwap adjacent\n";	//question 5th

  	while (1)
  	{
      	cout << "\v Enter your choice : ";
      	cin >> option;
      	switch (option)
	  	{
		  	case 0:
		  		exit (0);
			case 1:
	  			list.insert_at_beg ();
	  			break;
			case 2:
	  			list.insert_at_end ();
	  			break;
			case 3:
	  			list.insert_at_middle ();
	  			break;
			case 4:
	  			list.insert_at_position ();
	  			break;
			case 5:
	  			list.display ();
	  			break;
			case 6:
	  			cout << " No of nodes : " << list.count () << "\n";
	  			break;
			case 7:
	  			list.delete_at_beg ();
	  			break;
			case 8:
	  			list.delete_at_end ();
	  			break;
			case 9:
	  			list.delete_at_position ();
	  			break;
			case 10:
	  			list.delete_at_middle ();
	  			break;
			case 11:
	  			cout << " Data to search : ";
	  			cin >> key;
	  			list.search(key);
	  			break;
			case 12:
	  			list.display_rev ();
	  			break;
			case 13:
	  			list.swap_adjacent ();
	  			break;
			default:
	  			cout << "\n";
	  			break;
		}
  	}
}
