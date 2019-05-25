#include<bits/stdc++.h>
using namespace std;
#define           ll               long long int
#define           pb               push_back
#define           pii              pair<ll,ll>
#define           mx               100000


ll parent[mx];
ll rankParent[mx];

void initialization(ll n)
{
    for(ll i=0; i<n; i++)
    {
        parent[i]=i;
        rankParent[i]=0;
    }
}


ll findParent(ll x)
{
    if(x != parent[x])
    {
        return parent[x]=findParent(parent[x]);
    }
    else
    {
        return x;
    }
}

void unionSet(ll x,ll y)
{
    ll px= findParent(x);
    ll py= findParent(y);

    if(px==py)
        return;

    if(rankParent[px]<rankParent[py])
    {
        parent[px]=py;
    }
    else if(rankParent[px]>rankParent[py])
    {
        parent[py]=px;
    }
    else
    {
        parent[py]=px;
        rankParent[x]++;
    }
}


void printSet(ll n)
{
    for(ll i=0; i<n; i++)
    {
        cout<<"Node is "<< i << " Parent is "<< parent[i] <<" Rank is "<<rankParent[i]<<endl;
    }
    cout<<endl;
}

int main()
{
    ll n;
    cin>>n;
    initialization(n);

    unionSet(0,1);
    unionSet(4,2);
    unionSet(3,3);
    unionSet(0,3);
    unionSet(0,4);

    printSet(n);
    return 0;
}
