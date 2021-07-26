#include <iostream>
using namespace std;
//快速排序，首先选定基准数（默认最左边的数），然后分别从所要排序的数组的最右边与最左边分别向中间
//递减（增），直到找到比基准数小（大）的值，然后交换二者位置，最后相遇时，将相遇数字
//与基准数进行交换，至此基准数归位

//（默认基准数在最左边的情况下）
//排序必须从右边开始，若从左边开始，则最后二者相遇时停止位置的数字一定大于基准数

//快速排序的一次划分算法从两头交替搜索，直到low和hight重合，因此其时间复杂度是O(n)；而整个快速排序算法的时间复杂度与划分的趟数有关。
//理想的情况是，每次划分所选择的中间数恰好将当前序列几乎等分，经过log2n趟划分，便可得到长度为1的子表。这样，整个算法的时间复杂度为O(nlog2n)。
//最坏的情况是，每次所选的中间数是当前序列中的最大或最小元素，这使得每次划分所得的子表中一个为空表，另一子表的长度为原表的长度-1。
//这样，长度为n的数据表的快速排序需要经过n趟划分，使得整个排序算法的时间复杂度为O(n2)。

/*int arr[] = {3, 7, 101, 55, 12, 88, 9, 6, 5, 4, 21};

void quick_sort(int left, int right)
{
    if (left > right)
        return;

    int temp = arr[left];
    int i = left, j = right;
    int t;
    while (i != j)
    {
        while (arr[j] >=temp && i < j)
            j--;
        while (arr[i] <=temp && i < j)
            i++;

        t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    t = arr[i];
    arr[i] = arr[left];
    arr[left] = t;

    quick_sort(left, i - 1);
    quick_sort(i + 1, right);
}*/

void practice(int *arr, int left, int right)
{
    if (left > right)
        return;

    int i = left, j = right, temp = arr[left];
    int t;
    while (i != j)
    {
        while (arr[j] >=temp && i < j)
            j--;
        while (arr[i] <=temp && i < j)
            i++;

        t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    t = arr[i];
    arr[i] = temp;
    arr[left] = t;

    practice(arr, left, i - 1);
    practice(arr, i + 1, right);
}
int main()
{
    /* quick_sort(0, 10);
    for (int i = 0; i < 11; i++)
        cout << arr[i] << " ";
    cout << endl;*/

    int *arr;

    int n, number, sum = 0;
    bool judge = true;
    cin >> n;

    arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> number;
        for (int j = 0; j < n; j++)
            if (arr[j] == number)
            {
                judge = false;
                break;
            }
        if (judge)
            arr[i] = number;
        if (arr[i] != 0)
            sum++;
        judge = true;
    }

    int *sort = new int[sum];
    for (int i = 0, j = 0; i < n; i++)
        if (arr[i] != 0)
            sort[j++] = arr[i];

    practice(sort, 0, sum - 1);

    for (int i = 0; i < sum; i++)
        cout << sort[i] << " ";
    system("pause");
    return 0;
}