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
    char popped;

public:
    Stack()
    {
        h = new head;
        h->count = 0;
        h->top = nullptr;
    }
    char peek()
    {
        return h->top->data;
    }

    // push into stack (char converts to int)

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
    char pop()
    {
        node *pop = h->top;
        h->top = h->top->link;
        popped = pop->data;
        delete pop;
        h->count--;
        return popped;
    }
    bool isEmpty()
    {
        if (h->count == 0)
            return true;
        return false;
    }
    ~Stack()
    {
        while (h->top)
        {
            auto *deleteMe = h->top;
            h->top = h->top->link;
            delete deleteMe;
        }
    }
};
class conversion
{
    string postfix{""};
    Stack s;
    struct invalidOperator
    {
    };

public:
    int8_t priority(char ch)
    {
        switch (ch)
        {
        case '^':
            return 3;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '+':
        case '-':
            return 1;
            break;
        case '(':
            return 0;
        }
        return -1;
    }
    bool isOperator(char ch)
    {
        try
        {
            if (ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '^')
                return true;
            else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
                return false;
            else
                throw invalidOperator();
        }
        catch (...)
        {
            if (ch == '(')
            {
                cout << R"*(no matching ')' found)*" << endl;
            }
            else
                cout << "invalid operator..." << ch << "\nterminating.." << endl;
            exit(1);
        }
    }
    string &infix_to_postfix(string &infix)
    {
        char popped;
        bool foundOperator = false;
        for (auto x : infix)
        {
            if (x == '(')
                s.push(x);
            else if (x == ')')
            {
                if (!s.isEmpty())
                    popped = s.pop();
                while (popped != '(' && !s.isEmpty())
                {
                    postfix += popped;
                    popped = s.pop();
                }
                if (popped != '(')
                {
                    cout << R"*(no matching '(' found)*" << endl;
                    exit(1);
                }
            }
            else
            {
                if (!isOperator(x))
                {
                    postfix += x;
                }
                else
                {
                    foundOperator = true;
                    while (!s.isEmpty() && priority(s.peek()) >= priority(x))
                    {
                        postfix += s.pop();
                    }
                    s.push(x);
                }
            }
        }
        while (!s.isEmpty())
        {
            popped = s.pop();
            postfix += popped;
        }
        if (!foundOperator)
        {
            cout << "no operation found in expression" << endl;
            exit(1);
        }
        return postfix;
    }

    //evaluate postfix
    int evaluate_postfix()
    {
        int op1, op2;
        for (int x : postfix)
        {

            if (!isOperator(x))
            {
                x = x - '0';
                s.push(x);
            }
            else
            {
                op1 = s.pop();
                op2 = s.pop();
                switch (x)
                {
                case '^':
                    s.push(op1 ^ op2);
                    break;
                case '*':
                    s.push(op1 * op2);
                    break;
                case '/':
                    s.push(op2 / op1);
                    break;
                case '+':
                    s.push(op1 + op2);
                    break;
                case '-':
                    s.push(op2 - op1);
                    break;
                default:
                    cout << "invalid operator..terminated" << endl;
                }
            }
        }
        return s.pop();
    }
};

int main()
{
    conversion convert;
    string infix{""};
    cout << "infix string ";
    cin >> infix;
    auto postfix = convert.infix_to_postfix(infix);
    cout << postfix << endl;
    int res = convert.evaluate_postfix();
    cout << res;
    return 0;
}