#include <iostream>
#include <string>
using namespace std;

// structure of a node

struct node
{
    int data;
    node *link;
};

// head of the stack

struct head
{
    int count;
    node *top;
};

// Stack class

class Stack
{
    head *h;

public:
    Stack()
    {
        h = new head;
        h->count = 0;
        h->top = nullptr;
    }
    bool push(int d)
    {

        if (node *temp = new node)
        {
            temp->link = h->top;
            h->top = temp;
            temp->data = d;
            h->count++;
            return true;
        }
        return false;
    }
    bool pop()
    {
        if (h->count == 0)
            return false;
        node *pop = h->top;
        h->top = h->top->link;
        delete pop;
        h->count--;
        return true;
    }
    int size()
    {
        return h->count;
    }
    string print()
    {
        string s;
        for (auto i = h->top; i != nullptr; i = i->link)
            s += " -> " + to_string(i->data);
        return "stack" + s;
    }
    ~Stack()
    {
        while (h->top)
        {
            auto deleteMe = h->top;
            h->top = h->top->link;
            delete deleteMe;
        }
        delete h;
    }
};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    cout << s.size() << endl;
    s.push(4);
    cout << s.print() << endl;
    s.pop();
    cout << s.size() << endl;
    cout << s.print() << endl;
    return 0;
}