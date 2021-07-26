#include<iostream>
#include<vector>
using namespace std;
#define N node<T>
template<class T>
class node
{
    T key;
};
template<class T>
int Search_inorder(vector<N>&v,T k)
{
    int i;
    for(i=v.size()-1;v[i].key!=k&&i>=0;i--);
    return i;
}

template<class T>
int Search_inorder_(vector<N>&v,T k)
{
    v[0]=k;//要求存储数据的线性表第一个位置没有元素
    int i;
    for(i=v.size();v[i].key!=k;i--);//少比较一次i>=0
    return i;
}


int main()
{
    system("pause");
    return 0;
}