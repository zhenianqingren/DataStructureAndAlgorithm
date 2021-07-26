#include <iostream>
#include <vector>
using namespace std;
#define N node<T>
template <class T>
struct node
{
    T key;
};
template <class T>
int binary_Search(vector<N> &v, T k)
{
    int lo = 0;
    int hi = v.size() - 1;
    int mid;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (v[mid].key > k)
            hi = mid - 1;
        else if (v[mid].key < k)
            lo = mid + 1;
        else
            return mid;
    }
    return -1;
}
template <class T>
int binary_Search_(vector<N> &v, T k, int lo, int hi)
{
    if (lo > hi)
        return -1;
    int mid = (lo + hi)/2;
    if (v[mid].key == k)
        return mid;
    else if (v[mid].key < k)
        binary_Search_(v, k, mid + 1, hi);
    else if (v[mid].key > k)
        binary_Search_(v, k, lo, mid - 1);
}
int main()
{
    vector<node<int>> v;
    for (int i = 0; i < 10; i++)
        v.push_back(node<int>{i});
    cout << binary_Search_(v, 6,0,v.size()-1)<<" "<<binary_Search_(v,100,0,v.size()-1);
    cout << endl;
    system("pause");
    return 0;
}