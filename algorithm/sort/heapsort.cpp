#include <iostream>
#include <vector>
using namespace std;
void sift(vector<int> &v, int k, int n)
{
    int x = v[k];
    bool finished = false;
    int i = k, j = 2 * k;
    while (j <= n && !finished)
    {
        if (j < n && v[j] < v[j + 1])
            j++;
        if (x > v[j])
            finished = true;
        else
        {
            v[i] = v[j];
            i = j;
            j = 2 * j;
        }
    }
    v[i] = x;
}
void heap_sort(vector<int> &v, int n)
{
    for (int i = n / 2; i >= 1; i--)
        sift(v, i, n);
    for (int i = n; i >= 2; i--)
    {
        int temp = v[1];
        v[1] = v[i];
        v[i] = temp;
        sift(v, 1, i - 1);
    }
}
int main()
{
    vector<int> v;
    srand(10);
    for (int i = 0; i < 11; i++)
    {
        v.push_back(rand() % 100);
        v[0]=-1;
        cout << v[i] << " ";
    }
    cout << endl;
    heap_sort(v, 10);
    for (int i = 0; i < 11; i++)
        cout << v[i] << " ";
    system("pause");
    return 0;
}