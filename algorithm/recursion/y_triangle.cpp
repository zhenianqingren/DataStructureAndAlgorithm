//递归方式求杨辉三角
#include <iostream>
using namespace std;
int Y(int i, int n)
{
    if (i == 1 || i == n)
        return 1;

    else
        return Y(i - 1, n - 1) + Y(i, n - 1);
}
int main()
{
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << Y(j, i) << " ";

        cout << endl;
    }

    system("pause");
    return 0;
}