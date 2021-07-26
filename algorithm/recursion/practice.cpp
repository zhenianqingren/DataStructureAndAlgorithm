#include <iostream>
#include <stack>
using namespace std;

void P(int n)
{
    if (n > 0)
    {
        cout << n;
        P(n - 1);
        cout << n;
    }
}

void _P(int n)
{
    int b = n;
L0:
    cout << n;
    n = n - 1;
    if (n > 0)
        goto L0;

L1:
    n = n + 1;
    cout << n;
    if (n < b)
        goto L1;
}

void p(int n)
{
    if (n > 0)
    {
        p(n - 1);
        cout << n;
        p(n - 1);
    }
}

void _p(int n)
{
    stack<int> s;

L0:
    if (n != 1)
    {
        s.push(n);
        n = n - 1;
        goto L0;
    L1:
        cout << n;

        n = n - 1;
        goto L0;
    }
    else
        cout << 1;
    if (!s.empty())
    {
        n = s.top();
        s.pop();
        goto L1;
    }
}

int main()
{
    P(5);
    cout << endl;
    _P(5);
    cout << endl;
    p(7);
    cout << endl;
    _p(7);
    cout<<endl;
    system("pause");
    return 0;
}