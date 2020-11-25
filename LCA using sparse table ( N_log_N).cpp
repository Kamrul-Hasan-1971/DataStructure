//https://www.spoj.com/problems/LCA/
#include<bits/stdc++.h>
using namespace std;
#define           mx                 1002
#define           pb                 push_back
#define           ll                 long long int
ll L[mx],P[mx][22],T[mx];
vector<ll>g[mx];
void dfs(ll from,ll u,ll dep)
{
    T[u]=from;
    L[u]=dep;
    for(ll i=0; i<(ll)g[u].size(); i++)
    {
        ll v=g[u][i];
        if(v==from) continue;
        dfs(u,v,dep+1);
    }
}
ll lca_query(ll p, ll q)
{
    ll tmp, log=1, i;
    if (L[p] < L[q]) tmp = p, p = q, q = tmp;
    while(1)
    {
        ll next=log+1;
        if((1<<next)>L[p]) break;
        log++;
    }
    for (i=log;i>=0;i--) if(L[p]-(1 << i)>=L[q]) p=P[p][i];
    if (p == q) return p;
    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];
    return T[p];
}
void initialize(ll node)
{
    for( int i = 0 ; i <= node ; i++) g[i].clear();
}
void lca_init(ll N)
{
    memset (P,-1,sizeof(P));
    ll i, j;
    for (i = 0; i < N; i++) P[i][0] = T[i];
    for (j = 1; 1 << j < N; j++)
        for (i = 0; i < N; i++)
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
}
int main()
{
    ll T , i , j,node , edge,c,d,q,cs=0;
    cin >> T ;
    while(T--)
    {
        cs++;
        cin >> node;
        initialize(node);
        for( i = 0 ; i < node ; i++)
        {
            cin >> edge;
            for( j = 0 ; j < edge ; j++)
            {
                cin >> c;
                c--;
                g[i].pb(c);
            }
        }
        dfs(-1, 0, 0);
        lca_init(node); //Total Node
        cin >> q ;
        printf("Case %lld:\n",cs);
        for( i = 0 ; i < q ; i++)
        {
            cin >> c >> d;
            c--,d--;
            printf("%lld\n",lca_query(c,d)+1);
        }
    }
    return 0;
}
