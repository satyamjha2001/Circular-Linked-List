#include <iostream>
using namespace std;
struct node
{
    int item;
    node *next;
    node(int data)
    {
        item = data;
        next = NULL;
    }
};
class CLL
{
private:
    node *last;

public:
    CLL();
    void insertAtStart(int);
    void insertAtLast(int);
    node *search(int);
    void insertAfter(node *, int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(int);
    void print();
    ~CLL();
};
CLL::CLL()
{
    last = NULL;
}
void CLL::insertAtStart(int data)
{
    node *n = new node(data);
    if (last == NULL)
    {
        last = n;
        last->next = last;
    }
    else
    {
        n->next = last->next;
        last->next = n;
    }
}
void CLL::insertAtLast(int data)
{
    node *n = new node(data);
    if (last == NULL)
    {
        last = n;
        last->next = last;
    }
    else
    {
        n->next = last->next;
        last->next = n;
        last = n;
    }
}
node *CLL::search(int data)
{
    if (last)
    {
        node *temp = last->next;
        do
        {
            if (temp->item == data)
                return temp;
            temp = temp->next;
        } while (temp != last->next);
    }
    return nullptr;
}
void CLL::insertAfter(node *temp, int data)
{
    if (temp)
    {
        node *n = new node(data);
        n->next = temp->next;
        temp->next = n;
        if (last == temp)
            last = n;
    }
}
void CLL::deleteFirst()
{
    node *temp;
    if (last)
    {
        if (last->next == last)
        {
            delete last;
            last = NULL;
        }
        else
        {
            temp = last->next;
            last->next = temp->next;
            delete temp;
        }
    }
}
void CLL::deleteLast()
{
    node *temp, *t;
    if (last)
    {
        if (last->next == last)
        {
            delete last;
            last = NULL;
        }
        else
        {
            temp = last->next;
            while (temp->next != last)
            {
                temp = temp->next;
            }
            temp->next = last->next;
            delete last;
            last = temp;
        }
    }
}
void CLL::deleteNode(int data)
{
    node *temp, *t;
    if (last)
    {
        temp = last->next;
        if (temp->item == data)
        {
            deleteFirst();
        }
        else
        {
            do
            {
                if (temp->next->item == data)
                {
                    t = temp->next;
                    temp->next = t->next;
                    if (t == last)
                        last = temp;
                    delete t;
                    break;
                }
                temp = temp->next;
            } while (temp != last->next);
        }
    }
}
void CLL::print()
{
    if (last == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    node *temp = last->next; // Point to the first node
    do
    {
        cout << temp->item << " ";
        temp = temp->next;
    } while (temp != last->next);
}
CLL::~CLL()
{
    while (last)
        deleteFirst();
}
int main()
{
    CLL c1;
    c1.insertAtStart(5);
    c1.insertAtStart(6);
    c1.insertAtLast(9);
    c1.insertAtLast(10);
    node *temp = c1.search(10);
    c1.insertAfter(temp, 12);
    // c1.deleteFirst();
    // c1.deleteLast();
    c1.deleteNode(12);
    c1.print();
    return 0;
}