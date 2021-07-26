#include <iostream>
using namespace std;
//桶排序
//初始化值为0
//每次接收到一个数值，对应数组的下标所储存的值便加1，代表（又）出现了一次
//最后将所有的下标打印，出现几次便打印几次

//不必拘泥于下标的值，可按照某种特定的规则，例如若要求输入大于100的值
//不必建立大型数组，可规定下标加100，代表输入值
int main()
{
    int a[16];
    int n;
    for (int i = 0; i <= 15; i++)
        a[i] = 0;
    for (int i = 0; i <= 15; i++)
    {
        cin >> n;
        a[n]++;
    }
    for (int i = 0; i <= 15; i++)
        for (int j = 1; j <= a[i]; j++)
            cout << i << " ";

    system("pause");
    return 0;
}