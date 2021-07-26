#include <iostream>
using namespace std;
int fib(int n, int &pre)
{
    if (n == 0)
        return 0;
    if (n == 1)
    {
        pre = 0;
        return 1;
    }

    int prepre;
    pre = fib(n - 1, prepre);
    return pre + prepre;
}

int main()
{

    int pre;
    for (int i = 0; i < 10; i++)
        cout << fib(i, pre) << endl;
    system("pause");
    return 0;
}