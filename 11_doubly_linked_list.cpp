//sorted by default
//inserted in sorted order

#include <iostream>
#include <iomanip>
using namespace std;
struct node
{
    int data;
    node *next, *prev;
};
struct head
{
    int count;
    node *first, *last;
};
class doubly_linked_list
{
    head *h;
    node *insertAt;

public:
    doubly_linked_list() {}
    ~doubly_linked_list() {}

    //create head of the list
    head *createNode()
    {
        h = new head;
        h->count = 0;
        h->first = nullptr;
        h->last = nullptr;
        return h;
    }

    //insert into the list
    bool insert(head *h, int d)
    {
        bool found = false;
        insertAt = search(h, d, found);
        if (!found)
        {
            node *temp = new node;
            temp->data = d;
            //insert at begining
            if (!insertAt)
            {

                temp->next = h->first;
                temp->prev = nullptr;

                //if list is not empty,make the first element prev pointer equal to new node inserting.
                if (h->first)
                    h->first->prev = temp;

                //else if list is empty,point head->last to the first node inserted into empty list
                else
                    h->last = temp;
                h->first = temp;
            }

            //insert at elsewhere
            else
            {

                temp->next = insertAt->next;
                temp->prev = insertAt;
                if (insertAt->next)
                    insertAt->next->prev = temp;
                else
                    h->last = temp; //same reason as above(line 56)
                insertAt->next = temp;
            }
            h->count++;
            return true;
        }
        cout << "cannot insert " << d << "... already exists " << endl;
        return false;
    }

    //search and return the pointer of node where data is to be inserted
    node *search(head *h, int d, bool &found)
    {
        if (h->count == 0 || h->first->data >= d)
        {
            if (h->first && h->first->data == d)
                found = true;
            return nullptr;
        }
        insertAt = h->first;
        while (insertAt->next)
        {
            if (insertAt->next->data < d)
                insertAt = insertAt->next;
            else if (insertAt->next->data == d)
            {
                found = true;
                break;
            }
            else
                break;
        }
        return insertAt;
    }
    bool Delete(head *h, int d)
    {
        bool found = false;
        insertAt = search(h, d, found);
        if (found)
        {
            node *deleteMe;
            if (!insertAt)
            {
                deleteMe = h->first;
                h->first = deleteMe->next;
                if (h->first)
                    h->first->prev = nullptr;
            }
            else
            {
                deleteMe = insertAt->next;
                insertAt->next = deleteMe->next;
                if (insertAt->next)
                    insertAt->next->prev = insertAt;
                else
                    h->last = insertAt;
            }
            delete deleteMe;
            h->count--;
            return true;
        }
        cout << d << " doesn't exist in list..." << endl;
        return false;
    }
    void destroyList(head *h)
    {
        while (h->first)
        {
            node *deleteMe = h->first;
            h->first = deleteMe->next;
            delete deleteMe;
        }
        delete h;
        cout << "\nlist deleted successfully\n"
             << endl;
    }
    void print(head *h)
    {
        if (h->first)
        {
            cout << setw(9) << "list: ";
            for (auto i = h->first; i != nullptr; i = i->next)
            {
                cout << i->data << " ";
            }
            cout << setw(10) << "\nreverse: ";
            for (auto i = h->last; i != nullptr; i = i->prev)
                cout << i->data << " ";
        }
        else
            cout << "list is empty" << endl;
        cout << endl;
        cout << "last data " << h->last->data << endl;
    }
};
int main()
{
    doubly_linked_list dll;
    head *list = dll.createNode();
    for (int i = 0; i < 10; i++)
    {
        dll.insert(list, -i);
        dll.insert(list, i);
    }
    dll.insert(list, 20);
    dll.insert(list, 10);
    dll.insert(list, 15);
    dll.insert(list, -12);
    dll.insert(list, -10);
    dll.insert(list, 13);
    dll.print(list);
    dll.Delete(list, 9);
    dll.Delete(list, 20);
    dll.print(list);
    for (int i = 0; i < 10; i++)
    {
        dll.Delete(list, -i);
        dll.Delete(list, i);
    }
    dll.destroyList(list);
    return 0;
}
