#include <iostream>
using namespace std;

void subset(int a[], bool b[], int n, int step)
{
    if (step == n)
    {
        for (int i = 0; i < n; i++)
            if (b[i])
                cout << a[i] << " ";
        cout << endl;
    }

    else
    {
        b[step] = true;
        subset(a, b, n, step + 1);
        b[step] = false;
        subset(a, b, n, step + 1);
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    bool b[9];
    subset(a, b, 9, 0);
    system("pause");
    return 0;
}