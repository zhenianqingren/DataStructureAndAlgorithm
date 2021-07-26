#include <iostream>
#include <vector>
using namespace std;
template <class T>
struct N
{
    T key;
};
template <class T>
struct dictionary
{
    T max;
    int length;
    int index;
};

template <class T>
int block_search(vector<N<T>> &v, T k)
{
        vector<dictionary<T>> d;
    int count = 0;
    T temp_max = 0;
    int index;
    for (int i = 0; i < v.size(); i++)
    {
        if (temp_max < v[i].key)
        {
            temp_max = v[i].key;
            index = i;
        }
        count++;
        if (count == 6)
        {
            d.push_back(dictionary<T>{temp_max, 6, index});
            temp_max = count = 0;
        }
    }
    if (count != 0)
        d.push_back(dictionary<T>{temp_max, count, index});
    for (int i = 0; i < d.size() - 1; i++)
        for (int j = 0; j < d.size() - 1 - i; j++)
            if (d[j].max > d[j + 1].max)
            {
                dictionary<T> temp = d[j];
                d[j] = d[j + 1];
                d[j + 1] = temp;
            }
    for (int i = 0; i < d.size(); i++)
        cout << d[i].max << " " << d[i].length << " " << d[i].index << endl;

    int in;
    for (int i = 0; i < d.size(); i++)
        if (k <= d[i].max)
        {
            in = d[i].index;
            break;
        }
    for (int i = in; i < v.size(); i++)
        if (v[i].key == k)
            return i;
    return -1;
}
int main()
{
    vector<N<int>> v;
    for (int i = 0; i < 12; i++)
        v.push_back(N<int>{i});
    cout << block_search(v, 5);
    cout << endl;
    system("pause");
    return 0;
}