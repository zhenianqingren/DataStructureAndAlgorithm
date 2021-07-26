#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
#define F
struct Int
{
    unsigned bi : 1;
};
template <class T>
struct bnode
{
    T e;
    bnode<T> *lchild;
    bnode<T> *rchild;
    bnode<T> *parent;
    int w;
    vector<Int> code;
};
template <typename T>
class Huffman
{
protected:
    bnode<T> *root;
    vector<bnode<T> *> _find;
    vector<bnode<T> *> tree;
    int n;
    vector<Int> Code;
    vector<char> init;
    vector<char> trans;
    string document;

public:
    Huffman();
    bnode<T> *&getroot() { return root; }
    void input1(); //手动输入
    void input2(); //文本输出
    void sort();
    void save();
    void huffmantree();
    void output_code();
    void trans_infor();
    void reverse();
    void print1();
    void retrans(bnode<T> *&p, int &k);
    void zip();
    void Write();
    void reWrite();
    void print2();
};

int main()
{
    Huffman<char> h;
#ifdef G
    h.input1();
    h.save();
    h.huffmantree();
    h.output_code();
    h.reverse();
    h.print1();
    cout << endl;
    cout << "total weight:  " << h.getroot()->w << endl;
#endif
#ifdef F
    h.input2();
    h.huffmantree();
    h.output_code();
    h.reverse();
    h.trans_infor();
    h.zip();
    cout << "\n\n\n"
         << endl;

    
    h.print1();
    cout << "\n\n"
         << endl;
    h.print2();
    cout << endl;
    h.Write();
#endif
    system("pause");
    return 0;
}

template <class T>
Huffman<T>::Huffman()
{
    root = NULL;
    n = 0;
}
template <class T>
void Huffman<T>::input1()
{
    cout << "Please input elem and its weight,while meet '. .' input end " << endl;
    T elem;
    bnode<T> *temp = NULL;
    int weight;
    do
    {
        cout << "ELEM\tWEIGHT:";
        cin >> elem >> weight;
        if (!cin.good() || elem == '.')
        {
            temp = NULL;
            n = tree.size();
            return;
        }
        temp = new bnode<T>;
        temp->e = elem;
        temp->w = weight;
        temp->parent = NULL;
        temp->lchild = NULL;
        temp->rchild = NULL;
        tree.push_back(temp);
    } while (true);
}
template <class T>
void Huffman<T>::input2()
{
    _find.resize(128);
    for (int i = 0; i < _find.size(); i++)
    {
        _find[i] = new bnode<T>;
        _find[i]->parent = _find[i]->lchild = _find[i]->rchild = NULL;
        _find[i]->w = 0;
        _find[i]->e = (char)i;
    }
    ifstream ifs;
    cout << "input specific document" << endl;
    cin >> document;
    ifs.open(document);
    if (ifs.fail())
    {
        cout << "error" << endl;
        return;
    }
    char c;
    while (ifs.get(c))
    {
        _find[(int)c]->w++;
        init.push_back(c);
    }
    for (int i = 0; i < _find.size(); i++)
        if (_find[i]->w != 0)
            tree.push_back(_find[i]);
    n = tree.size();
}
template <class T>
void Huffman<T>::sort()
{
    for (int i = 0; i < tree.size() - 1; i++)
        for (int j = 0; j < tree.size() - 1 - i; j++)
        {
            if (tree[j]->w < tree[j + 1]->w)
            {
                bnode<T> *temp = tree[j];
                tree[j] = tree[j + 1];
                tree[j + 1] = temp;
            }
        }
}
template <class T>
void Huffman<T>::save()
{
    sort();
    for (int i = 0; i < tree.size(); i++)
        _find.push_back(tree[i]);
}
template <class T>
void Huffman<T>::huffmantree()
{
    bnode<T> *temp = NULL;
    while (n > 1)
    {
        sort();
        temp = new bnode<T>;
        temp->lchild = tree[n - 2];
        temp->rchild = tree[n - 1];
        temp->w = tree[n - 1]->w + tree[n - 2]->w;
        tree[n - 1]->parent = tree[n - 2]->parent = temp;
        tree[n - 2] = temp;
        n--;
    }
    temp = NULL;
    root = tree[0];
}
template <class T>
void Huffman<T>::output_code()
{
    bnode<T> *temp = NULL;
    for (int i = 0; i < _find.size(); i++)
    {
        if (_find[i]->w != 0)
        {
            temp = _find[i];
            while (temp != root)
            {
                if (temp->parent->lchild == temp)
                    _find[i]->code.push_back(Int{0});
                else
                    _find[i]->code.push_back(Int{1});
                temp = temp->parent;
            }
        }
    }
}
template <class T>
void Huffman<T>::reverse()
{
    for (int i = 0; i < _find.size(); i++)
    {
        if (_find[i]->w != 0)
        {
            int m = 0;
            int n = _find[i]->code.size() - 1;
            while (m < n)
            {
                int temp = _find[i]->code[m].bi;
                _find[i]->code[m].bi = _find[i]->code[n].bi;
                _find[i]->code[n].bi = temp;
                m++;
                n--;
            }
        }
    }
}
template <class T>
void Huffman<T>::trans_infor()
{

    for (int n = 0; n < init.size(); n++)
    {
        int size = _find[(int)init[n]]->code.size();
        for (int i = 0; i < size; i++)
            Code.push_back(_find[(int)init[n]]->code[i]);
    }
}
template <class T>
void Huffman<T>::print1()
{
    for (int i = 0; i < _find.size(); i++)
    {
        if (_find[i]->w != 0)
        {
            cout << "Elem:  " << _find[i]->e << "  Weight:  " << _find[i]->w << "  Code:  ";
            for (int j = 0; j < _find[i]->code.size(); j++)
                cout << _find[i]->code[j].bi;
            cout << endl;
        }
    }
}
template <class T>
void Huffman<T>::retrans(bnode<T> *&p, int &k)
{
    if (p->lchild == NULL && p->rchild == NULL)
    {
        cout << p->e;
        return;
    }
    if (Code[k].bi == 0)
    {
        k++;
        retrans(p->lchild, k);
    }
    else
    {
        k++;
        retrans(p->rchild, k);
    }
}
template <class T>
void Huffman<T>::print2()
{
    int k = 0;
    while (k < Code.size())
        retrans(root, k);

    cout << "\n"
         << endl;
    for (int i = 0; i < Code.size(); i++)
        cout << Code[i].bi;
    cout<<endl;
    cout<<"Start:"<<init.size()*8<<endl;
    cout<<"Finally:"<<trans.size()*8<<endl;
}
template <class T>
void Huffman<T>::zip()
{
    int temp = 0;
    int count = 0;
    for (int i = 0; i < Code.size(); i++)
    {
        temp = temp * 2 + Code[i].bi;
        count++;
        if (count == 8)
        {
            trans.push_back((char)temp);
            temp = 0;
            count = 0;
        }
    }
}
template <class T>
void Huffman<T>::Write()
{
    fstream fs(document, ios::out);
    for (int i = 0; i < trans.size(); i++)
        fs << trans[i];
}
template <class T>
void Huffman<T>::reWrite()
{
    fstream fs(document, ios::out);
    for (int i = 0; i < init.size(); i++)
        fs << init[i];
}