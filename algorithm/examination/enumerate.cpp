#include <iostream>
using namespace std;
//ը����

//������ʽ
//������Ŀ���Ѿ������������24����񣬶��ȺźͼӺŸ���4����ǰ���£�A\B\C���������ܹ�ֻ��20�����
//���ݷ�Χ��С��������ö�ٷ�ö��A��B�����ʱ�����Ƿ��֣�0-9��10���������õĻ����Ϊ��6,2,5,5,4,5,6,3,7,6��
//����������1�õĻ�������ֻҪ2����������BΪ1����ôA��C������ʹ��18�����
//��C>=A������������A�����ȡֵΪ1111������ö��A��B�ķ�Χ�Ǵ�0~1111
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
    //n�����ͼ�ж����� m�����ͼ�ж�����
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];
    //����ѭ��ö�ٵ�ͼ���е�
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            //�����ж��ǲ���ƽ��
            if (a[i][j] == '.')
            {
                sum = 0; //����
                x = i;
                y = j;
                while (a[x][y] != '#') //�ж��ǲ���ǽ
                {
                    if (a[x][y] == 'G')
                        sum++;
                    x--; //����ͳ��
                }
                x = i;
                y = j;
                while (a[x][y] != '#')
                {
                    if (a[x][y] == 'G')
                        sum++;
                    x++; //����ͳ��
                }
                x = i;
                y = j;
                while (a[x][y] != '#')
                {
                    if (a[x][y] == 'G')
                        sum++;
                    y--; //����ͳ��
                }
                x = i;
                y = j;
                while (a[x][y] != '#')
                {
                    if (a[x][y] == 'G')
                        sum++;
                    y++; //����ͳ��
                }
                if (sum > map)
                {
                    map = sum; //�������ֵ
                    p = i;     //��������
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