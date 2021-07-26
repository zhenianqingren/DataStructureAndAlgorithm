#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//图的基本概念
//由结点的有穷集合V和边的集合E组成 两个顶点之间存在一条边 则称其有相邻关系
//有向图与无向图的区别在于边是否有方向 与顶点v相关的边的条数称为顶点的度
//在有向图中指向顶点v的边的条数称为入度 由顶点v发出的边的条数称为其出度
//将具有n(n-1)条边的n个顶点构成的图称为有向完全图（即任意两个顶点可互相到达）
//无向完全图具有n(n-1)/2条边
//路径：相邻顶点所构成的序列 路径长度：该路径边的条数
//简单路径：路径中顶点不重复出现
//回路：一条路径中首顶点与尾顶点重合
//无相图中，若vi与vj之间有路径联通，则称vi与vj连通，若图的任意两个顶点均连通，则称其为连通图
//否则 图中的极大连通子图称为连通分量
//强连通图：在有向图中，对于每一对顶点vi到vj和从vj到vi都有路径，则称其为强连通图，
//否则 称其中的极大强连通子图称为强连通分量
//权：与边存在一定关系的一个数
//网：边上带有权的图称为带权图，也称为网

//邻接表 图的链式存储结构
struct edge //边
{
    int a;
    int b; //连接的两个结点的信息
    int w; //权重

    int location;    //指向的结点位置
    edge* next_e;    //另外一个与顶点相关的边的位置
    bool isCritical; //是否是关键路径
};
template <class T>
struct node //顶点
{
    T e;           //顶点信息
    edge* first_e; //指向第一条边的位置
    bool mark;     //是否被访问过

    int count; //统计入度
};
template <class T>
class map
{
protected:
    vector<node<T>*> list;    //邻接表
    int n_n;                   //顶点数
    int n_e;                   //边数
    queue<node<T>*> q;        //用于广度优先搜索遍历
    vector<vector<int>> edges; //邻接矩阵
    vector<int> find;          //定义并查集数组
    vector<edge> Edges;        //存放边的信息
    vector<int> que;           //拓扑排序后的路径
    vector<int> ve;            //最早发生时间
    vector<int> vl;            //最迟发生时间
    vector<int> dist;
    vector<int> path;
    int Max; //代表两个不可到达顶点的距离

    vector<vector<int>> A;
    vector<vector<int>> Path; //弗洛伊德算法
public:
    int time;                  //工期
    map();
    void addedge(int x, int y); //添加x点与y点的边关系
    void create();              //构造一个图              无向

    void addedge_(int x, int y,int w);
    void create_(); //有向

    void initedges();               //初始化邻接矩阵
    node<T>*& specific_node(int i); //得到指定位置的结点
    bool same(edge*& t, int e);     //判断边是否重复
    void DFS(node<T>* n);           //深度优先搜索遍历
    void dfs();                     //非连通图
    void BFS();                     //广度优先搜索遍历
    int practice1();                //判断是否是连通图

    void practice2(node<T>* n, int& e, int& p);
    void trav_pra2(int& e, int& p);
    //判断是否是一棵树，e代表边数，p代表结点数，即e/2==p-1

    void assist_dfs(node<T>*& n, int& s);
    bool test(node<T>*& n);
    //判断图中的一个节点是否是关节点
    //所谓关节点就是在一个连通图中删除某个顶点及其附属的边，原图变为非连通图

    void Prim(int v0); //普里姆算法

    int getRoot(int a);     //在并查集中查找根节点的函数
    void sort();            //对边集按权重进行排序
    void Kruskal(int& sum); //克鲁斯卡尔算法

    bool TopSort(); //拓扑排序
    void init();    //全部未放入

    void TopSort(int& sum, vector<int> p); //拓扑排序求所有
    void Criticalpath();                   //求关键路径
    void print_dfs(node<T>*n);

    void findMax();
    void setMax();
    void Dijkstra(int v);  //迪杰斯特拉算法
    void printPathD(int a); //打印最短路径

    void initA_Path();
    void Floyd(); //弗洛伊德算法
    void printPathF(int u, int v);
};
//深度优先搜索遍历 DFS 对于某个顶点，先访问该点，再逐个访问由以它相邻点构成的子图

int main()
{
    map<int> m;
    m.create_();
    m.Criticalpath();
    m.print_dfs(m.specific_node(1));
    cout << endl;
    cout << m.time;
    cout << endl;
    system("pause");
    return 0;
}

template <class T>
map<T>::map()
{
    n_n = 0;
    n_e = 0;
    time = 0;
}
template <class T>
void map<T>::initedges()
{
    edges.resize(n_n);
    for (int i = 0; i < n_n; i++)
        edges[i].resize(n_n);
    for (int i = 0; i < n_n; i++)
        for (int j = 0; j < n_n; j++)
            edges[i][j] = 0;
}
template <class T>
void map<T>::addedge(int x, int y)
{
    x--;
    y--;
    edge* temp = list[x]->first_e;
    edge* e_x = new edge;
    e_x->location = y;
    e_x->next_e = temp;
    list[x]->first_e = e_x;

    temp = list[y]->first_e;
    edge* e_y = new edge;
    e_y->location = x;
    e_y->next_e = temp;
    list[y]->first_e = e_y;

    edges[x][y] = 1;
    edges[y][x] = 1;
    temp = NULL;
}
template <class T>
void map<T>::create()
{
    cout << "Please input sum of node" << endl;
    cin >> n_n;
    list.resize(n_n);
    initedges();
    for (int i = 0; i < n_n; i++)
    {
        list[i] = new node<T>;
        list[i]->mark = false;
        list[i]->first_e = NULL;
        cout << "input elem of NO." << i + 1 << endl;
        cin >> list[i]->e;
    }
    system("cls");
    int x, y;
    while (true)
    {
        cout << "input two node connect by one edge,while meet '.' end " << endl;
        cout << "x  y:  " << endl;
        cin >> x >> y;
        if (!cin.good())
        {
            cin.clear();
            cin.sync();
            return;
        }
        if (x < 0 || x > n_n || y < 0 || y > n_n || edges[y - 1][x - 1] || edges[x - 1][y - 1] == 1 || x == y)
        {
            cout << "Error" << endl;
            continue;
        }
        addedge(x, y);
        system("cls");
    }
}

template <class T>
void map<T>::addedge_(int x, int y,int w)
{
    x--;
    y--;
    list[y]->count++;
    edge* temp = list[x]->first_e;
    edge* e_x = new edge;
    e_x->location = y;
    e_x->next_e = temp;
    e_x->isCritical = false;
    e_x->w = w;
    list[x]->first_e = e_x;

    edges[x][y] = w;
    temp = NULL;
}

template <class T>
void map<T>::create_()
{
    cout << "Please input sum of node" << endl;
    cin >> n_n;
    list.resize(n_n);
    initedges();
    for (int i = 0; i < n_n; i++)
    {
        list[i] = new node<T>;
        list[i]->mark = false;
        list[i]->first_e = NULL;
        list[i]->count = 0;
        cout << "input elem of NO." << i + 1 << endl;
        cin >> list[i]->e;
    }
    system("cls");
    int x, y,w;
    while (true)
    {
        cout << "input two node connect by one edge,while meet '.' end " << endl;
        cout << "x-->y weight:  " << endl;
        cin >> x >> y>>w;
        if (!cin.good())
        {
            cin.clear();
            cin.sync();
            return;
        }
        if (x < 0 || x > n_n || y < 0 || y > n_n || edges[x - 1][y - 1] !=0 || x == y)
        {
            cout << "Error" << endl;
            continue;
        }
        addedge_(x, y,w);
        system("cls");
    }
}

template <class T>
void map<T>::DFS(node<T>* n)
{
    cout << n->e;
    n->mark = true;
    edge* temp = n->first_e;
    while (temp != NULL)
    {
        if (!list[temp->location]->mark)
            DFS(list[temp->location]);
        temp = temp->next_e;
    }
}
template <class T>
void map<T>::dfs()
{
    for (int i = 0; i < n_n; i++)
        if (!list[i]->mark)
            DFS(list[i]);
}

template <class T>
int map<T>::practice1()
{
    int k = 0;
    for (int i = 0; i < n_n; i++)
        list[i]->mark = false;
    for (int i = 0; i < n_n; i++)
        if (!list[i]->mark)
        {
            DFS(list[i]);
            k++;
        }
    return k;
}

template <class T>
void map<T>::trav_pra2(int& e, int& p)
{
    for (int i = 0; i < n_n; i++)
        if (!list[i]->mark)
            practice2(list[i], e, p);

    e = e / 2;

    cout << (e == p - 1);
}
template <class T>
void map<T>::practice2(node<T>* n, int& e, int& p)
{
    p++;
    n->mark = true;
    edge* temp = n->first_e;
    while (temp != NULL)
    {
        e++;
        if (!list[temp->location]->mark)
            practice2(list[temp->location], e, p);
        temp = temp->next_e;
    }
}

template <class T>
node<T>*& map<T>::specific_node(int i)
{
    return list[i - 1];
}

template <class T>
void map<T>::BFS()
{
    node<T>* temp = list[0];
    edge* t_edge = NULL;
    cout << temp->e << " ";
    temp->mark = true;
    q.push(temp);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        t_edge = temp->first_e;
        while (t_edge != NULL)
        {
            temp = list[t_edge->location];
            if (!temp->mark)
            {
                cout << temp->e << " ";
                temp->mark = true;
                q.push(temp);
            }
            t_edge = t_edge->next_e;
        }
    }
}

template <class T>
void map<T>::assist_dfs(node<T>*& n, int& s)
{
    s++;
    n->mark = true;
    edge* t_e = n->first_e;
    while (t_e != NULL)
    {
        if (!list[t_e->location]->mark)
            assist_dfs(list[t_e->location], s);
        t_e = t_e->next_e;
    }
}
template <class T>
bool map<T>::test(node<T>*& n)
{
    int i = 1;
    n->mark = true;

    edge* temp = n->first_e;

    if (temp != NULL)
        assist_dfs(list[temp->location], i);

    return i == n_n;
}

template <class T>
void map<T>::Prim(int v0) //以v0为生成的根节点
{
    vector<int> lowcost; //某阶段生成的树到其余各结点的最小权重
    vector<int> vset;    //1代表已经放入树中，0代表未放入树中
    lowcost.resize(n_n);
    vset.resize(n_n);
    int sum = 0; //统计树的权值
    int min;
    int k;
    for (int i = 0; i < n_n; i++)
    {
        lowcost[i] = edges[v0][i];
        vset[i] = 0;
    }
    vset[v0] = 1;
    for (int i = 0; i < n_n - 1; i++)
    {
        min = 1000;
        for (int j = 0; j < n_n; j++)
        {
            if (vset[j] == 0 && min > lowcost[j])
            {
                min = lowcost[j];
                k = j;
            }
        }
        sum += sum + min;
        vset[k] = 1;
        for (int j = 0; j < n_n; j++)
        {
            if (vset[j] == 0 && lowcost[j] > edges[k][j])
                lowcost[j] = edges[k][j];
        }
    }
}

template <class T>
int map<T>::getRoot(int a)
{
    while (a != find[a])
        a = find[a];
    return a;
}

template <class T>
void map<T>::sort()
{
    for (int i = 0; i < Edges.size() - 1; i++)
        for (int j = 0; j < Edges.size() - 1 - i; j++)
            if (Edges[j].w > Edges[j + 1].w)
            {
                edge temp = Edges[j];
                Edges[j] = Edges[j + 1];
                Edges[j + 1] = temp;
            }
}

template <class T>
void map<T>::Kruskal(int& sum)
{
    for (int i = 0; i < find.size(); i++)
        find[i] = i;
    sort();
    int a;
    int b;
    for (int i = 0; i < Edges.size(); i++)
    {
        a = getRoot(Edges[i].a);
        b = getRoot(Edges[i].b);
        if (a != b)
        {
            if (a > b)
                find[a] = b;
            else
                find[b] = a;
            sum += Edges[i].w;
        }
    }
}

template <class T>
bool map<T>::TopSort()
{
    int Stack[50];
    int top = -1;
    int sum = 0;
    int v;
    int w;
    edge* t_e;
    ve.resize(list.size(), 0);
    for (int i = 0; i < list.size(); i++)
        if (list[i]->count == 0)
            Stack[++top] = i;
    while (top != -1)
    {
        v = Stack[top--];
        que.push_back(v);
        sum++;
        cout << list[v]->e;
        t_e = list[v]->first_e;

        while (t_e != NULL)
        {
            w = t_e->location;
            list[w]->count--;

            if (list[w]->count == 0)
                Stack[++top] = t_e->location;

            if (ve[w] < ve[v] + t_e->w)
                ve[w] = ve[v] + t_e->w;

            t_e = t_e->next_e;
        }
    }

    if (sum == list.size())
        return true;
    else
        return false;
}

template <class T>
void map<T>::Criticalpath()
{
    //v->w
    if (!TopSort())
        return;
    cout << endl;
    int v;
    int w;
    edge* temp;
    vl.resize(list.size(), ve[que[que.size()-1]]);
    int size = que.size();
    for (int i = size - 1; i >= 0; i--)
    {
        w = que[i];
        for (int j = 0; j < size; j++)
            if (edges[j][w] != 0)
            {
                v = j;
                if (vl[v] > vl[w] - edges[v][w])
                    vl[v] = vl[w] - edges[v][w];
            }
    }
    for (int i = 0; i < ve.size(); i++)
        cout << ve[i] << " ";
    cout << endl;
    for (int i = 0; i < vl.size(); i++)
        cout << vl[i] << " ";
    cout << endl;
    int ee;
    int el;
    for (int i = 0; i < size; i++)
    {
        v = que[i];
        temp = list[v]->first_e;
        while (temp != NULL)
        {
            w = temp->location;
            if (ve[v] == vl[v] && ve[w] == vl[w])
            {
                temp->isCritical = true;
                time += temp->w;
            }
            temp = temp->next_e;
        }
    }
}

template<class T>
void map<T>::print_dfs(node<T>* n)
{
    cout << n->e;
    edge* temp = n->first_e;
    while (temp != NULL)
    {
        if(temp->isCritical)
        print_dfs(list[temp->location]);
        temp = temp->next_e;
    }
}

template <class T>
void map<T>::init()
{
    for (int i = 0; i < list.size(); i++)
        list[i]->mark = true;
}

template <class T>
void map<T>::TopSort(int& sum, vector<int> p)
{
    if (p.size() >= list.size())
    {
        for (int i = 0; i < p.size(); i++)
            cout << p[i] + 1 << " ";

        cout << endl;
        sum++;
        return;
    }
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i]->count == 0 && list[i]->mark == true)
        {
            p.push_back(i);
            list[i]->mark = false;

            edge* temp = list[i]->first_e;
            while (temp != NULL)
            {
                list[temp->location]->count--;
                temp = temp->next_e;
            }

            TopSort(sum, p);
            list[i]->mark = true;
            temp = list[i]->first_e;
            while (temp != NULL)
            {
                list[temp->location]->count++;
                temp = temp->next_e;
            }
            p.pop_back();
        }
    }
}

template <class T>
void map<T>::findMax()
{
    int t_max = 0;
    for (int i = 0; i < Edges.size(); i++)
        if (t_max < Edges[i].w)
            t_max = Edges[i].w;
    Max = t_max + 15;
}

template <class T>
void map<T>::setMax()
{
    for (int i = 0; i < edges.size(); i++)
        for (int j = 0; j < edges.size(); j++)
            if (edges[i][j] == 0)
                edges[i][j] = Max;
}

template <class T>
void map<T>::Dijkstra(int v)
{
    int* set = new int[list.size()];
    int u;   //记录当前最短路径
    int min; //寻找当前最短路径
    //初始化
    for (int i = 0; i < list.size(); i++)
    {
        dist[i] = edges[v][i];
        set[i] = 0;
        if (edges[v][i] < Max)
            path[i] = v;
        else
            path[i] = -1;
    }
    set[v] = 1;
    path[v] = -1;
    for (int i = 0; i < list.size() - 1; i++)
    {
        min = Max;
        for (int j = 0; j < list.size(); j++)
            if (set[j] == 0 && min > dist[j])
            {
                min = dist[j];
                u = j;
            }
        set[u] = 1;
        for (int j = 0; j < list.size(); j++)
            if (set[j] == 0 && dist[u] + edges[u][j] < dist[j])
            {
                dist[j] = dist[u] + edges[u][j];
                path[j] = u;
            }
    }
}

template <class T>
void map<T>::printPathD(int a)
{
    int top = -1;
    int* stack = new int[list.size()];
    while (path[a] != -1)
    {
        stack[++top] = a;
        a = path[a];
    }
    stack[++top] = a;
    while (top != -1)
        cout << stack[top--] + 1 << " ";
}

template <class T>
void map<T>::initA_Path()
{
    A = edges;
    Path.resize(edges.size());
    for (int i = 0; i < edges.size(); i++)
        Path[i].resize(edges.size(), -1);
}

template <class T>
void map<T>::Floyd()
{
    for (int k = 0; k < A.size(); k++)
    {
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < A.size(); j++)
                if (A[i][j] > A[i][k] + A[k][j])
                {
                    A[i][j] = A[i][k] + A[k][j];
                    Path[i][j] = k;
                }
    }
}

template<class T>
void map<T>::printPathF(int u, int v)
{
    if(Path[u][v]==-1)
    {
        cout<<" "<<u<<"-->"<<v<<" ";
        return;
    }
    printPathF(u,Path[u][v]);
    printPathF(Path[u][v],v);
}