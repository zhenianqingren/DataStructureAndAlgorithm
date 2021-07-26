#include <iostream>
using namespace std;

//纸牌游戏-小猫钓鱼

//一副扑克牌平均分成两份，每人拿一份，a拿出手中第一张牌放在桌上，b也拿出手中第一张牌，并放在上一张牌上面，
//像这样彼此交替出牌，出牌时，若某人打出的一张牌与桌面上的某张牌相同，则将两张牌及其中间所夹所有牌均归该
//人所有，并放到该人牌末尾，当任意一人手中牌全部出完时，失败。

//由题意，可用队列模拟持牌者，用栈来模拟桌面上的牌

struct queue
{
    int data[500];
    int head;
    int rear;
};

struct stack
{
    int data[500];
    int top;
};

bool judge(stack s, int e, int &j)
{
    for (int i = 0; i < s.top; i++)
        if (s.data[i] == e)
        {
            j = i;
            return true;
        }
    return false;
}

int main()
{
    queue q1, q2;
    stack s;
    int j;
    for (int i = 0; i < 6; i++)
        cin >> q1.data[i];
    for (int i = 0; i < 6; i++)
        cin >> q2.data[i];
    s.top = 0;
    q1.head = q2.head = 0;
    q1.rear = q2.rear = 6;
    while (q1.head < q1.rear && q2.head < q2.rear)
    {
        if (judge(s, q1.data[q1.head], j))
        {
            q1.data[q1.rear++] = q1.data[q1.head++];
            for (int i = s.top - 1; i >= j; i--, s.top--)
                q1.data[q1.rear++] = s.data[i];
        }
        else
            s.data[s.top++] = q1.data[q1.head++];

        if (judge(s, q2.data[q2.head], j))
        {
            q2.data[q2.rear++] = q2.data[q2.head++];
            for (int i = s.top - 1; i >= j; i--, s.top--)
                q2.data[q2.rear++] = s.data[i];
        }
        else
            s.data[s.top++] = q2.data[q2.head++];
    }

    if (q1.head == q1.rear)
    {
        cout << "q2win" << endl;
        for (int i = q2.head; i < q2.rear; i++)
            cout << q2.data[i] << " ";
    }
    else
    {
        cout << "q1win" << endl;
        for (int i = q1.head; i < q1.rear; i++)
            cout << q1.data[i] << " ";
    }

    system("pause");
    return 0;
}