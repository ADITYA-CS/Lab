#include <iostream>
#include <cmath>
using namespace std;

struct node 
{
	double x, c;
	node * next;
	node(double a, double b)
	{
		c = a;
		x = b;
		next = NULL;
	}
};

class poly
{
private:
	node *head, *tail;
public:
	poly()
	{
		head = tail = NULL;	
	}
	void create(double a, double b)
	{
		node * temp = new node(a, b);
		if(!head)
		{
			head = tail = temp;
			return;
		}
		tail->next = temp;
		tail = temp;
	}
	void display()
	{
		node * temp = head;
		while(temp)
		{
			cout << temp->c << "x^" << temp->x << " ";
			if(temp->next)
				cout << "+ ";
			else
				cout << "\n";
			temp = temp->next;
		}
	}
	friend poly polySum(poly , poly);
};


int main()
{
	poly P1, P2, result;
	double c, x;
	cin >> c >> x;
	P1.create(c,x);
	cin >> c >> x;
	P1.create(c,x);
	cin >> c >> x;
	P1.create(c,x);
	P1.display();
	cin >> c >> x;
	P2.create(c,x);
	cin >> c >> x;
	P2.create(c,x);
	P2.display();
	result = polySum(P1, P2);
	result.display();
}

poly polySum(poly p1, poly p2)
{
	poly result;
	node * ptr1 = p1.head;
	node * ptr2 = p2.head;
	while( ptr1 && ptr2)
	{
		if(ptr1->x == ptr2->x)
		{
			result.create(ptr1->c + ptr2->c, ptr1->x);
			ptr1 = ptr1->next, ptr2 = ptr2->next;
		}
		else if(ptr1->x > ptr2->x)
		{
			result.create(ptr1->c, ptr1->x);
			ptr1 = ptr1->next;
		}
		else
		{
			result.create(ptr2->c, ptr1->x);
			ptr2 = ptr2->next;
		}
	}
	while(ptr1)
	{
		result.create(ptr1->c, ptr1->x);
		ptr1 = ptr1->next;
	}

	while(ptr2)
	{
		result.create(ptr2->c, ptr2->x);
		ptr2 = ptr2->next;
	}
	return result;
}


