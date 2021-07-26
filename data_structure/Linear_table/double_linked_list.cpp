#include <iostream>
using namespace std;

typedef int elemtype;
typedef int Error_code;
#define success 1
#define error 0

struct List
{
    elemtype data;
    List *prior;
    List *next;
};

class list
{
private:
    List *head;
    List *rear;
    int length;

public:
    list();
    int getlength() const;
    Error_code insert(const int i, const elemtype e);
    Error_code del(const int i);
    void print1();
    void print2();
    void create();
    void reverse(); //就地逆置
};

int main()
{
    list l;

    cout<<"Please input number,while meet illegal char,create end"<<endl;

    l.create();
    cout << "Before:" << endl;
    l.print1();
    cout << "\n\n";
    l.print2();
    cout << "\n\n";
    cout << "After:" << endl;
    l.reverse();
    l.print1();
    cout << "\n\n";
    l.print2();
    cout << endl;
    l.del(5);
    l.insert(2,666);
    l.insert(1,-3);
    l.del(l.getlength());
    l.print1();
    system("pause");
    return 0;
}

list::list()
{
    head = new List;
    head->prior = head->next = head;
    rear = head;
    length = 0;
}

int list::getlength() const
{
    return length;
}

Error_code list::insert(const int i, const elemtype e)
{
    if (i < 1 || i > length + 1)
        return error;

    List *_new = new List;
    _new->data = e;

    int j = 0;
    List *temp = head;
    do
    {
        if (j == i - 1)
        {
            _new->next = temp->next;
            _new->prior = temp;
            temp->next->prior = _new;
            temp->next = _new;
            if (i == length + 1 || length == 0)
                rear = _new;
            length++;
            return success;
        }

        else
        {
            j++;
            temp = temp->next;
        }

    } while (temp != head);
    return error;
}

Error_code list::del(const int i)
{
    if (i < 1 || i > length || length == 0)
        return error;
    List *del = head;
    int j = 0;
    do
    {
        if (j == i)
        {
            if (i == length)
                rear = del->prior;
            del->next->prior = del->prior;
            del->prior->next = del->next;
            length--;
            if (length == 0)
                rear = head;
            delete del;
            return success;
        }

        else
        {
            j++;
            del = del->next;
        }
    } while (del != head);
    return error;
}

void list::print1()
{
    if (length == 0)
        return;
    cout << "forward printing" << endl;
    for (List *temp = head->next; temp != head; temp = temp->next)
        cout << temp->data << " ";
}

void list::print2()
{
    if (length == 0)
        return;
    cout << "opposite printing" << endl;
    for (List *temp = head->prior; temp != head; temp = temp->prior)
        cout << temp->data << " ";
}

void list::create()
{
    int x;
    List *temp;
    while (cin >> x)
    {
        temp = new List;
        temp->data = x;
        temp->next = head;
        head->prior = temp;
        temp->prior = rear;
        rear->next = temp;
        rear = temp;
        length++;
        cin.clear();
    }
}

void list::reverse()
{
    List *p = head->next;
    List *q;
    List *j = head;
    List *fi = p;
    while (p != head)
    {
        q = p;
        p = p->next;
        q->next = j;
        q->prior = p;
        j = q;
    }
    head->next = q;
    head->prior = fi;
}