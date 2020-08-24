#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll fun(char op)
{
    if(op == '+'||op == '-')return 1;
    if(op == '*'||op == '/')return 2;
    return 0;
}
ll applyOp(ll a, ll b, char op)
{
    if(op=='+') return a+b;
    if(op=='-') return a-b;
    if(op=='*') return a*b;
    if(op=='/')
    {
        if(b==0) return -1;
        return a/b;
    }
    return -1;
}
void fun2(stack<ll>&values,stack<char>&ops)
{
    ll val2 = values.top();
    values.pop();
    ll val1 = values.top();
    values.pop();
    char op = ops.top();
    ops.pop();
    values.push(applyOp(val1, val2, op));
}
ll evaluate(string s1)
{
    stack <ll> values;
    stack <char> ops;
    for(ll i = 0; i < s1.size(); i++)
    {
        if(s1[i] == ' ') continue;
        else if(s1[i] == '(') ops.push(s1[i]);
        else if(isdigit(s1[i]))
        {
            ll val = 0;
            while(i < s1.size() && isdigit(s1[i]))
            {
                val = (val*10) + (s1[i]-'0');
                i++;
                //break;//for single digit
            }
            i--;
            values.push(val);
        }
        else if(s1[i] == ')')
        {
            while(!ops.empty() && ops.top() != '(')
            {
                if(values.size()<2) return -1;
                fun2(values,ops);
            }
            if(!ops.empty()) ops.pop();
            else return -1;
        }
        else
        {
            while(!ops.empty() && fun(ops.top()) >= fun(s1[i]))
            {
                if(values.size()<2) return -1;
                fun2(values,ops);
            }
            ops.push(s1[i]);
        }
    }
    while(!ops.empty())
    {
        if(values.size()<2) return -1;
        fun2(values,ops);
    }
    if(values.size()>1) return -1;
    return values.top();
}

int main()
{
    cout << evaluate("10 + 2 * 6") << "\n";
    cout << evaluate("100 * 2 + 12") << "\n";
    cout << evaluate("100 * ( 2 + 12 )") << "\n";
    cout << evaluate("100 * ( 2 + 12 ) / 14");
    return 0;
}
