#include <iostream>
using namespace std;
//单链表的操作
typedef int Error_code;
#define success 1
#define error 0
template <class elemtype>
struct List
{
    elemtype elem;
    List *node;
};

template <class elemtype>
class list
{
private:
    int count;
    List<elemtype> *head;

public:
    list();
    int length() const;
    Error_code get_elem(int i, elemtype &e) const;
    List<elemtype> *locate(const elemtype x) const;
    Error_code insert(const int i, const elemtype e);
    Error_code del(const int i);
    void create1();
    void create2();
    void print();
    void reverse();
    ~list();
};

int main()
{

    list<int> l1;
    l1.create1();
    l1.del(2);
    l1.print();
    system("pause");
    return 0;
}

template <class elemtype>
list<elemtype>::list()
{
    count = 0;
    head = new List<elemtype>;
    head->node = NULL;
}

template <class elemtype>
int list<elemtype>::length() const
{
    return count;
}

template <class elemtype>
Error_code list<elemtype>::get_elem(int i, elemtype &e) const
{
    if (count == 0)
        return error;
    int j = 1;
    List<elemtype> *temp = head->node;
    for (; temp != NULL; temp = temp->node, j++)
    {
        if (j == i)
        {
            e = temp->elem;
            return success;
        }
    }
    return error;
}

template <class elemtype>
List<elemtype> *list<elemtype>::locate(const elemtype x) const
{
    List<elemtype> *temp = head->node;
    for (; temp != NULL; temp = temp->node)
    {
        if (temp->elem == x)
            return temp;
    }

    return temp;
}

template <class elemtype>
Error_code list<elemtype>::insert(const int i, const elemtype e)
{
    if (i < 1 || i > count)
        return error;
    int j = 0;
    List<elemtype> *_new = new List<elemtype>;
    for (List<elemtype> *temp = head; temp != NULL; temp = temp->node, j++)
    {
        if (j == i - 1)
        {
            _new->elem = e;
            _new->node = temp->node;
            temp->node = _new;
            count++;
            return success;
        }
    }
    return error;
}

template <class elemtype>
Error_code list<elemtype>::del(const int i)
{
    if (i < 1 || i > count || head->node == NULL)
        return error;
    int j = 0;
    List<elemtype> *_new;
    for (List<elemtype> *temp = head; temp != NULL; temp = temp->node, j++)
    {
        if (j == i - 1)
        {
            _new = temp->node;
            temp->node = _new->node;
            delete _new;
            count--;
            return success;
        }
    }
    return error;
}


template <class elemtype>
void list<elemtype>::create1()
{
    cout << "head insert" << endl;
    elemtype x;
    List<elemtype> *_new;
    while (cin >> x)
    {
        _new = new List<elemtype>;
        _new->elem = x;
        _new->node = head->node;
        head->node = _new;
        count++;
        cin.clear();
    }
}

template <class elemtype>
void list<elemtype>::create2()
{
    cout << "end insert" << endl;
    elemtype x;
    List<elemtype> *_new;
    List<elemtype> *rear = head;
    while (cin >> x)
    {
        _new = new List<elemtype>;
        _new->elem = x;
        rear->node = _new;
        rear = _new;
        rear->node = NULL;
        count++;
        cin.clear();
    }
}

template <class elemtype>
list<elemtype>::~list()
{
    List<elemtype> *p;
    List<elemtype> *q;
    p = head->node;
    while (p != NULL)
    {
        q = p;
        p = p->node;
        delete q;
    }
}

template <class elemtype>
void list<elemtype>::print()
{
    for (List<elemtype> *temp = head->node; temp != NULL; temp = temp->node)
    {
        cout << temp->elem << " ";
    }
}

template <class elemtype>
void list<elemtype>::reverse()
{
    List<elemtype> *i = head->node;
    List<elemtype> *j = NULL;
    List<elemtype> *k;
    while (i != NULL)
    {
        k = i;
        i = i->node;
        k->node = j;
        j = k;
    }
    head->node = j;
}