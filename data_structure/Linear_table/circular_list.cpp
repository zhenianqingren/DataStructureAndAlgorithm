#include <iostream>
using namespace std;

typedef int elemtype;
typedef int Error_code;
#define success 1
#define error 0

struct List
{
    elemtype elem;
    List *node;
};
class Circular
{
private:
    List *head;
    List *rear;
    int length;

public:
    Circular();
    int getlength() const;
    Error_code getelem(const int i, elemtype &e) const;
    Error_code insert(const int i, const elemtype e);
    Error_code delete_(const int i);
    void print() const;
    Error_code ClearList();
};

int main()
{
    Circular c;
    for (int i = 1; i <= 3; i++)
        c.insert(1, i);
    c.print();
    cout << endl;
    c.delete_(1);
    c.delete_(2);
    c.delete_(1);
    c.insert(1, 1);
    c.insert(2, 2);
    c.print();
    system("pause");
    return 0;
}

Circular::Circular()
{
    head = new List;
    head->node = head;
    length = 0;
    rear = head;
}

int Circular::getlength() const
{
    return length;
}

Error_code Circular::getelem(const int i, elemtype &e) const
{
    if (i < 1 || i > length || length == 0)
        return error;
    int j = 1;
    List *temp_p = head->node;
    for (; temp_p != head; temp_p = temp_p->node, j++)
    {
        if (j == i)
        {
            e = temp_p->elem;
            return success;
        }
    }
    return error;
}

Error_code Circular::insert(int i, elemtype e)
{
    if (i < 1 || i > length + 1)
        return error;
    int j = 0;
    List *temp = head;
    List *_new = new List;
    do
    {
        if (j == i - 1)
        {
            _new->elem = e;
            _new->node = temp->node;
            temp->node = _new;
            if (length == 0 || i == length + 1)
                rear = _new;
            length++;
            return success;
        }
        else
        {
            j++;
            temp = temp->node;
        }
    } while (temp != head);

    return error;
}

Error_code Circular::delete_(const int i)
{
    if (i < 1 || i > length || length == 0)
        return error;
    List *del;
    int j = 0;
    List *temp = head;
    do
    {
        if (j == i - 1)
        {
            del = temp->node;
            temp->node = del->node;
            delete del;
            length--;
            if (length == 0 || i == length + 1)
                rear = temp;
            return success;
        }

        else
        {
            j++;
            temp = temp->node;
        }
    } while (temp != head);
    return error;
}

void Circular::print() const
{
    for (List *temp = head->node; temp != head; temp = temp->node)
        cout << temp->elem << " ";
}