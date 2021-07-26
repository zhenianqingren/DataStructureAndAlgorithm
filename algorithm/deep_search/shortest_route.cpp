#include <iostream>
using namespace std;

int book[50][50];
int Next[4][2] = {
    {0, 1},  //右
    {1, 0},  //下
    {-1, 0}, //左
    {0, -1}  //上
};

void defs(int x, int y, int step, int p, int q, int &min, int **a, int n, int m)
{
    if (x == p && y == q)
    {
        if (step < min)
            min = step;
        return;
    }

    for (int k = 0; k < 4; k++)
    {
        int tx = x + Next[k][0];
        int ty = y + Next[k][1];
        if (tx < 0 || tx >= n || ty < 0 || ty >= m)
            continue;
        if (a[tx][ty] == 0 && book[tx][ty] == 0)
        {
            book[tx][ty] = 1;
            defs(tx, ty, step + 1, p, q, min, a, n, m);
            book[tx][ty] = 0;
        }
    }
}

int main()
{
    for (int i = 0; i <50; i++)
        for (int j = 0; j <50; j++)
            book[i][j] = 0;
    int min = 1000;
    int n;
    cin >> n;
    int m;
    cin >> m;
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    book[0][0]=1;
    defs(0, 0, 0, 3, 2, min, a, n, m);
    cout << min << endl;
    system("pause");
    return 0;
}