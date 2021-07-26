#include <iostream>
using namespace std;
int dic[256];
int*suffix;
bool*prefix;
void init(string &p)
{
    int len = p.length();
    for (int i = 0; i < len; i++)
        dic[(int)p[i]] = i;
}

void generate(string&p)
{
    
}


int main()
{
    for (int i = 0; i < 256; i++)
        dic[i] = -1;

    system("pause");
    return 0;
}