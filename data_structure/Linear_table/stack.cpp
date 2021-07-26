#include <iostream>
using namespace std;
//栈是限定仅在表尾进行插入和删除操作的线性表
//栈顶(top)进行插入和删除操作  栈底(bottom)

//栈的顺序存储结构
//栈的合法输出序列，一个数字后的每个比它小的数字是降序排列
typedef int elemtype;
typedef int Status;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
const int max_size = 20;
class myStack1
{
public:
    elemtype data[max_size];
    int top; //指向栈顶

    myStack1();
    Status push(elemtype e); //入栈
    Status pop(elemtype *e); //接收删除的栈顶元素
    elemtype getelem();
    bool isfull();
    bool isempty();
};

//栈的链表存储结构
struct Stack
{
    elemtype elem;
    Stack *node;
};
class myStack2
{
public:
    int count;  //结点数
    Stack *top; //头节点

    myStack2();
    Status push(elemtype e);
    Status pop(elemtype *e);
};
int main()
{
    myStack1 stack;
    for (int i = 0; i < 10; i++)
        stack.push(i);
    for (int i = stack.top; i >= 0; i--)
        cout << stack.data[i] << " ";
    cout << endl;
    int k;
    cout << stack.pop(&k) << endl;
    cout << k << endl;
    getchar();
    return 0;
}

myStack1::myStack1()
{
    top = -1;
}

Status myStack1::push(elemtype e)
{
    if (top == max_size - 1)
        return ERROR;
    top++;
    data[top] = e;
    return OK;
}

Status myStack1::pop(elemtype *e)
{
    if (top == -1)
        return ERROR;
    *e = data[top];
    top--;
    return OK;
}

elemtype myStack1::getelem()
{
    if (top == -1)
        return -1;
    return data[top];
}

bool myStack1::isfull()
{
    if (top == max_size - 1)
        return true;
    return false;
}

bool myStack1::isempty()
{
    if (top == -1)
        return true;
    return false;
}

myStack2::myStack2()
{
    top = NULL;
    count = 0;
}

Status myStack2::push(elemtype e)
{
    Stack *temp = new Stack;
    temp->elem = e;
    temp->node = top;
    top = temp;
    count++;
    return OK;
}

Status myStack2::pop(elemtype *e)
{
    if (top == NULL)
        return ERROR;
    Stack *temp = top;
    *e = top->elem;
    top = top->node;
    count--;
    delete temp;
    return OK;
}

//栈的应用
//递归

//四则运算表达式求值
//后缀表达式 逆波兰运算
//规则:从左到右遍历表达式的每个数字和符号，遇到是数字就进栈，遇到是符
//号，就将处于栈顶两个数字出栈，进行运算，运算结果进栈，直到最终获得结果。


//规则：从左到右遍历中缀表达式的每个数字和符号，若是数字就输出，即成为后
//缀表达式的一部分，若是符号，则判断其与楼顶符号的优先级，是右括号或优先
//级低于栈顶符号(乘除 先加减)则栈顶元素依次出栈并输出 并将当前符号进栈，一直
//到最终输出后缀表达式为止。



//进制转换
myStack2 dec_oct(int N)
{
    myStack2 stack;
    while (N != 0)
    {
        stack.push(N % 8);
        N = N / 8;
    }
    return stack;
}

//practice
int op(int a, char Op, int b)
{
    switch (Op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
    {
        if (b == 0)
            return 0;
        else
            return a / b;
    }
    }
}
int com(char exp[])
{
    myStack1 stack;
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]>='1'||exp[i]<='9')
        stack.push(int(exp[i]-'0'));
        else
        {
            int a=stack.data[stack.top--];
            int b=stack.data[stack.top--];
            stack.data[++stack.top]=op(a,exp[i],b);
        }
    }
    return stack.data[stack.top]; 
}
