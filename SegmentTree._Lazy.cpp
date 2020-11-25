/*Lazy te max,min ber korar time e upadte value er er multiplictaion part bad jabey..
tree[node]+=((b-a+1)*lazy[node]); --> tree[node] += lazy[node] ;
tree[node]+=((b-a+1)*newValue);---> tree[node]+=newValue;*/

#include<bits/stdc++.h>
using namespace std;
#define           ll                 long long int
#define           MX                 100005
#define           inf                LLONG_MAX
#define           zero(a)            memset(a,0,sizeof a)
ll tree[MX*3], ara[MX], lazy[MX*3];
void build( ll node, ll a, ll b )
{
    if( a > b ) return ;
    if( a == b )
    {
        tree[node] = ara[a] ;
        return ;
    }
    ll left = (node<<1),right = (node<<1)+1,mid = (a+b)>>1 ;
    build( left, a, mid ) ;
    build( right, mid+1, b ) ;
    tree[node] = tree[left] + tree[right];
}

ll query( ll node, ll a, ll b, ll i, ll j )
{
    ll left = (node<<1),right = (node<<1)+1,mid = (a+b)>>1 ;
    if( lazy[node]!=0)
    {
        tree[node]+=((b-a+1)*lazy[node]);
        if(a!=b)
        {
            lazy[left] += lazy[node];
            lazy[right] += lazy[node];
        }
        lazy[node]=0;
    }
    if( a > b || a > j || b < i ) return 0 ;
    if(a>=i && b <= j) return tree[node];
    ll q1 = query(left, a, mid, i, j ) ;
    ll q2 = query(right, mid+1, b, i, j ) ;
    return q1+q2 ;
}

void update( ll node, ll a, ll b, ll i, ll j,ll newValue)
{
    ll left = (node<<1),right = (node<<1)+1,mid = (a+b)>>1 ;
    if( lazy[node] != 0 )
    {
        tree[node] += ((b-a+1)*lazy[node]) ;
        if( a!=b )
        {
            lazy[left] += lazy[node];
            lazy[right] += lazy[node];
        }
        lazy[node]=0;
    }
    if( a > b || a > j || b < i ) return ;
    if( a>=i && b <=j )
    {
        tree[node]+=((b-a+1)*newValue);
        if(a!=b)
        {
            lazy[left] += newValue ;
            lazy[right] += newValue ;
        }
        return ;
    }
    update( left, a, mid, i, j, newValue ) ;
    update( right, mid+1, b, i, j, newValue ) ;
    tree[node]=tree[left]+tree[right];
}

int main()
{
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&ara[i]);
    build(1,1,n);
    memset(lazy,0,sizeof(lazy));
    update(1,1,n, 11,n,100);
    ll ans=query(1,1,n,1,n);
    cout<<ans<<endl;
    return 0;
}
