#include <iostream>
using namespace std;

void reverse(int A[], int lo, int hi)
{
    if (lo >= hi)
        return;

    int temp = A[lo];
    A[lo] = A[hi];
    A[hi] = temp;
    reverse(A, lo + 1, hi - 1);
}

int main()
{
    int a[10];
    for (int i = 0; i < 10; i++)
        a[i] = i;
    reverse(a, 0, 9);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;

    system("pause");
    return 0;
}