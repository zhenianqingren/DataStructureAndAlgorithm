#include <iostream>
#include <string>
using namespace std;
int dic[256];

void init(string s)
{
    for (int i = 0; i < (int)s.length(); i++)
        dic[(int)s[i]] = i;
}

int sunday(string &t, string &p)
{
    int lent = t.length();
    int lenp = p.length();
    int i = 0, j = 0;
    int next = i + lenp;
    int rank = i;
    while (i < lent && j < lenp)
    {
        while ((i < lent && j < lenp) && t[i] == p[j])
        {
            i++;
            j++;
        }
        if (j >= lenp && i <= lent)
            return rank;

        if (dic[(int)t[next]] == -1)
        {
            i = next + 1;
            j = 0;
            next = i + lenp;
            rank = i;
        }
        else
        {
            i = next - dic[(int)t[next]];
            j = 0;
            next = i + lenp;
            rank = i;
        }
    }
    return -1;
}

int main()
{
    for (int i = 0; i < 256; i++)
        dic[i] = -1;
    string t = "abcdefghi";
    string p = "hijk";
    init(p);
    cout << sunday(t, p) << endl;
    system("pause");
    return 0;
}