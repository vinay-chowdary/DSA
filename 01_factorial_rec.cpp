#include "iostream"
using namespace std;

// recursion

long rec_fact(int n)
{
    if (n == 1)
        return 1;
    return n * rec_fact(n - 1);
}
int main()
{
    int n;
    cout << "enter number: ";
    cin >> n;
    cout << rec_fact(10) << "\n";
    return 0;
}

// loop

// long iter_fact(int n)
// {
//     long fact = 1;
//     for (int i = n; i > 1; i--)
//     {
//         fact = fact * i;
//     }
//     return fact;
// }