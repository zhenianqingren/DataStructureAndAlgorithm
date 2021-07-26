#include <iostream>
using namespace std;

void hanio(char left, char mid, char right, int n)
{
    if (n == 1)
    {
        cout << left << "->" << right << endl;
        return;
    }

    else
    {
        hanio(left, right, mid, n - 1);
        cout << left << "->" << right << endl;
        hanio(mid, left, right, n - 1);
    }
}

int main()
{
    int n=3;
    hanio('A','B','C',n);
    system("pause");
    return 0;
}