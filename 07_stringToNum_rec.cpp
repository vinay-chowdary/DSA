#include <iostream>
#include <string>
using namespace std;

//tail recursion

void stringToNum(string s, int &num)
{
    if (s.length() == 0)
        return;
    num = num * 10 + (s[0] - '0');
    return stringToNum(s.substr(1), num);
}

int main()
{
    string s;
    cin >> s;
    int num{0};
    stringToNum(s, num);
    cout << num;
    return 0;
}