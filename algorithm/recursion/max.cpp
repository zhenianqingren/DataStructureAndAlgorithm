#include <iostream>
using namespace std;

void max(int A[], int lo, int hi, int &x1, int &x2)
{
    if (lo + 1 == hi)
    {
        x1 = A[lo] > A[hi] ? lo : hi;
        x2 = A[lo] > A[hi] ? hi : lo;
        return;
    }
    if (lo == hi)
    {
        x1 = x2 = lo;
        return;
    }
    int x1L, x2L;
    int mi = (lo + hi) / 2;
    max(A, lo, mi, x1L, x2L);
    int x1R, x2R;
    max(A, mi + 1, hi, x1R, x2R);
    if (x1L > x1R)
    {
        x1 = x1L;
        x2 = A[x2L] > A[x1R] ? x2L : x1R;
        if (x1 == x2)
            x2 = x1R;
    }
    else
    {
        x1 = x1R;
        x2 = A[x1L] > A[x2R] ? x1L : x2R;
        if (x1 == x2)
            x2 = x1L;
    }
}

int main()
{
    int a[] = {10,10};
    int x1, x2;
    max(a, 0,1, x1, x2);
    cout << a[x1] << "  " << a[x2] << endl;

    system("pause");
    return 0;
}