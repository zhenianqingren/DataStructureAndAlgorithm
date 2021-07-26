#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define BinNodePosi(elemtype) BinNode<elemtype> * //节点位置
#define stature(p) ((p) ? (p)->height : -1)       //节点高度，与空树高度为-1相统一
template <class elemtype>
struct BinNode
{
    BinNode() : parent(NULL), lchild(NULL), rchild(NULL) {}
    elemtype data;
    BinNode<elemtype> *parent;
    BinNode<elemtype> *lchild;
    BinNodePosi(elemtype) rchild;
    int height;
};
template <class elemtype>
class Bintree
{
protected:
    int _size;
    BinNodePosi(elemtype) _root;
    virtual int updateheight(BinNodePosi(elemtype) & x); //更新节点x的高度
    void updateheightabove(BinNodePosi(elemtype) & x);   //更新x及其历代祖先的高度
public:
    Bintree();
    int size() const { return _size; }
    bool empty() const { return !_root; }
    BinNodePosi(elemtype) & root() { return _root; }
    BinNodePosi(elemtype) insertAsrc(BinNodePosi(elemtype) & x, elemtype const e);
    void create1(BinNodePosi(elemtype) & x, BinNodePosi(elemtype) & p); //先序创建
    void travpre1(BinNodePosi(elemtype) x);                             //先序递归遍历
    void travin1(BinNodePosi(elemtype) x);                              //中序递归遍历
    void travpost1(BinNodePosi(elemtype) x);                            //后续递归遍历
    BinNodePosi(elemtype) SearchBST(BinNodePosi(elemtype) & x, elemtype e);
    void InsertBST(BinNodePosi(elemtype) & Root, BinNodePosi(elemtype) & x);
    void createBST(vector<BinNodePosi(elemtype)> &v);
    BinNodePosi(elemtype) & Pre_In(BinNodePosi(elemtype) & x);
    void DeleteBST(BinNodePosi(elemtype) & x);
};
int main()
{

    system("pause");
    return 0;
}
template <class elemtype>
Bintree<elemtype>::Bintree()
{
    _size = 0;
    _root = new BinNode<elemtype>;
}

template <class elemtype>
int Bintree<elemtype>::updateheight(BinNodePosi(elemtype) & x)
{
    return x->height = 1 + max(stature(x->lchild), stature(x->rchild));
    //+1代表根在最左或有节点的上方，比它孩子的高度多1
}

template <class elemtype>
void Bintree<elemtype>::updateheightabove(BinNodePosi(elemtype) & x)
{
    while (x)
    {
        updateheightabove(x);
        x = x->parent;
    }
}

template <class elemtype>
BinNodePosi(elemtype) Bintree<elemtype>::insertAsrc(BinNodePosi(elemtype) & x, elemtype const e)
{
    x->insertAsrc(e);
    _size++;
    updateheightabove(x);
    return x->rchild;
}

template <class elemtype>
void Bintree<elemtype>::travpre1(BinNodePosi(elemtype) x) //先序递归遍历
{
    if (x == NULL)
        return;
    cout << x->data << endl;
    travpre1(x->lchild);
    travpre1(x->rchild);
}

template <class elemtype>
void Bintree<elemtype>::travin1(BinNodePosi(elemtype) x) //中序递归遍历
{
    if (x == NULL)
        return;
    travin1(x->lchild);
    cout << x->data << " ";
    travin1(x->rchild);
}

template <class elemtype>
void Bintree<elemtype>::travpost1(BinNodePosi(elemtype) x) //后序递归遍历
{
    if (x == NULL)
        return;
    travpost1(x->lchild);
    travpost1(x->rchild);
    cout << x->data << " ";
}

template <class elemtype>
void Bintree<elemtype>::create1(BinNodePosi(elemtype) & x, BinNodePosi(elemtype) & p)
{
    elemtype e;
    cin >> e;
    if (e == '.')
    {
        x = NULL;
        this->updateheightabove(x);
    }
    else
    {
        if (x != _root)
        {
            x = new BinNode<elemtype>;
            x->lchild = NULL;
            x->rchild = NULL;
            x->parent = p;
        }
        x->data = e;
        _size++;
        create1(x->lchild, x);
        create1(x->rchild, x);
    }
}

template <class elemtype>
BinNodePosi(elemtype) Bintree<elemtype>::SearchBST(BinNodePosi(elemtype) & x, elemtype e)
{
    if (!x || x->data == e)
        return x;
    if (x->data > e)
        return SearchBST(x->lchild, e);
    else if (x->data <= e)
        return SearchBST(x->rchild, e);
}

template <class elemtype>
void Bintree<elemtype>::InsertBST(BinNodePosi(elemtype) & treenode, BinNodePosi(elemtype) & x)
{
    if (x->data < treenode->data)
    {
        if (treenode->lchild != NULL)
            InsertBST(treenode->lchild, x);
        else
        {
            treenode->lchild = x;
            x->parent = treenode;
            return;
        }
    }
    else
    {
        if (treenode->rchild != NULL)
            InsertBST(treenode->rchild, x);
        else
        {
            treenode->rchild = x;
            x->parent = treenode;
            return;
        }
    }
}

template <class elemtype>
void Bintree<elemtype>::createBST(vector<BinNodePosi(elemtype)> &v)
{
    if (v.size() != 0)
    {
        root = v[0];
        for (int i = 1; i < v.size(); i++)
            InsertBST(root, v[i]);
    }
}

template <class elemtype>
BinNodePosi(elemtype) & Bintree<elemtype>::Pre_In(BinNodePosi(elemtype) & x)
{
    static BinNodePosi(elemtype) temp = x->lchild;
    while (temp->rchild != NULL)
        temp = temp->rchild;
    return temp;
}

template <class elemtype>
void Bintree<elemtype>::DeleteBST(BinNodePosi(elemtype) & x)
{
    if (x->lchild == NULL && x->lchild == NULL)
    {
        delete x;
        return;
    }
    else if (x->lchild == NULL && x->rchild != NULL)
    {
        x->parent->lchild == x ? x->parent->lchild = x->rchild : x->parent->rchild = x->rchild;
        delete x;
        return;
    }
    else if (x->lchild != NULL && x->rchild == NULL)
    {
        x->parent->lchild == x ? x->parent->lchild = x->lchild : x->parent->rchild = x->lchild;
        delete x;
        return;
    }
    else if (x->lchild != NULL && x->rchild != NULL)
    {
        static BinNodePosi(elemtype) temp=Pre_In(x);
        x->data=temp->data;
        DeleteBST(temp);
    }
}