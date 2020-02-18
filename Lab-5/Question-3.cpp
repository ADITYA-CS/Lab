#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

struct node
{
	double x;
	node * next;
	node(double a)
	{
		x = a;
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
	void create(double a)
	{
		node * temp = new node(a);
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
			cout << temp->x << " ";
			temp = temp->next;
		}
	}
	friend poly intersect(poly p1, poly p2);
};


int main()
{
	poly P1, P2, result;
	double c;
	string str;
	getline(cin, str);
	istringstream in(str);
	while(in >> c)
	{
		P1.create(c);
	}
	P1.display();
	cout << "\n";

	getline(cin, str);
	istringstream In(str);
	while(In >> c)
	{
		P2.create(c);
	}
	P2.display();
	cout << "\n";

	result = intersect(P1, P2);
	result.display();
	cout << "\n";
}
poly intersect(poly p1, poly p2)
{
	poly result;
	node * ptr1 = p1.head;
	node * ptr2;
	while(ptr1)
	{
		ptr2 = p2.head;
		while(ptr2)
		{
			if(ptr1->x == ptr2->x)
				result.create(ptr1->x);
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	return result;
}
