#include<bits/stdc++.h>
using namespace std;
#define ll long long int

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
ll evaluate(string s1)
{
    stack <ll> values;
    int sz = s1.size();
    for(ll i = sz-1; i >= 0; i--)
    {
        if(s1[i] == ' ') continue;
        else if(isdigit(s1[i]))
        {
            ll val = 0,ini = 1;
            while(i < s1.size() && isdigit(s1[i]))
            {
                val +=  (s1[i]-'0')*ini;
                ini*=10;
                i--;
               // break;//for single digit;
            }
            i++;
            values.push(val);
        }
        else
        {
            if(values.size()<2) return -1;
            ll val1 = values.top();
            values.pop();
            ll val2 = values.top();
            values.pop();
            values.push(applyOp(val1,val2,s1[i]));
        }
    }
    if(values.size()>1) return -1;
    return values.top();
}


int main()
{
    int T ,i;
    cin >> T ;
	for( i = 0 ; i < T ; i++){
        string exp;
        if(i==0) getchar();
        getline(cin,exp);
        cout<<evaluate(exp)<<endl;
	}
	return 0;
}
