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
};


int main()
{
	poly P;
	double c, x, y, z;
	while(1)
	{
		int op;
		//cout << " Option ";
		cin >> op;
		switch(op)
		{
			case 0:
				exit(0);
			case 1:
				//cout << " : ";
				cin >> c >> x >> y >> z;
				P.create(c, x, y, z);
				break;	
			case 2:
				cout << " P(x, y, z) = "; P.display(); break;
			case 3:
				//cout << " : ";
				cin >> x >> y >> z;
				cout << "\n : " << P.eva(x, y, z);
				break;
		}
	}
}




