#include <iostream>
#include <stack>
#include <queue>
using namespace std;
//树(tree)是n(n>=0)个结点的有限集。n=0时称为空树。在任意一棵非空
//树中:1.有且仅有一个特定的称为根（Root）的结点。2.当n>1时，其
//余结点可分为m(m>0)个互不相交的有限集T1,T2,……Tn,其中每一个
//集合本身又是一棵树，并且称为根的子树(SubTree)

//对于树的定义强调两点:
//1.n>0 时根结点是唯一的，不可能存在多个根结点，别和现实中的大树混在一
//起，现实中的树有很多根须，那是真实的树，数据结向中的树是只能有一个根
//结点。
//2.m>O 时,子树的个数没有限制，但它们一定是互不相交的。

//结点分类
//树的结点包含1个数据元素及若干指向其子树的分支。结点拥有的子树数称为结
//点的度 (Degree) 。度为0的结点称为叶结点(Leaf) 或终端结点;度不为0的结点
//称为非终端结点或分支结点 除根结点之外，分支结点也称为内部结点。树的度是树
//内各结点的度的最大值。

//结点的子树的根即该节点下的一个分节点称为该结点的孩子(Child),相应地,该结点称为孩子的双亲
//(Parent)。
//同一个双亲的孩子之间直称兄弟 (Sibling)
//结点的祖先是从根到该结点所经分支上的所有结点。
//反之，以某结点为根的子树中的任一结点都称为该结点的子孙。

//结点的层次Level从根开始定义起，根为第一层，根的孩子为第二层。若某结
//点在第l层，则其子树的根就在第l+1层。其双亲在同一层的结点互为堂兄弟。

//树中结点的最大层次称为树的深度(deep)或高度
//如果将树中结点的各子树看成从左至右是有次序的，不能互换的，则称该树为有序树，否则称为无序树
//森林Forest是m(m>=0)棵互不相交的树的集合。对树中每个结点而言，其子树的集合即为森林。
#define BinNodePosi(elemtype) BinNode<elemtype> * //节点位置
#define stature(p) ((p) ? (p)->height : -1)       //节点高度，与空树高度为-1相统一
typedef enum
{
    RB_RED,
    RB_BLACK
} RBColor; //节点颜色
template <class elemtype>
struct BinNode
{
    elemtype data;
    BinNode<elemtype> *parent;
    BinNode<elemtype> *lchild;
    BinNodePosi(elemtype) rchild;
    int height;
    int size();
    BinNodePosi(elemtype) insertAslc(elemtype const &e) //作为左孩子插入新节点
    {
        if (lchild == NULL && rchild == NULL)
            height++;
        return lchild = new BinNode(e, this);
    }
    BinNodePosi(elemtype) insertAsrc(elemtype const &e) //作为右孩子插入新节点
    {
        if (lchild == NULL && rchild == NULL)
            height++;
        return rchild = new BinNode(e, this);
    }
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
    void travpre2();                                                    //先序迭代遍历1
    void travpre3();                                                    //先序迭代遍历2
    void travin1(BinNodePosi(elemtype) x);                              //中序递归遍历
    void travin2();                                                     //中序迭代遍历
    void travpost1(BinNodePosi(elemtype) x);                            //后续递归遍历
    void travpost2();                                                   //后序迭代遍历
    void travlevel();                                                   //层次遍历
};
int main()
{
    Bintree<char> t1;
    t1.create1(t1.root(),t1.root());
    t1.travin2();
    system("pause");
    return 0;
}
template <class elemtype>
Bintree<elemtype>::Bintree()
{
    _size = 0;
    _root = new BinNode<elemtype>;
    _root->lchild = NULL;
    _root->rchild = NULL;
    _root->parent = NULL;
}
template <class elemtype>
int BinNode<elemtype>::size()
{
    int s = 1;
    if (lchild)
        s += lchild->size();
    if (rchild)
        s += rchild->size();
    return s;
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
void Bintree<elemtype>::travpre2() //先序迭代遍历1
{
    stack<BinNodePosi(elemtype)> s;
    BinNodePosi(elemtype) x = _root;
    s.push(x);
    while (!s.empty())
    {
        x = s.top();
        s.pop();
        cout << x->data << " ";
        if (x->rchild)
            s.push(x->rchild);
        if (x->lchild)
            s.push(x->lchild);
    }
}

template <class elemtype>
static void visitleftbranch(BinNodePosi(elemtype) x, stack<BinNodePosi(elemtype)> &s)
{
    while (x != NULL)
    {
        cout << x->data << " ";
        if (x->rchild)
            s.push(x->rchild);
        x = x->lchild;
    }
}
template <class elemtype>
void Bintree<elemtype>::travpre3() //先序迭代遍历2
{
    stack<BinNodePosi(elemtype)> s;
    BinNodePosi(elemtype) x = _root;
    while (1)
    {
        visitleftbranch(x, s);
        if (s.empty())
            break;
        x = s.top();
        s.pop();
    }
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
void goalongleft(BinNodePosi(elemtype) x, stack<BinNodePosi(elemtype)> &s)
{
    while (x != NULL)
    {
        s.push(x);
        x = x->lchild;
    }
}

template <class elemtype>
void Bintree<elemtype>::travin2() //中序迭代遍历
{
    stack<BinNodePosi(elemtype)> s;
    BinNodePosi(elemtype) x = _root;
    while (1)
    {
        goalongleft(x, s);
        if (s.empty())
            return;
        x = s.top();
        s.pop();
        cout << x->data << " ";
        x = x->rchild;
    }
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
void deepest(stack<BinNodePosi(elemtype)> &s)
{
    BinNodePosi(elemtype) x;
    while (x = s.top())
    {
        if (x->lchild)
        {
            if (x->rchild)
                s.push(x->rchild);
            s.push(x->lchild);
        }
        else
            s.push(x->rchild);
    }
    s.pop();
}
template <class elemtype>
void Bintree<elemtype>::travpost2()
{
    stack<BinNodePosi(elemtype)> s;
    s.push(_root);
    BinNodePosi(elemtype) x = s.top();
    while (!s.empty())
    {
        if (x->parent != s.top())
            deepest(s);
        x = s.top();
        cout << x->data << " ";
        s.pop();
    }
}
template <class elemtype> //层次遍历
void Bintree<elemtype>::travlevel()
{
    queue<BinNodePosi(elemtype)> q;
    BinNodePosi(elemtype) x = _root;
    q.push(x);
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        cout << x->data << " ";
        if (x->lchild)
            q.push(x->lchild);
        if (x->rchild)
            q.push(x->rchild);
    }
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
//practice
int cal(int A, char m, int B)
{
    switch (m)
    {
    case '+':
        return A + B;
    case '-':
        return A - B;
    case '*':
        return A * B;
    case '/':
        return A / B;
    }
}
int comp(BinNode<char> *x)//求表达式的值
{
    if (x != NULL)
    {
        if (x->lchild != NULL && x->rchild != NULL)
        {
            int A = comp(x->lchild);
            int B = comp(x->rchild);
            return cal(A, x->data, B);
        }
        else
            return (int)(x->data - '0');
    }
}
template <class elemtype>
int getdepth(BinNodePosi(elemtype) x)//求高度
{
    if (x == NULL)
        return -1;

    int LD = getdepth(x->lchild);
    int RD = getdepth(x->rchild);
    return LD > RD ? LD : RD + 1;
}

template <class elemtype>
struct St
{
    BinNodePosi(elemtype) p;
    int level;
};
template <class elemtype>
int maxNode(BinNodePosi(elemtype) x)
{
    St<elemtype> queue[50];
    int front, rear;
    front = rear = 0;
    int Level;
    BinNodePosi(elemtype) temp;
    if (x != NULL)
    {
        queue[rear++].p = x;
        queue[rear - 1].level = 1;
    }
    else
        return 0;
    while (front != rear)
    {
        Level = queue[front].level;
        temp = queue[front++];
        if (temp->lchild != NULL)
        {
            queue[rear++].p = temp->lchild;
            queue[rear - 1].level = Level + 1;
        }
        if (temp->rchild != NULL)
        {
            queue[rear++].p = temp->rchild;
            queue[rear - 1].level = Level + 1;
        }
    }
    int max = 0;
    for (int i = 1; i <= Level; i++)
    {
        int sum = 0;
        for (int j = 0; j < rear; j++)
            if (queue[j].level == i)
                sum++;
        if (max < sum)
            max = sum;
    }
    return max;
}
