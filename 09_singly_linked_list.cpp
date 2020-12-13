#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
struct head
{
    int count;
    node *first;
};
class singly_linked_list
{
private:
    head *h;
    node *insertAt;

public:
    singly_linked_list() {}
    ~singly_linked_list() {}
    void destroyList(head *headNode)
    {
        while (headNode->first)
        {
            node *deleteMe = headNode->first;
            headNode->first = deleteMe->next;
            delete deleteMe;
        }
        delete h;
    }
    head *createNode()
    {
        h = new head;
        h->count = 0;
        h->first = nullptr;
        return h;
    }
    bool insert(head *headNode, int data)
    {
        bool found = false;
        insertAt = search(headNode, data, found);
        if (!found)
        {
            node *temp = new node;
            temp->data = data;
            if (!insertAt)
            {
                temp->next = headNode->first;
                headNode->first = temp;
            }
            else
            {

                temp->next = insertAt->next;
                insertAt->next = temp;
            }
            headNode->count++;
        }

        else
            cout << "cannot insert " << data << "... already exists " << endl;
        return true;
    }

    bool Delete(head *headNode, int data)
    {

        node *deleteMe;
        bool found = false;
        insertAt = search(headNode, data, found);
        if (found)
        {
            if (!insertAt)
            {
                deleteMe = headNode->first;
                headNode->first = deleteMe->next;
            }
            else
            {

                deleteMe = insertAt->next;
                insertAt->next = deleteMe->next;
            }
            delete deleteMe;
        }
        else
        {
            cout << data << " data not found.." << endl;
        }

        return true;
    }

    node *search(head *headNode, int data, bool &found)
    {
        insertAt = headNode->first;
        if (headNode->count == 0 || headNode->first->data >= data)
        {
            if (headNode->first && data == headNode->first->data)
                found = true;
            return nullptr;
        }
        while (insertAt->next)
        {
            if (insertAt->next->data < data)
                insertAt = insertAt->next;
            else if (insertAt->next->data == data)
            {
                found = true;
                break;
            }
            else
                break;
        }
        return insertAt;
    }
    void print(head *headNode)
    {
        if (headNode->first)
        {
            cout << "list: " << endl;
            for (auto i = headNode->first; i != nullptr; i = i->next)
                cout << i->data << endl;
        }
        else
            cout << "list is empty" << endl;
    }
};
int main()
{
    singly_linked_list sll;
    head *list = sll.createNode();
    for (int i = 0; i < 10; i++)
        sll.insert(list, i);

    sll.print(list);
    sll.destroyList(list);
    return 0;
}