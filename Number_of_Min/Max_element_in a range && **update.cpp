#include<bits/stdc++.h>
using namespace std;
#define  ll                 long long int
#define  pb                 push_back
#define  all(v)             v.begin(),v.end()
#define  pii                pair<ll,ll>
ll seg_size,ara[300002],u,n,sz;
vector<pii>v1[700];
void build()
{
    for(ll i=0; i<n; i++) v1[i/seg_size].pb({ara[i],i});
    sz = (n-1)/seg_size;
    for(ll i=0; i<=sz; i++) sort(all(v1[i]));
}
ll query(ll L, ll R, ll v)
{
    ll cnt=0;
    while(L<=R && L%seg_size) cnt+=(ara[L++]<=v);
    while(L+seg_size<=R)
    {
        ll block = L/seg_size;
        cnt+=upper_bound(all(v1[block]),make_pair(v,R))-v1[block].begin();
        L+=seg_size;
    }
    while(L<=R) cnt+=(ara[L++]<=v);
    return cnt ;
}
void update(ll indx,ll val,ll pre)
{
    ll block = indx/seg_size;
    ll x = lower_bound(all(v1[block]),make_pair(pre,indx))-v1[block].begin();
    v1[block][x].first=ara[indx]=val;
    sort(all(v1[block]));
}
int main()
{
    ll  i,j,m,a,l,r,indx,val,type,L,R,v,p;
    scanf("%lld%lld%lld",&n,&m,&u);
    seg_size = sqrt(n);
    for( i = 0 ; i < n ; i++ ) scanf("%lld",&ara[i]);
    build();
    for( i = 0 ; i < m ; i++)
    {
        scanf("%lld%lld%lld%lld",&L,&R,&v,&p);
        L--,R--,p--,v--;
        ll x = query(L,R,v);
        x*=u;
        x/=(R-L+1);
        update(p,x,ara[p]);
    }
    for( i = 0 ; i < n ; i++) printf("%lld\n",ara[i]);
    return 0 ;
}
