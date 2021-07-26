#include <iostream>
using namespace std;
//���Ա�0������Ԫ����ɵ���������
//���Ա��е�һ��Ԫ�ؿ����ɶ�����������

//���Ա��˳��洢
const int max_size = 20; //�洢�ռ��ʼ����
typedef int elemtype;    //�ٶ��洢Ԫ������Ϊ����
typedef int Status;      //Status�Ǻ��������ͣ���ֵΪOK��״̬��������һ��������״̬�������÷��ز�����
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
class List
{
private:
    elemtype data[max_size]; //�������
    int length;              //��ǰ����
public:
    List();
    Status getelem(int i, elemtype *e);
    Status insert(int i, elemtype e);
    Status delete_(int i, elemtype *e);
    void quick_sort(int left, int right);
    void create();
    void print();
    int getlength() const;
};

int main()
{
    List l;
    l.create();
    cout<<"\n\n";
    l.print();
    cout<<"\n\n";
    l.quick_sort(0,l.getlength()-1);
    cout<<"\n\n";
    l.print();
    system("pause");
    return 0;
}

List::List()
{
    length = 0;
}

Status List::getelem(int i, elemtype *e)
{
    if (length == 0 || i < 1 || i > length)
        return ERROR;
    *e = data[i - 1];
    return OK;
}

Status List::insert(int i, elemtype e)
{
    if (length == max_size)
        return ERROR;
    if (i < 1 || i > length + 1)
        return ERROR;
    for (int k = length; k > i - 1; k--)
        data[k] = data[k - 1];
    data[i - 1] = e;
    length++;
    return OK;
}

Status List::delete_(int i, elemtype *e)
{
    if (length == 0 || i < 1 || i > length)
        return ERROR;
    *e = data[i - 1];
    if (i != length)
        for (int k = i - 1; k < length - 1; k++)
            data[k] = data[k + 1];
    length--;
    return OK;
}

void List::quick_sort(int left, int right)
{
    if (left >= right)
        return;
    int i = left;
    int j = right;
    int temp;
    while (i != j)
    {
        while (data[j] >= data[left] && i <j)
            j--;
        while (data[i] <= data[left] && i <j)
            i++;

        temp = data[j];
        data[j] = data[i];
        data[i] = temp;
    }

    temp = data[i];
    data[i] = data[left];
    data[left] = temp;

    quick_sort(left,i-1);
    quick_sort(i+1,right);
}

void List::create()
{
    int x;
    int i = 0;
    while (cin >> x)
    {
        data[i++] = x;
        length++;
        cin.clear();
    }
}

void List::print()
{
    for (int i = 0; i < length; i++)
        cout << data[i] << " ";
}

int List::getlength() const
{
    return length;
}
