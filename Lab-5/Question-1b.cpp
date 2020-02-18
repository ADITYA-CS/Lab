#include <iostream>
#include <cmath>
using namespace std;

struct node 
{
	double x, y, z, c;
	node * next;
	node(double a, double b, double d, double e)
	{
		c = a;
		x = b;
		y = d;
		z = e;
		next = NULL;
	}
};

class poly
{
private:
	node *head, *tail;
	double evaL(node *head, double x, double y, double z)
	{
		if(head)
		{
			return head->c * pow(x, head->x) * pow(y, head->y) * pow(z, head->z) +  evaL(head->next, x, y, z);
		}		
	}
public:
	poly()
	{
		head = tail = NULL;	
	}
	void create(double a, double b, double c, double d)
	{
		node * temp = new node(a, b, c, d);
		if(!head)
		{
			head = tail = temp;
			return;
		}
		tail->next = temp;
		tail = temp;
	}
	double eva(double x, double y, double z)
	{
		return evaL(head, x, y, z);
	}
	void display()
	{
		node * temp = head;
		while(temp)
		{
			cout << temp->c << "x^" << temp->x << "y^" << temp->y << "z^" << temp->z << " ";
			if(temp->next)
				cout << "+ ";
			else
				cout << "\n";
			temp = temp->next;
		}
	}
	void sumPoly(poly P2, poly &result)
	{
		node * temp = head;
		node * temp2 = P2.head;
		while(temp)
		{
			result.create(temp->c + temp2->c, temp->x, temp->y, temp->z);
			temp = temp->next;
			temp2 = temp2->next;
		}
	}
};


int main()
{
	poly P1, P2, result;
	double c, x, y, z;
	cin >> c >> x >> y >> z;
	P1.create(c, x, y, z);
	cin >> c >> x >> y >> z;
	P1.create(c, x, y, z);
	cin >> c >> x >> y >> z;
	P1.create(c, x, y, z);
	cin >> c >> x >> y >> z;
	P1.create(c, x, y, z);
	cin >> c >> x >> y >> z;
	P1.create(c, x, y, z);
	cin >> c >> x >> y >> z;
	P2.create(c, x, y, z);
	cin >> c >> x >> y >> z;
	P2.create(c, x, y, z);
	cin >> c >> x >> y >> z;
	P2.create(c, x, y, z);
	cin >> c >> x >> y >> z;
	P2.create(c, x, y, z);
	cin >> c >> x >> y >> z;
	P2.create(c, x, y, z);
	P1.sumPoly(P2, result);
	P1.display();
	P2.display();
	result.display();
}




