#include <iostream>
using namespace std;
//������������ѡ����׼����Ĭ������ߵ�������Ȼ��ֱ����Ҫ�������������ұ�������߷ֱ����м�
//�ݼ���������ֱ���ҵ��Ȼ�׼��С���󣩵�ֵ��Ȼ�󽻻�����λ�ã��������ʱ������������
//���׼�����н��������˻�׼����λ

//��Ĭ�ϻ�׼��������ߵ�����£�
//���������ұ߿�ʼ��������߿�ʼ��������������ʱֹͣλ�õ�����һ�����ڻ�׼��

//���������һ�λ����㷨����ͷ����������ֱ��low��hight�غϣ������ʱ�临�Ӷ���O(n)�����������������㷨��ʱ�临�Ӷ��뻮�ֵ������йء�
//���������ǣ�ÿ�λ�����ѡ����м���ǡ�ý���ǰ���м����ȷ֣�����log2n�˻��֣���ɵõ�����Ϊ1���ӱ������������㷨��ʱ�临�Ӷ�ΪO(nlog2n)��
//�������ǣ�ÿ����ѡ���м����ǵ�ǰ�����е�������СԪ�أ���ʹ��ÿ�λ������õ��ӱ���һ��Ϊ�ձ���һ�ӱ�ĳ���Ϊԭ��ĳ���-1��
//����������Ϊn�����ݱ�Ŀ���������Ҫ����n�˻��֣�ʹ�����������㷨��ʱ�临�Ӷ�ΪO(n2)��

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