#include <iostream>
using namespace std;
//队列(queue)是只允许在一端进行插入操作，而在另一进行删除操作的线性表

//队列是一种先进先出的线性表，简称 FIFO。允许插入的一端称为队尾，允许删除的一端称为队头
typedef int elemtype;
typedef int Status; //Status是函数的类型，其值为OK等状态，即返回一个操作的状态，用引用返回操作数
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
const int max_size = 10;
//顺序队列
class queue
{
public:
    elemtype data[max_size];
    int front;
    int rear;
    int size;

    queue();
    void destroy();
    void clear();
    Status gethead(int *e);
    Status insert(elemtype e);
    Status del1(elemtype *e);
    Status del2(elemtype *e);
};
//循环队列
class Queue
{
private:
    elemtype data[max_size];
    int front;
    int rear;
    int size;

public:
    Queue();
    int Getlength();
    Status insert(elemtype e);
    Status del(elemtype *e);
};
//链式队列
struct list
{
    elemtype elem;
    list *node;
};
class _queue
{
private:
    list *front;
    list *rear;

public:
    _queue();
    Status insert(elemtype e);
    Status del(elemtype *e);
    void print();
};
int main()
{
    _queue q;
    for(int i=0;i<5;i++)q.insert(i);
    q.print();
    cout<<endl;
    elemtype*e;
    q.del(e);
    q.del(e);
    q.print();
    getchar();
    return 0;
}

queue::queue()
{
    size = 0;
    front = rear = 0;
    return;
}

void queue::destroy()
{
    delete[] data;
    return;
}

Status queue::gethead(int *e)
{
    if (size == 0)
        return ERROR;
    *e = data[front];
    return OK;
}

Status queue::insert(elemtype e)
{
    if (rear - 1 == max_size)
        return ERROR;
    data[rear] = e;
    rear++;
    size++;
    return OK;
}

Status queue::del1(elemtype *e)
{
    if (front == rear)
        return false;
    *e = data[front];
    front++;
    size--;
    return OK;
}

Status queue::del2(elemtype *e)
{
    if (front == rear)
        return ERROR;
    *e = data[front];
    for (int i = front; i != rear - 1; i++)
        data[i] = data[i + 1];
    rear--;
}

Queue::Queue()
{
    size = 0;
    front = rear = 0;
    return;
}

int Queue::Getlength()
{
    return (rear + max_size - front) % max_size;
}

Status Queue::insert(elemtype e)
{
    if ((rear + 1) % max_size == front)
        return ERROR;
    data[rear] = e;
    rear = (rear + 1) % max_size;
    size++;
    return OK;
}

Status Queue::del(elemtype *e)
{
    if (Getlength() == 0)
        return ERROR;
    *e = data[front];
    front = (front + 1) % max_size;
    return OK;
}

_queue::_queue()
{
    front = rear = new list;
}

Status _queue::insert(elemtype e)
{
    rear->node = new list;
    rear=rear->node;
    rear->elem=e;
    rear->node =NULL;
    return OK;
}

Status _queue::del(elemtype *e)
{
    if (front == rear)
        return ERROR;
    *e = front->node->elem;
    list *temp = front->node;
    if (front->node == rear)
        rear = front;
    front->node = temp->node;
    delete temp;
    return OK;
}

void _queue::print()
{
    for (list *temp = front->node; temp != NULL; temp = temp->node)
        cout << temp->elem << " ";
}

//应用
//在操作系统中，多任务多作业的排队
//网络中，服务器对各终端的服务请求的排队
//在程序设计中，用队列结构存储数据构成某种次序，实现特定问题的求解（图的广度优先搜索遍历算法）

//用队列计算并打印杨辉三角
