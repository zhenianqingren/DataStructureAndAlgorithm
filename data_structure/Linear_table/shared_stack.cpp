#include <iostream>
using namespace std;
typedef int elemtype;
typedef int Status;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
const int max_size = 20;
//两栈共享数组
//两个栈底，一个位于0处，一个位于n-1处，增加元素向中间靠拢
//top1+1=top2即为栈满

//函数括号名后加const为常成员函数，不能修改数据成员，能对常数据成员进行操作
//常对象只能调用常成员函数

//静态成员函数static 无this指针
//只能调用静态数据成员
//可以作为一种指挥所有对象的作用
class myStack
{
public:
    int top1;
    int top2;
    elemtype data[max_size];

    myStack();
    Status push(elemtype e, int stacktype); //stacktype为1向栈1压入，stacktype为2向栈2压入
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
    if (top1 + 1 == top2) //判断栈是否为满
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