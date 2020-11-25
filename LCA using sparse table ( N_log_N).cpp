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
    for(auto v : g[u]) if(v!=from) dfs(u,v,dep+1);
}
void lca_init(ll N)
{
    memset (P,-1,sizeof(P));
    for (ll i = 0; i < N; i++) P[i][0] = T[i];
    for (ll j = 1; 1 << j < N; j++)
        for (ll i = 0; i < N; i++)
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
    for( ll i = 0 ; i <= N ; i++) g[i].clear();
}
ll lca_query(ll u, ll v)
{
    ll tmp, log=1, i;
    if (L[u] < L[v]) swap(u,v);
    for( log = 1 ; ; log++) if( (1<<log) >L[u]) break;
    for( i=log;i>=0;i--) if( L[u]-(1 << i) >= L[v]) u=P[u][i];
    if (u == v) return v;
    for (i=log;i>=0;i--)
        if (P[u][i] != -1 && P[u][i] != P[v][i])
            u = P[u][i], v = P[v][i];
    return T[u];
}
int main()
{
    ll T , i , j,node , edge,c,d,q,cs=0;
    cin >> T ;
    while(T--)
    {
        cs++;
        cin >> node;
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
