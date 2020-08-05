#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next, *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

class DoublyLinkedList
{
private:
    Node *head, *tail;
public:
    DoublyLinkedList()
    {
        head = tail = NULL;
    }
    void insert(int x)
    {
        Node *temp = new Node(x);
        if(head == NULL)
        {
            head = tail = temp;
            return;
        }
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    void show()
    {
        Node *ptr = head;
        cout << "\n ";
        while(ptr)
        {
            cout << ptr->data << "->";
            ptr = ptr->next;
        }
        cout << "\n";
    }
    void reverse()
    {
        Node *ptr, *next, *temp;
        ptr = head;

        temp = head;
        head = tail;
        tail = temp;

        while(ptr)
        {
            next = ptr->next;
            ptr->next = ptr->prev;
            ptr->prev = next;
            ptr = next;
        }
    }
};

int main()
{
    DoublyLinkedList list;
    int n;
    while(1)
    {
        cout << " : ";
        cin >> n;
        if(!n)
            break;
        list.insert(n);
    }
    list.show();
    list.reverse();
    list.show();
}
