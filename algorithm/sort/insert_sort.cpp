#include <iostream>
#include <vector>
using namespace std;
template <class T>
void insert_sort(vector<T> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        T temp = v[i];
        int j = i - 1;
        while (j >= 0 && temp < v[j])
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = temp;
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
    insert_sort(v);
    cout << "\n"
         << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    system("pause");
    return 0;
}