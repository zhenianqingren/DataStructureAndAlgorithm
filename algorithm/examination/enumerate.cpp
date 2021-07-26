#include <iostream>
using namespace std;
//炸弹人

//火柴棍等式
//由于题目中已经给出，最多有24根火柴，而等号和加号各用4根的前提下，A\B\C三个数则总共只有20根火柴，
//数据范围较小，可以用枚举法枚举A、B。这个时候我们发现，0-9这10个数字所用的火柴数为：6,2,5,5,4,5,6,3,7,6，
//很明显数字1用的火柴棒最少只要2根，不妨让B为1，那么A和C最多可以使用18根火柴，
//而C>=A，满足条件的A的最大取值为1111。所以枚举A和B的范围是从0~1111
int f[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int func(int x)
{
    int num = 0;
    if (x == 0)
        num = 6;
    else
        while (x != 0)
        {
            num += f[x % 10];
            x = x / 10;
        }
    return num;
}

int main()
{
    /* char a[20][21];
    int i, j, sum, map = 0, p, q, x, y, n, m;
    cin >> n >> m;
    //n代表地图有多少行 m代表地图有多少列
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];
    //两重循环枚举地图所有点
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            //首先判断是不是平地
            if (a[i][j] == '.')
            {
                sum = 0; //计数
                x = i;
                y = j;
                while (a[x][y] != '#') //判断是不是墙
                {
                    if (a[x][y] == 'G')
                        sum++;
                    x--; //向上统计
                }
                x = i;
                y = j;
                while (a[x][y] != '#')
                {
                    if (a[x][y] == 'G')
                        sum++;
                    x++; //向下统计
                }
                x = i;
                y = j;
                while (a[x][y] != '#')
                {
                    if (a[x][y] == 'G')
                        sum++;
                    y--; //向左统计
                }
                x = i;
                y = j;
                while (a[x][y] != '#')
                {
                    if (a[x][y] == 'G')
                        sum++;
                    y++; //向右统计
                }
                if (sum > map)
                {
                    map = sum; //更新最大值
                    p = i;     //保存坐标
                    q = j;
                }
            }
        }
    cout << p << " , " << q << endl; */

    int a, b, c, m;
    cin >> m;
    for (a = 0; a <= 1111; a++)
        for (b = 0; b <= 1111; b++)
        {
            c = a + b;
            if (func(a) + func(b) + func(c) == m - 4)
                cout << "a=" << a << "b=" << b << "c=" << c << endl;
        }
    system("pause");
    return 0;
}