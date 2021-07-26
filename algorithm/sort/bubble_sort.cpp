#include <iostream>
using namespace std;

void bubble_sort(int a[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] < a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
}

int main()
{
    int a[] = {5, 101, 23, 7, 8, 1, 2, 0, 333, 16, 7};
    bubble_sort(a, 11);
    cout << sizeof(a) / sizeof(int) << endl;
    for (int i = 0; i < 11; i++)
        cout << a[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}