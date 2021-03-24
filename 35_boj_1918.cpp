#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);
    
    char oper[6] = {'+', '-', '*', '/','(',')'};
    stack<char> st;
    vector<char> v;
    string s;

    cin >> s;
    int leng = s.length();

    for (int i=0; i<leng; i++)
    {   
        // puts("=============================");
        // for (auto iter=v.begin(); iter != v.end(); iter++)
        // {
        //     printf("%c ", *iter);
        // }
        // puts("");
        // puts("=============================");

        if ('A' <= s[i] && s[i] <= 'Z')
        {
            v.push_back(s[i]);
        }
        else
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else if (s[i] == '*' || s[i] == '/')
            {
                while (!st.empty() && (st.top()=='*' || st.top()=='/'))
                {
                        v.push_back(st.top());
                        st.pop();
                }
                st.push(s[i]);
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                while (!st.empty() && st.top() != '(')
                {
                        v.push_back(st.top());
                        st.pop();
                }
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                        v.push_back(st.top());
                        st.pop();
                }
                st.pop();
            }
        }
    }

    while (!st.empty())
    {
        v.push_back(st.top());
        st.pop();
    }

    for (auto iter=v.begin(); iter != v.end(); iter++)
    {
        printf("%c", *iter);
    }

    return 0;
}

/*

4*(5+2)

*/