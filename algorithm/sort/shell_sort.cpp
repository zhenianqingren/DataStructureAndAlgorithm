#include <iostream>
#include <vector>
using namespace std;
template <class T>
void shell_sort(vector<T> &v)
{
    int d = (v.size() - 1)/2;
    while (d > 0)
    {
        for (int i = d; i < v.size(); i++)
        {
            int j = i - d;
            T temp = v[i];
            while (j >= 0 && v[j] > temp)
            {
                v[j + d] = v[j];
                j = j - d;
            }
            v[j + d] = temp;
        }
        d = d / 2;
    }
}

int main()
{
    vector<int> v;
    v.resize(20);
    for (int i = 0; i < v.size(); i++)
        v[i] = rand() % 20;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    shell_sort(v);
    cout << "\n"
         << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    system("pause");
    return 0;
}