#include <iostream>
using namespace std;

void towers(int numberOfDisks, char s, char d, char a)
{
    if (numberOfDisks == 1)
        cout << "move disk from " << s << " to " << d << endl;
    else
    {
        towers(numberOfDisks - 1, s, a, d);
        cout << "move disk from " << s << " to " << d << endl;
        towers(numberOfDisks - 1, a, d, s);
    }
}
int main()
{
    int a = 0, b = 1, c = 2;
    towers(2, 's', 'd', 'a');
    return 0;
}