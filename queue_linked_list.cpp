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
class Queue
{
private:
    head *h;
    node *temp;
    union Union {
        char ch;
        bool b;
    } u;

public:
    Queue()
    {
        h = new head;
        h->count = 0;
        h->front = nullptr;
        h->rear = nullptr;
    }
    ~Queue()
    {
        while (h->front)
        {
            auto deleteme = h->front;
            h->front = h->front->next;
            delete deleteme;
        }
        delete h;
    }
    bool enqueue(int d)
    {
        if (temp = new node)
        {
            temp->data = d;
            temp->next = nullptr;
            if (h->count == 0)
                h->front = temp;
            else
                h->rear->next = temp;
            h->rear = temp;
            h->count++;
            return true;
        }
        return false;
    }
    Union dequeue()
    {
        if (h->count == 0)
        {
            cout << "queue is empty" << endl;
            u.b = false;
            return u;
        }
        u.ch = h->front->data;
        auto dequeueMe = h->front;
        h->front = dequeueMe->next;
        h->count--;
        return u;
    }

    //if functions(qFront(),qRear()) are not declared constant they cannot be called from a const function(print())
    int qFront() const
    {
        return h->front->data;
    }
    int qRear() const
    {
        return h->rear->data;
    }
    void print() const
    {
        cout << "count " << h->count << endl;
        for (auto i = h->front; i != nullptr; i = i->next)
            cout << i->data << endl;

        cout << "front " << qFront() << " "
             << "rear " << qRear() << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.print();

    return 0;
}