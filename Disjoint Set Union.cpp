#include<bits/stdc++.h>
using namespace std;
#define           ll               long long int
#define           mx               100000
ll parent[mx];
void initialization(ll n)
{
    for(ll i=0; i<=n; i++) parent[i]=i;
}
ll findParent(ll x)
{
    if(x != parent[x]) return parent[x]=findParent(parent[x]);
    return x;
}
void unionSet(ll x,ll y)
{
    ll px= findParent(x);
    ll py= findParent(y);
    if(px!=py) parent[py]=px;
}
int main()
{
    ll n,i;
    cin>>n;
    initialization(n);
    unionSet(2,5);
    for(i=1;i<=n;i++) findParent(i);
    for(i=1;i<=n;i++) cout<<parent[i]<<" ";
    return 0;
}
