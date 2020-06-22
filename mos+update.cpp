#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int Q=1e5+5;
int S;

struct query
{
    int l,r,t,i;
    bool operator<(const query&o)const
    {
        if(l/S!=o.l/S)
            return l<o.l;
        if(r/S!=o.r/S)
            return r<o.r;
        return t<o.t;
    }
} q[Q];
struct updt
{
    int i, nxt, prv;
} u[Q];

int a[N], au[N];
int ml=0, mr=-1, t=0;
long long re[Q], cur=0;
unordered_map<int,int>cnt;
void add(int i)
{
    int x=a[i];
    auto it=cnt.find(x);
    if(it->second==0 and x%3==0)
        cur+=x;
    ++(it->second);
}
void del(int i)
{
    int x=a[i];
    auto it=cnt.find(x);
    if(it->second==1 and x%3==0)cur-=x;
    --(it->second);
}
void updo(int i)
{
    int j=u[i].i, nxt=u[i].nxt;
    if(j>=ml and j<=mr) del(j);
    a[j]=nxt;
    if(j>=ml and j<=mr) add(j);
}
void undo(int i)
{
    int j=u[i].i, prv=u[i].prv;
    if(j>=ml and j<=mr) del(j);
    a[j]=prv;
    if(j>=ml and j<=mr)add(j);
}
int main()
{
    int n, m, c;
    scanf("%d %d",&n,&m);
    S = n/cbrt(n);

    for(int i=0; i<n; ++i)
    {
        scanf("%d",&a[i]);
        cnt[a[i]];
        au[i]=a[i];
    }
    int su=0, sq=0, l, r;
    for(int i=0; i<m; ++i)
    {
        scanf("%d%d%d",&c,&l,&r);
        if(c==1)
        {
            --l,--r;
            q[sq]= {l,r,su,sq};
            sq++;
        }
        else
        {
            --l;
            cnt[r];
            u[su++]= {l,r,au[l]};
            au[l]=r;
        }
    }
    sort(q,q+sq);
    for(int j=0; j<sq; ++j)
    {
        int l=q[j].l, r=q[j].r, qt=q[j].t, i=q[j].i;
        while(t<qt) updo(t++);
        while(t>qt) undo(--t);
        while(ml<l) del(ml++);
        while(ml>l) add(--ml);
        while(mr<r) add(++mr);
        while(mr>r) del(mr--);
        re[i]=cur;
    }
    for(int i=0; i<sq; ++i) printf("%lld\n",re[i]);
    return 0;
}
