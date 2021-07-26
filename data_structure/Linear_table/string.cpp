#include <iostream>
using namespace std;
//��(string)������������ַ���ɵ��������У������ַ���
//����������:s1="a1a2����an"   s2="b1b2����bm"��������������֮һʱ��s1<s2(�����ַ�����ASCLL��Ƚ�)
//1.n<m  ��ai=bi
//2.����ĳ��k<=min(n,m)ʹ��ak<bk ����֮ǰai=bi

typedef int elemtype;
typedef int Error_code;
#define success 1
#define error 0
const int max_size = 20;

class String
{
private:
    char *data;
    int *next;

public:
    friend int Strcmp(String &s1, String &s2); //�Ƚ������ַ���
    String();
    Error_code Strassign(char *&s, const char *c); //���ַ���c��ֵ��s
    Error_code Strcopy(const char *s);             //��������
    void Strprint();
    Error_code Strclear();
    bool Strempty();
    int Strlength();
    char charAt(int rank);
    friend void Strcat(String &s, String &s1, String &s2); //��s2�ӵ�s1�󲢴洢��s��
    friend ostream &operator<<(ostream &output, String &s);
    friend int index1(String &s, String &subs);   //���Ӵ�λ��,�����㷨�汾1
    friend int index2(String &s, String &subs);   //���Ӵ�λ�ã������㷨�汾2
    bool substring(char *&str, int pos, int len); //���Ӵ�������ֵ��str(ָ����Ϊ�β���ô������ã�ǳ������)
    //bool prefix(int k,char*&ptr);//ǰ׺
    //bool suffix(int k,char*&ptr);//��׺
    void getnext();
    friend int kmp(String &p, String &t);
    ~String();
};

int main()
{
    String s, t;
    s.Strcopy("abcdefghij");
    t.Strcopy("abij");
    t.getnext();
    cout << kmp(s, t) << endl;
    system("pause");
    return 0;
}

String::String()
{
    data = NULL;
}

Error_code String::Strassign(char *&s, const char *c) //ָ���βδ�����ǵ�ַ�����ı��βεĵ�ַ����ʵ�ε�ַ����ı䣬��Ϊ�β���ʵ�α���Ϊ��������,����������
{
    if (s != NULL)
        delete s;

    int num = sizeof(c) / sizeof(char);
    s = new char[num];
    for (int i = 0; i < num; i++)
        s[i] = c[i];
    return success;
}

Error_code String::Strcopy(const char *s)
{
    if (data != NULL)
        delete[] data;
    int i;
    int len = 0;
    for (int j = 0; s[j] != '\0'; j++)
        len++;
    data = new char[len + 1];
    for (i = 0; i < len; i++)
        data[i] = s[i];
    data[i] = '\0';
    return success;
}

void String::Strprint()
{
    cout << data;
}

Error_code String::Strclear()
{
    if (data == NULL)
        return error;
    delete[] data;
    data = NULL;
    return success;
}

bool String::Strempty()
{
    if (data == NULL)
        return true;
    return false;
}

int String::Strlength()
{
    if (data == NULL)
        return -1;
    int sum = 0;
    for (int i = 0; data[i] != '\0'; i++)
        sum++;
    return sum;
}

int Strcmp(String &s1, String &s2)
{
    int length1 = s1.Strlength();
    int length2 = s2.Strlength();
    for (int j = 0; j < length1 && j < length2; j++)
        if (s1.data[j] != s2.data[j])
            return s1.data[j] - s2.data[j];

    return length1 - length2;
}

ostream &operator<<(ostream &output, String &s) //�����ã�ֻ��һ�����������
{
    if (s.data == NULL)
    {
        output << "Wrong" << endl;
        return output;
    }

    output << s.data << endl;
    return output;
}

void Strcat(String &s, String &s1, String &s2)
{
    if (s.data != NULL)
        delete[] s.data;
    s.data = NULL;
    int length1 = s1.Strlength();
    int length2 = s2.Strlength();
    s.data = new char[length1 + length2 + 1];
    for (int i = 0; i < length1; i++)
        s.data[i] = s1.data[i];
    for (int i = 0; i < length2; i++)
        s.data[i + length1] = s2.data[i];
    s.data[length1 + length2] = '\0';
}

bool String::substring(char *&str, int pos, int len)
{
    if (pos < 1 || pos > this->Strlength() || len < 0 || len > this->Strlength() - pos + 1)
        return false;
    if (str != NULL)
        delete[] str;
    if (len == 0)
    {
        str = new char('\0');
        return true;
    }

    else
    {
        str = new char[len + 1];
        for (int i = pos - 1, j = 0; i <= pos + len - 2; i++, j++)
            str[j] = data[i];
        str[len] = '\0';
        return true;
    }
}

String::~String()
{
    delete[] data;
    data = NULL;
}

int index1(String &s, String &subs)
{
    int i = 0, j = 0;
    int k = i;
    int len1 = s.Strlength();
    int len2 = subs.Strlength();
    while (i < len1 && j < len2)
    {
        if (s.data[i] == subs.data[j])
        {
            i++;
            j++;
        }
        else
        {
            j = 0;
            i = ++k;
        }
    }

    if (j >= len2)
        return k;
    else
        return -1;
}

int index2(String &s, String &subs)
{
    int n = s.Strlength();
    int m = subs.Strlength();
    int i, j;
    for (i = 0; i < n - m + 1; i++)
    {
        for (j = 0; j < m; j++)
            if (s.data[i + j] != subs.data[j])
                break;
        if (j >= m)
            break;
    }
    return i;
}

char String::charAt(int rank)
{
    return data[rank];
}

void String::getnext()
{
    int len = Strlength();
    next = new int[len];
    int k = -1;
    int j = 0;
    next[0] = -1;
    while (j < len - 1)
    {
        if (k == -1 || data[k] == data[j])
            next[++j] = ++k;
        else
            k = next[k];
    }
}

int kmp(String &p, String &t)
{
    int len1 = p.Strlength();
    int len2 = t.Strlength();
    int i = 0;
    int j = 0;
    while (len1 - i >= len2 - j)
    {
        if (j == -1 || p.data[i] == t.data[j])
        {
            i++;
            j++;
        }

        else
            j = t.next[j];

        if (j >= len2)
            return i - j;
    }
    return -1;
}