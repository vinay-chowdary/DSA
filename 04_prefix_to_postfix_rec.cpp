#include "iostream"
#include "string"
using namespace std;
int isOperator(char ch)
{
    switch (ch)
    {
    case '*':
    case '-':
    case '+':
    case '/':
        return 1;
    }
    return 0;
}
int findexLen(string Ex)
{
    int len1 = 0, len2 = 0;
    cout << Ex << endl;
    if (isOperator(Ex[0]))
    {
        len1 = findexLen(Ex.substr(1));
        len2 = findexLen(Ex.substr(len1));
    }
    cout << len1 + len2 + 1 << endl;
    return len1 + len2 + 1;
}
void preTopos(string preEx, string &posEx)
{
    if (preEx.length() == 1)
    {
        posEx = preEx;
    }
    else
    {
        char op = preEx[0];
        // cout << preEx.substr(1);
        int exLen = findexLen(preEx.substr(1));
        // cout << exLen << endl;
        string temp = preEx.substr(1, exLen);
        string posEx1, posEx2;
        preTopos(temp, posEx1);
        temp = preEx.substr(exLen + 1);
        preTopos(temp, posEx2);
        posEx = posEx1 + posEx2 + op;
    }
}
int main()
{
    string preEx, posEx;
    cin >> preEx;
    preTopos(preEx, posEx);
    cout << posEx << endl;
    return 0;
}