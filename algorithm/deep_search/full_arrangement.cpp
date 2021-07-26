#include <iostream>
using namespace std;

int _cout[50];
void defs(int a[], int n, bool b[], int step)
{
    if (step == n)
    {
        for (int i = 0; i < n; i++)
            cout << _cout[i] << " ";
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (b[i])
        {
            _cout[step] = a[i];
            b[i] = false;
            defs(a, n, b, step + 1);
            b[i] = true;
        }
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    bool b[5];
    for (int i = 0; i < 5; i++)
        b[i] = true;
    defs(a, 5, b, 0);
    system("pause");
    return 0;
}