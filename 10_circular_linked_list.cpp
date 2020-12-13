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
    node *front;
    node *rear;
};
class circular_linked_list
{
private:
    head *h;
    node *insertAt;

public:
    circular_linked_list() {}
    ~circular_linked_list() {}
    head *createNode()
    {
        h = new head;
        h->count = 0;
        h->front = nullptr;
        h->rear = nullptr;
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
                if (h->count == 0)
                {
                    temp->next = temp;
                    headNode->rear = temp;
                }
                else
                {
                    temp->next = headNode->front;
                    headNode->rear->next = temp;
                }
                headNode->front = temp;
            }
            else
            {
                if (insertAt == headNode->rear)
                    headNode->rear = temp;
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

        bool found = false;
        insertAt = search(headNode, data, found);
        if (found)
        {
            node *deleteMe;
            if (!insertAt)
            {
                deleteMe = headNode->front;

                //delete last element to make list empty
                if (headNode->front == headNode->rear)
                    deleteMe->next = nullptr;

                headNode->front = deleteMe->next;
                headNode->rear->next = headNode->front;
            }
            else
            {
                if (insertAt->next == headNode->rear)
                    headNode->rear = insertAt;
                deleteMe = insertAt->next;
                insertAt->next = deleteMe->next;
            }
            delete deleteMe;
            headNode->count--;
        }
        else
        {
            cout << data << " data not found.." << endl;
        }

        return true;
    }

    node *search(head *headNode, int data, bool &found)
    {
        if (headNode->count == 0 || headNode->front->data >= data)
        {
            if (headNode->front && data == headNode->front->data)
                found = true;
            return nullptr;
        }
        insertAt = headNode->front;
        while (insertAt->next != headNode->front)
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
    void destroyList(head *headNode)
    {
        if (headNode->front)

            while (headNode->count)
            {
                node *deleteMe = headNode->front;
                headNode->front = deleteMe->next;
                delete deleteMe;
                headNode->count--;
            }
        delete h;
    }
    void print(head *headNode)
    {
        auto i = headNode->front;
        if (i)
        {
            cout << "no.of elements: " << headNode->count << endl;
            cout << "list: ";
            do
            {
                cout << i->data << " ";
                i = i->next;
            } while (i != headNode->front);
            cout << i->data << endl;
            cout << "rear " << headNode->rear->data << endl;
        }
        else
            cout << "list is empty" << endl;
    }
};
int main()
{
    circular_linked_list sll;
    head *list = sll.createNode();
    sll.insert(list, -1);
    sll.insert(list, 20);
    sll.insert(list, 10);
    sll.insert(list, -2);
    sll.print(list);
    sll.destroyList(list);
    return 0;
}