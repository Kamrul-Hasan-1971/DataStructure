#include<bits/stdc++.h>
using namespace std;

#define  ll                 int
#define  pb                 push_back
#define  all(v)             v.begin(),v.end()
#define  pii                pair<ll,ll>
ll block,ara[300002],u,n,sz;
vector<pii>v1[700];
void build()
{
    for(ll i=0; i<n; i++) v1[i/block].pb({ara[i],i});
    sz = (n-1)/block;
    for(ll i=0; i<=sz; i++) sort(all(v1[i]));
}
ll query(ll L, ll R, ll v)
{
    ll cnt=0;
    while(L<=R && L%block) cnt+=(ara[L++]<=v);
    while(L+block<=R)
    {
        cnt+=upper_bound(all(v1[L/block]),make_pair(v,R))-v1[L/block].begin();
        L+=block;
    }
    while(L<=R) cnt+=(ara[L++]<=v);
    return cnt ;
}
void update(ll indx,ll val,ll pre)
{
    ll x = lower_bound(all(v1[indx/block]),make_pair(pre,indx))-v1[indx/block].begin();
    v1[indx/block][x].first=ara[indx]=val;
    sort(all(v1[indx/block]));
}
int main()
{
    ll  i,j,m,a,l,r,indx,val,type,L,R,v,p;
    scanf("%d%d%d",&n,&m,&u);
    block = sqrt(n);
    for( i = 0 ; i < n ; i++ ) scanf("%d",&ara[i]);
    build();
    for( i = 0 ; i < m ; i++)
    {
        scanf("%d%d%d%d",&L,&R,&v,&p);
        L--,R--,p--,v--;
        long long int x = query(L,R,v);
        x*=u;
        x/=(R-L+1);
        update(p,x,ara[p]);
    }
    for( i = 0 ; i < n ; i++) printf("%d\n",ara[i]);
    return 0 ;
}
