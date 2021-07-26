#include <iostream>
using namespace std;
//ջ���޶����ڱ�β���в����ɾ�����������Ա�
//ջ��(top)���в����ɾ������  ջ��(bottom)

//ջ��˳��洢�ṹ
//ջ�ĺϷ�������У�һ�����ֺ��ÿ������С�������ǽ�������
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
    int top; //ָ��ջ��

    myStack1();
    Status push(elemtype e); //��ջ
    Status pop(elemtype *e); //����ɾ����ջ��Ԫ��
    elemtype getelem();
    bool isfull();
    bool isempty();
};

//ջ������洢�ṹ
struct Stack
{
    elemtype elem;
    Stack *node;
};
class myStack2
{
public:
    int count;  //�����
    Stack *top; //ͷ�ڵ�

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

//ջ��Ӧ��
//�ݹ�

//����������ʽ��ֵ
//��׺���ʽ �沨������
//����:�����ұ������ʽ��ÿ�����ֺͷ��ţ����������־ͽ�ջ�������Ƿ�
//�ţ��ͽ�����ջ���������ֳ�ջ���������㣬��������ջ��ֱ�����ջ�ý����


//���򣺴����ұ�����׺���ʽ��ÿ�����ֺͷ��ţ��������־����������Ϊ��
//׺���ʽ��һ���֣����Ƿ��ţ����ж�����¥�����ŵ����ȼ����������Ż�����
//������ջ������(�˳� �ȼӼ�)��ջ��Ԫ�����γ�ջ����� ������ǰ���Ž�ջ��һֱ
//�����������׺���ʽΪֹ��



//����ת��
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
