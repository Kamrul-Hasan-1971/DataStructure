//https://rezwanarefin01.github.io/posts/block-decomposition-01/
//https://www.spoj.com/problems/XXXXXXXX/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MX 50004
#define Q  100005
ll S,ml=0,mr=-1,t=0,cur=0,b[MX],cnt[MX],org[MX],a[MX],au[MX],res[Q];
unordered_map<ll,ll>cmp;
struct query
{
    ll l,r,t,i;
    bool operator<(const query&o)const
    {
        if(l/S!=o.l/S) return l<o.l;
        if(r/S!=o.r/S) return r<o.r;
        return t<o.t;
    }
} q[Q];
struct updt
{
    ll i, nxt, prv;
} u[Q];
void add(ll i)
{
    if(cnt[a[i]]==0) cur+=org[a[i]];
    cnt[a[i]]++;
}
void del(ll i)
{
    if(cnt[a[i]]==1) cur-=org[a[i]];
    cnt[a[i]]--;
}
void updo(ll i)
{
    ll j=u[i].i, nxt=u[i].nxt;
    if(j>=ml and j<=mr) del(j);
    a[j]=nxt;
    if(j>=ml and j<=mr) add(j);
}
void undo(ll i)
{
    ll j=u[i].i, prv=u[i].prv;
    if(j>=ml and j<=mr) del(j);
    a[j]=prv;
    if(j>=ml and j<=mr)add(j);
}
int main()
{
    ll i,n, m, c,su=0, sq=0, l, r,ini=1,indx,newval;
    char ch;
    scanf("%lld",&n);
    S = n/cbrt(n);
    // i dont know why compression needed!!
    for(ll i=0; i<n; ++i)
    {
        scanf("%lld",&a[i]);
        if(!cmp.count(a[i]))
        {
            org[ini]=a[i];
            cmp[a[i]]=ini++;
        }
        a[i]=cmp[a[i]];
        au[i]=a[i];
    }
    scanf("%lld",&m);
    for(ll i=0; i<m; ++i)
    {
        getchar();
        scanf("%c",&ch);
        if(ch=='Q')
        {
            scanf("%lld%lld",&l,&r);
            --l,--r;
            q[sq]= {l,r,su,sq};
            sq++;
        }
        else
        {
            scanf("%lld%lld",&indx,&newval);
            --indx;
            if(!cmp.count(newval))
            {
                org[ini]=newval;
                cmp[newval]=ini++;
            }
            newval=cmp[newval];
            u[su++]= {indx,newval,au[indx]};
            au[indx]=newval;
        }
    }
    sort(q,q+sq);
    for(ll j=0; j<sq; ++j)
    {
        ll l=q[j].l, r=q[j].r, qt=q[j].t, i=q[j].i;
        while(t<qt) updo(t++);
        while(t>qt) undo(--t);
        while(ml<l) del(ml++);
        while(ml>l) add(--ml);
        while(mr<r) add(++mr);
        while(mr>r) del(mr--);
        res[i]=cur;
    }
    for(ll i=0; i<sq; ++i) printf("%lld\n",res[i]);
    return 0;
}
