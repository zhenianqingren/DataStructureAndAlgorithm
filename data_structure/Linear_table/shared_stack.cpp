#include <iostream>
using namespace std;
typedef int elemtype;
typedef int Status;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
const int max_size = 20;
//��ջ��������
//����ջ�ף�һ��λ��0����һ��λ��n-1��������Ԫ�����м俿£
//top1+1=top2��Ϊջ��

//�������������constΪ����Ա�����������޸����ݳ�Ա���ܶԳ����ݳ�Ա���в���
//������ֻ�ܵ��ó���Ա����

//��̬��Ա����static ��thisָ��
//ֻ�ܵ��þ�̬���ݳ�Ա
//������Ϊһ��ָ�����ж��������
class myStack
{
public:
    int top1;
    int top2;
    elemtype data[max_size];

    myStack();
    Status push(elemtype e, int stacktype); //stacktypeΪ1��ջ1ѹ�룬stacktypeΪ2��ջ2ѹ��
    Status pop(elemtype*e,int stacktype);
};

int main()
{
    getchar();
    return 0;
}

myStack::myStack()
{
    top1 = -1;
    top2 = max_size;
}

Status myStack::push(elemtype e, int stacktype)
{
    if (top1 + 1 == top2) //�ж�ջ�Ƿ�Ϊ��
        return ERROR;
    if (stacktype == 1)
        data[++top1] = e;
    else if (stacktype == 2)
        data[--top2] = e;
    return OK;
}

Status myStack::pop(elemtype*e,int stacktype)
{
    if(stacktype==1)
    {
        if(top1==-1)
        return ERROR;
        *e=data[top1--];
    }
    else if(stacktype==2)
    {
        if(top2==max_size)
        return ERROR;
        *e=data[top2++];
    }
    return OK;
}