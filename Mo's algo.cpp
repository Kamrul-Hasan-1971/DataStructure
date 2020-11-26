#include<bits/stdc++.h>
using namespace std;
#define  ll   long long int
const ll MX = 100005;
ll K, ans[MX], a[MX], sum,cnt[MX];
struct Query
{
    ll indx, L, R;
    bool operator<(const Query& other)
    {
        return L/K < other.L/K || (L/K == other.L/K && R<other.R);
    }

}query[MX];

void add(ll indx)
{
    ll x = ++cnt[a[indx]];
    if(x==1) sum++;
}
void del(ll indx)
{
    ll x = --cnt[a[indx]];
    if(x==0) sum--;
}

int main()
{
    ll T,j;
    scanf("%lld",&T);
    for( j = 1 ; j<= T ; j++)
    {
        ll i, n, q, L=1, R=0;
        scanf("%lld%lld",&n,&q);
        K = sqrt(n);
        for(i=1; i<=n; i++) scanf("%lld",&a[i]);
        for(i=1; i<=q; i++)
        {
            scanf("%lld%lld",&query[i].L,&query[i].R);
            query[i].indx = i;
        }
        sort(query+1, query+q+1);
        sum=0;
        for(i=1; i<=q; i++)
        {
            while(R<query[i].R) add(++R);
            while(L<query[i].L) del(L++);
            while(R>query[i].R) del(R--);
            while(L>query[i].L) add(--L);
            ans[query[i].indx] = sum;
        }
        printf("Case %lld:\n",j);
        for(ll i=1; i<=q; i++) printf("%lld\n",ans[i]);
        memset(cnt,0,sizeof cnt);
    }
    return 0;
}
//http://lightoj.com/volume_showproblem.php?problem=1188
