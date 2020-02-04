#include <iostream>
using namespace std;

class integer
{
private:
	int x;
public:
	integer()
	{
		x = 0;
	}
	integer(int y)
	{
		x = y;
	}
	integer operator+(integer i2)
	{
		integer temp;
		temp.x = x + i2.x;
		return temp;
	}
	integer operator++()
	{
		x++;
		return *this;
	}
	integer operator++(int y)
	{
		x++;
		return *this;
	}
	integer operator+=(integer i2)
	{
		x += i2.x;
		return *this;
	}
	integer operator=(integer i2)
	{
		x = i2.x;
		return *this;
	}
	void show()
	{
		cout << " x = " << x <<" \n";
	}
};

int main()
{
	integer i1(10), i2(11);
	i1.show(), i2.show();
	(i1 + i2).show();
	(i1 + ++i2).show();
	i1.show();i2.show();
	(i1++ + i2).show();
	i1.show();
}
