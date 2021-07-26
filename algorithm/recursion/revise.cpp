#include <iostream>
#include <stack>
using namespace std;

int Fact(int n)
{
    if (n == 1)
        return 1;
    else
        return n * Fact(n - 1);
}
int test1(int M, int N)
{
    if (N == 0)
        return M;

    else
        return test1(N, M % N);
}
void P(int n)
{
    if (n > 0)
    {
        cout << n;
        P(n - 1);
        P(n - 1);
    }
}
void P_(int n)
{
    int s[100];
    int top = -1;
L0:
    if (n > 0)
    {
        cout << n;
        s[++top] = n;
        n--;
        goto L0;
    L1:
        n--;
        goto L0;
    L2:;
    }
    if (top != -1)
    {
        n = s[top--];
        goto L1;
    }
}
void p(int n)
{
    if (n > 0)
    {
        cout << n;
        p(n - 1);
        cout << n;
    }
}
void p_(int n)
{
    int s[50];
    int top = -1;
L0:
    if (n > 0)
    {
        cout << n;
        s[++top] = n;
        n--;
        goto L0;
    L1:
        cout << n;
    }
    if (top != -1)
    {
        n = s[top--];
        goto L1;
    }
}

void O(int n)
{
    if (n > 0)
    {
        O(n - 1);
        cout << n;
        O(n - 1);
    }
}
void O_(int n)
{
    int s[50];
    int top = -1;
L0:
    if (n > 0)
    {
        s[++top] = n;
        n--;
        goto L0;
    L1:
        cout << n;
    L2:
        n--;
        goto L0;
    }
    if (top != -1)
    {
        n = s[top--];
        goto L1;
    }
}
int main()
{
    O(3);
    cout << endl;
    O_(3);
    system("pause");
    return 0;
}