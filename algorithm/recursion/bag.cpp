#include <iostream>
using namespace std;

void print(int b[], int n)
{
    for (int i = 0; i <= n; i++)
        cout << b[i] << " ";
}

void bag(int S1, int S, int n[], int b[], int step, int k, int num)
{
    if (step>=num)
        return;
    else
    {
        if (S1 + n[step] == S)
        {
            b[k] = n[step];
            print(b, k);
            cout << endl;
            return;
        }     
        else if (S1 + n[step] < S)
        {
            b[k] = n[step];
            bag(S1 + n[step], S, n, b, step + 1, k + 1, num);
        }

        bag(S1, S, n, b, step + 1, k, num);
    }
}

int main()
{
    int S=50;
    int num=10;
    int n[]={29,26,18,16,13,10,8,5,3,1};
    int b[10];
    int S1=0;
    bag(S1,S,n,b,0,0,num);
    system("pause");
    return 0;
}