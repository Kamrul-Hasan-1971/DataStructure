#include<bits/stdc++.h>
using namespace std;
#define           ll                 long long int
#define           MX                 30004
#define           all(v)             v.begin(),v.end()
ll ara[MX+3];
vector<ll>tree[4*MX+1];
void built( ll n, ll a, ll b )
{
    if( a > b ) return;
    if( a == b )
    {
        tree[n].push_back(ara[a]) ;
        return ;
    }
    ll l = (n << 1),r = ( n << 1)+ 1 ,m = ( a + b ) / 2 ;
    built( l, a, m ) ;
    built( r, m+1, b ) ;
    merge(all(tree[l]),all(tree[r]),back_inserter(tree[n]));
}
ll query( ll n, ll a, ll b, ll i, ll j,ll key)
{
    if( a > b || i > b || j < a ) return 0 ;
    if( a >= i  && b <= j )
    {
        ll x = upper_bound(all(tree[n]),key)-tree[n].begin();
        ll p = tree[n].size();
        return p-x;
    }
    ll l = (n << 1),r = ( n << 1)+ 1 ,m = ( a + b ) / 2 ;
    ll r1 = query( l, a, m, i, j, key) ;
    ll r2 = query( r, m+1, b, i, j,key) ;
    return r1+r2 ;
}
int main()
{
    ll i, n, j,a,b,k;
    scanf("%lld", &n ) ;
    for( i = 1 ; i <= n ; i++ ) scanf("%lld",&ara[i]);
    built( 1, 1, n ) ;
    scanf("%lld%lld%lld",&a,&b,&k);
    printf("%lld\n",query(1,1,n,a,b,k));
    return 0 ;
}


//https://www.spoj.com/problems/KQUERY/
