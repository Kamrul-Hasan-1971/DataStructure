#include<bits/stdc++.h>
using namespace std;

int prec(char c)
{
	if(c == '^') return 3;
	else if(c == '*' || c == '/') return 2;
	else if(c == '+' || c == '-') return 1;
	else return -1;
}

string infixToPostfix(string s)
{
	std::stack<char> st;
	int l = s.length();
	string ans="";
	for(int i = 0; i < l; i++)
	{
	    if(s[i]==' ') continue;
		else if(isalpha(s[i])) ans+=s[i];
		else if(s[i] == '(') st.push('(');
		else if(s[i] == ')')
		{
			while(!st.empty() && st.top() != '(')
			{
				ans += st.top();
				st.pop();
			}
			if(!st.empty()) st.pop();
			else return "-1";
		}
		else{
			while(!st.empty() && prec(s[i]) <= prec(st.top()))
			{
				ans += st.top();
				st.pop();
			}
			st.push(s[i]);
		}

	}
	while(!st.empty())
	{
		ans += st.top();
		st.pop();
	}
	return ans;
}

int main()
{
	string exp = "a+b*(c^d-e)^(f+g*h)-i";
	cout<<infixToPostfix(exp);
	return 0;
}

