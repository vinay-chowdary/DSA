#include <iostream>
using namespace std;
class Stack
{
    int *arr, n, count;

public:
    Stack(int n)
    {
        cout << "stack created" << endl;
        count = 0;
        this->n = n;
        arr = new int[n];
    }
    ~Stack()
    {
        delete[] arr;
        cout << "stack destroyed" << endl;
    }
    int peek()
    {
        return arr[count - 1];
    }
    bool push(int d)
    {
        if (count == n)
            return 0;
        arr[count++] = d;
        cout << d << " pushed successfully" << endl;
        return 1;
    }
    bool pop()
    {
        if (count == 0)
            return 0;
        cout << arr[count - 1] << " poped successfully" << endl;
        count--;
        return 1;
    }
    int size()
    {
        return count;
    }
    void print()
    {
        for (int i = 0; i < count; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Stack s(4);
    s.push(100);
    s.push(9);
    s.push(20);
    s.print();
    cout << s.size() << endl;
    s.pop();
    cout << s.peek() << " is at top" << endl;
    s.pop();
    s.print();
    cout << s.size() << endl;
}