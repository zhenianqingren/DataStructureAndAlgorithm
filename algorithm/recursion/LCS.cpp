#include <iostream>
#include <string>
using namespace std;

int LCS(string s, string t, int n_s, int n_t)
{
    if (n_s >= (int)s.length() || n_t >= (int)t.length())
        return 0;

    if (s[n_s] == t[n_t])
        return LCS(s, t, n_s + 1, n_t + 1) + 1;

    else
        return LCS(s, t, n_s + 1, n_t) > LCS(s, t, n_s, n_t + 1) ? LCS(s, t, n_s + 1, n_t) : LCS(s, t, n_s, n_t + 1);
}

int main()
{
    string s = "abcdefg";
    string t = "befghijklmn";
    cout << LCS(s, t, 0, 0) << endl;

    //LCS迭代
    const int ns = s.length();
    const int nt = t.length();
    //s作为列数
    //t作为行数
    int lcs[nt + 1][ns + 1];
    for (int i = 0; i <= nt; i++)
        lcs[i][0] = 0;
    for (int i = 0; i <= ns; i++)
        lcs[0][i] = 0;

    for (int i = 1; i <= nt; i++)
        for (int j = 1; j <= ns; j++)
        {
            if (s[j - 1] == t[i - 1])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = lcs[i - 1][j] > lcs[i][j - 1] ? lcs[i - 1][j] : lcs[i][j - 1];
        }
    cout << lcs[nt][ns] << endl;
    system("pause");
    return 0;
}