#include <iostream>
using namespace std;
//静态链表
//把这种用数组描述的链表叫做静态链表，这种描述方法还有起名叫做游标实现法
const int max_size = 1000;
typedef int elemtype;
typedef int Status; //Status是函数的类型，其值为OK等状态，即返回一个操作的状态，用引用返回操作数
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
struct chain
{
    elemtype elem;
    int cur;
};

class Static
{
private:
    chain data[max_size];
    int length;

public:
    Static();
    int Malloc();
    Status Listinsert(int i, elemtype e);
    Status Dele(int i);
    void Free(int i);
};

int main()
{

    getchar();
    return 0;
}

Static::Static()
{
    for (int i = 0; i < max_size - 1; i++)
        data[i].cur = i + 1;
    data[max_size - 1].cur = 0;
    length = 0;
}

int Static::Malloc()
{
    int i = data[0].cur;
    if (data[0].cur)
        data[0].cur = data[i].cur;
    return i;
}

Status Static::Listinsert(int i, elemtype e)
{
    if (i < 1 || i > length)
        return ERROR;

    int j = Malloc();
    int k = max_size - 1;

    if (j)
    {
        data[j].elem = e;
        for (int n = 1; n <= i - 1; n++)
            k = data[k].cur;
        data[j].cur = data[k].cur;
        data[k].cur = j;
        length++;
        return OK;
    }

    return ERROR;
}

Status Static::Dele(int i)
{
    if (i < 1 || i > length)
        return ERROR;
    int k, j;
    for (j = 1; j <= i - 1; j++)
        k = data[k].cur;
    j = data[k].cur;
    data[k].cur = data[j].cur;
    return OK;
}

void Static::Free(int i)
{
    data[0].cur = i;
}

