#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        char*t=new char[s.size()];
        int top=-1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            t[++top]=s[i];
            else
            {
                switch(s[i])
                {
                    case ')':
                    {
                        if(t[top]=='(')
                        top--;
                        else
                        return false;
                    }
                    case ']':
                    {
                        if(t[top]=='[')
                        top--;
                        else
                        return false;
                    }
                    case '}':
                    {
                        if(t[top]=='{')
                        top--;
                        else
                        return false;
                    }
                }
            }
        }
        if(top==-1)return true;
        else return false;
    }
};
int main()
{
    Solution().isValid("()");
    system("pause");
    return 0;
}