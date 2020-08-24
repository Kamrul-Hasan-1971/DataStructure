#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int prec(char c)
{
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s)
{
    stack<char> st;
    int l = s.length();
    string ans="";
    for(int i = 0; i < l; i++)
    {
        if(s[i]==' ')
            continue;
        else if(s[i]=='^')
            st.push('^');
        else if(isalnum(s[i]))
            ans+=s[i];
        else if(s[i] == '(')
            st.push('(');
        else if(s[i] == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            if(!st.empty())
                st.pop();
            else
                return "-1";
        }
        else
        {
            //ans+=' ';
            while(!st.empty())
            {
                if(st.top()=='(')
                    break;
                if(prec(st.top())<prec(s[i]))
                    break;
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        if(st.top()=='(')
            return "-1";
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main()
{
    int T,i;
    cin >> T ;
    for( i = 0 ; i < T ; i++)
    {
        string exp;
        if(i==0)
            getchar();
        getline(cin,exp);
        cout<<infixToPostfix(exp)<<endl;
    }
    return 0;
}
