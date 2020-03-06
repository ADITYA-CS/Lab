#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class SinglyLinkedList
{
private:
    Node *head, *tail;
public:
    SinglyLinkedList()
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
        tail = temp;
    }
    void deleteAlternate()
    {
        Node *ptr = head;
        while(ptr && ptr->next)
        {
            Node *temp = ptr->next;
            ptr->next = temp->next;
            delete temp;
            ptr = ptr->next;
        }
    }
    void removeDuplicate()
    {
        Node *ptr1, *ptr2;
        ptr1 = head;

        while(ptr1)
        {
            ptr2 = ptr1;
            while(ptr2)
            {
                if(ptr2->next && ptr2->next->data == ptr1->data)
                {
                    Node *temp = ptr2->next;
                    ptr2->next = ptr2->next->next;
                    delete temp;
                }
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
    }
    Node * removeK(Node *head, int k)
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
    void removeK(int k)
    {
        head = removeK(head, k);
    }
    void show()
    {
        cout << "\n ";
        Node *ptr = head;
        while(ptr)
        {
            cout << ptr->data << "->";
            ptr = ptr->next;
        }
        cout << "\n";
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

int main()
{
    int n;
    SinglyLinkedList list;
    while(1)
    {
        cout << " : ";
        cin >> n;
        if(!n)
            break;
        list.insert(n);
    }
    list.show();
    int k;
    cin >> k;
    list.removeK(k);
    list.show();
}
