#include <iostream>
#include <vector>
using namespace std;
template <class T>
void select_sort(vector<T> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < v.size(); j++)
            if (v[j] < v[min])
                min = j;
        if (i != min)
        {
            v[i] = v[min] + v[i];
            v[min] = v[i] - v[min];
            v[i] = v[i] - v[min];
        }
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
    select_sort(v);
    cout << "\n"
         << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    system("pause");
    return 0;
}