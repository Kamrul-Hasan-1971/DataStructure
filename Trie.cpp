#include<bits/stdc++.h>
using namespace std;
#define ll int
#define pii pair<string,ll>
#define CIN   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
string s1 ;
struct node
{
    ll endmark,mx;
    string ans ;
    node* next[26 + 1];
    node()
    {
        endmark = 0,mx=0;
        for (ll i = 0; i < 26; i++)
            next[i] = NULL;
    }
} * root;
ll add(node *cur,ll pos)
{
    ll id = s1[pos]-'a';
    if(cur->next[id]==NULL)
        cur->next[id]=new node();
    cur=cur->next[id];
    if(pos+1==s1.size())
    {
        cur->endmark++;
        if(cur->endmark>=cur->mx){
            cur->mx=cur->endmark;
            cur->ans=s1;
        }
        return cur->endmark;
    }
    else
    {
        ll cnt = add(cur,pos+1);
        if(cnt>cur->mx)
        {
            cur->mx=cnt;
            cur->ans=s1;
        }
        else if(cnt==cur->mx&&cur->ans>s1){
            cur->ans=s1;
        }
        return cnt;
    }
}
pii search()
{
    node* cur = root;
    ll len = s1.size();
    for (ll i = 0; i < len; i++)
    {
        ll id = s1[i] - 'a';
        if (cur->next[id] == NULL) return {"-1",0};
        cur = cur->next[id];
    }
    return {cur->ans,cur->mx};
}
void del(node* cur)
{
    for (ll i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);
    delete (cur);
}
int main()
{
    CIN;
    ll n, q, i ;
    cin>>n;
    root = new node();
    for( i = 1 ; i<= n ; i++)
    {
        cin >> s1 ;
        add(root,0);
    }
    cin >>q;
    for (i = 1; i <= q; i++)
    {
        cin>>s1;
        pii x = search();
        if(x.second==0) cout<<"Case "<<i<<": "<<-1<<endl;
        else cout<<"Case "<<i<<": "<<x.first<<" "<<x.second<<endl;
    }
    //if memory limit
    //del(root);
    return 0;
}
https://toph.co/p/the-punishment/
