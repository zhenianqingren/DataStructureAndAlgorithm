#include <iostream>
using namespace std;
template <class T>
struct tbtnode
{
    T data;
    tbtnode<T> *lchild;
    tbtnode<T> *rchild;
    tbtnode<T> *parent;
    int ltag;
    int rtag;
};
template <class T>
class tbttree
{
protected:
    tbtnode<T> *_root;

public:
    tbtnode<T> *&root() { return _root; }
    void Inthread(tbtnode<T> *&p, tbtnode<T> *&pre);   //构造中序线索树
    tbtnode<T> *&Left(tbtnode<T> *p);                  //求以p为根节点的树中最靠左的节点
    tbtnode<T> *&Right(tbtnode<T> *p);                 //求以p为根节点的树中最靠右的节点
    tbtnode<T> *&Pre_In(tbtnode<T> *p);                //求中序序列遍历下p节点的前驱节点
    tbtnode<T> *&Next_In(tbtnode<T> *p);               //求中序序列遍历下p节点的后继节点
    void travelin();                                   //中序遍历
    void Prethread(tbtnode<T> *&p, tbtnode<T> *&pre);  //构造先序线索树
    tbtnode<T> *&Pre_Pre(tbtnode<T> *p);               //求先序序列遍历下节点的前驱节点
    tbtnode<T> *&Next_Pre(tbtnode<T> *p);              //求先序序列遍历下p节点的后继节点
    void travelpre();                                  //先序遍历
    void Postthread(tbtnode<T> *&p, tbtnode<T> *&pre); //构造后序线索树
    tbtnode<T> *&Pre_Post(tbtnode<T> *p);              //求后序遍历下p节点的前驱节点
    tbtnode<T> *&Next_Post(tbtnode<T> *p);             //求后序遍历下p节点的后继节点
    void travelpost();
};

int main()
{
    system("pause");
    return 0;
}

template <class T>
void tbttree<T>::Inthread(tbtnode<T> *&p, tbtnode<T> *&pre)
{
    if (p != NULL)
    {
        Inthread(p->lchild, pre);
        if (p->lchild == NULL)
        {
            p->ltag = 1;
            p->lchild = pre;
        }
        if (pre != NULL && pre->rchild == NULL)
        {
            pre->rtag = 1;
            pre->rchild = p;
        }
        pre = p;
        Inthread(p->rchild, pre);
    }
}
template <class T>
tbtnode<T> *&tbttree<T>::Left(tbtnode<T> *p)
{
    while (p->ltag == 0)
        p = p->lchild;
    return p;
}
template <class T>
tbtnode<T> *&tbttree<T>::Right(tbtnode<T> *p)
{
    // ^ //
}
template <class T>
tbtnode<T> *&tbttree<T>::Pre_In(tbtnode<T> *p)
{
    if (p->lchild == 1)
        return p->lchild;
    else
        return Right(p->lchild);
}
template <class T>
tbtnode<T> *&tbttree<T>::Next_In(tbtnode<T> *p)
{
    if (p->rtag == 0)
        return Left(p->rchild);
    else
        return p->rchild;
}
template <class T>
void tbttree<T>::travelin()
{
    for (tbtnode<T> *temp = _root; temp != NULL; temp = Next_In(temp))
        cout << temp->data << " ";
}
template <class T>
void tbttree<T>::Prethread(tbtnode<T> *&p, tbtnode<T> *&pre)
{
    if (p != NULL)
    {
        if (pre != NULL & pre->rchild == NULL)
        {
            pre->rtag = 1;
            pre->rchild = p;
        }

        if (p->lchild == NULL)
        {
            p->ltag = 1;
            p->lchild = pre;
        }

        pre = p;

        if (p->ltag == 0)
            Prethread(p->lchild, pre);

        if (p->rtag == 0)
            Prethread(p->rchild, pre);
    }
}
template <class T>
tbtnode<T> *&tbttree<T>::Pre_Pre(tbtnode<T> *p)
{
    if (p == _root)
        return NULL;
    if (p->ltag == 1)
        return p->lchild;
    if (p->parent->lchild == p)
        return p->parent;
    if (p->parent->rchild == p)
    {
        if (p->parent->ltag == 0)
            return Right(p->parent->lchild);
        else
            return p->parent;
    }
}
template <class T>
tbtnode<T> *&tbttree<T>::Next_Pre(tbtnode<T> *p)
{
    if (p->ltag == 0)
        return p->lchild;
    else
        return p->rchild;
}
template <class T>
void tbttree<T>::travelpre()
{
    for (tbtnode<T> *temp = _root; temp != NULL; temp = Next_Pre(temp))
        cout << temp->data << " ";
}
template <class T>
void tbttree<T>::Postthread(tbtnode<T> *&p, tbtnode<T> *&pre)
{
    if (p != NULL)
    {
        if (p->lchild == 0)
            Postthread(p->lchild, pre);
        if (p->rchild == 0)
            Postthread(p->rchild, pre);
        if (pre != NULL && pre->rchild == NULL)
        {
            pre->rtag = 1;
            pre->rchild = p;
        }
        if (p->lchild == NULL)
        {
            p->ltag = 1;
            p->lchild = pre;
        }
        pre = p;
    }
}
template <class T>
tbtnode<T> *&tbttree<T>::Pre_Post(tbtnode<T> *p)
{
    if (p->rtag == 0)
        return p->rchild;
    else
        return p->lchild;
}
template <class T>
tbtnode<T> *&tbttree<T>::Next_Post(tbtnode<T> *p)
{
    if (p->rtag == 1)
        return p->rchild;
    else
    {
        if (p == p->parent->rchild)
            return p->parent;
        else
        {
            if (p->parent->rtag == 1)
                return p->parent;
            else
                return Left(p->parent->rchild);
        }
    }
}
template <class T>
void tbttree<T>::travelpost()
{
    for (tbtnode<T> *temp = _root; temp != NULL; temp = Next_Post(temp))
        cout << temp->data << " ";
}