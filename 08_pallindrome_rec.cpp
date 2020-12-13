#include <iostream>
#include <string>
using namespace std;

bool isPallindrome(string str)
{
    int last = str.length() - 1;
    if (last <= 0)
        return true;
    if (str[0] != str[last])
        return false;

    return isPallindrome(str.substr(1, last - 1));
}

int main()
{
    string num;
    cin >> num;
    isPallindrome(num) ? cout << "yes" : cout << "no";
    return 0;
}