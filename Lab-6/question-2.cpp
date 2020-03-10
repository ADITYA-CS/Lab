#include <iostream>
using namespace std;

class CircularQueue
{
private:
 	int size_;
	int *array_;
	int front_, rare_;
public:
	CircularQueue(int n);
	bool full();
	bool empty();
	void display();
	void enqueue_front(int n);
	void enqueue_rare(int n);
	void dequeue_front();
	void dequeue_rare();
};

int main()
{
	int n;
	cout << " Size of queue ";
	cin >> n;
	CircularQueue cq(n);
	
	int op;
	while(1)
	{
		cout << " 0. Exit\n 1. Full\n 2. Empty\n 3. Display\n 4. Enqueue at front\n 5. Enqueue at end\n 6. Dequeue from front\n 7. Dequeue from rare\n";
		cout << " Option : ";
		cin >> op;

		switch(op)
		{
			case 0:
				exit(0);
			case 1:
				if(cq.full())
					cout << " Queue is full\n";
				else
					cout << " Queue is not full\n";
				break;
			case 2:
				if(cq.empty())
					cout << " Queue is empty\n";
				else
					cout << " Queue is not empty\n";
				break;	
			case 3:
				cq.display();
				break;
			case 4:
				cout << " Data to insert : ";
				cin >> n;
				cq.enqueue_front(n);
				break;
			case 5:
				cout << " Data to insert : ";
				cin >> n;
				cq.enqueue_rare(n);
				break;
			case 6:
				cq.dequeue_front();
				break;
			case 7:
				cq.dequeue_rare();
				break;
		}
	}
}
CircularQueue :: CircularQueue(int n)
{
	size_ = n;
	array_ = new int[n];
	front_ = rare_ = -1; 	
}

bool CircularQueue :: full()
{
	return (rare_ + 1)%size_ == front_;
}
bool CircularQueue :: empty()
{
	return front_ == -1;
}

void CircularQueue :: display()
{
	if(empty())
	{
		cout << " Queue is empty.\n";
		return;
	}
	if(rare_ >= front_)
	{
		for(int i = front_; i <= rare_; i++)
		{
			cout << array_[i] << " ";
		}
		cout << "\n";
		return;
	}
	for(int i = front_; i < size_; i++)
	{
		cout << array_[i] << " ";
	}
	for(int i = 0; i <= rare_; i++)
	{
		cout << array_[i] << " ";
	}
	cout << "\n";
}

void CircularQueue :: enqueue_front(int n)
{
	if(full())
	{
		cout << " Queue is Full.\n";
		return;
	}
	if(front_ == -1)
	{
		front_++, rare_++;
		array_[front_] = n;
		return;
	}
	front_ = front_ == 0 ? size_ - 1 : front_ - 1;
	array_[front_] = n;
}
void CircularQueue :: enqueue_rare(int n)
{
	if(full())
	{
		cout << " Queue is Full.\n";
		return;
	}
	if(front_ == -1)
	{
		front_++, rare_++;
		array_[front_] = n;
		return;	
	}
	rare_ = (rare_ + 1) % size_;
	array_[rare_] = n;
}

void CircularQueue :: dequeue_front()
{
	if(empty())
	{
		cout << " Queue is empty.\n";
		return;
	}
	if(rare_ == front_)
	{
		rare_ = front_ = -1;
		return;
	}
	front_ = (front_ + 1) % size_;
}
void CircularQueue :: dequeue_rare()
{
	if(empty())
	{
		cout << " Queue is empty.\n";
		return;
	}
	if(rare_ == front_)
	{
		rare_ = front_ = -1;
		return;
	}
	rare_ = rare_ == 0 ? size_ - 1 : rare_ - 1;
}

















