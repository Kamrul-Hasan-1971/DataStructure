#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define  ll              long long int
const ll maxn = 200002;
ll K, ans[maxn], a[maxn], sum,cnt[1000006];
struct Query{
    ll index, L, R;
    bool operator < (const Query &other) const {
		ll block_own = L/K;
		ll block_other = other.L/K;
		if(block_own == block_other)
            return R < other.R;
		return block_own < block_other;
	}
}query[maxn];

inline void add(ll indx){
    ll x = ++cnt[a[indx]];
    sum+= (x+x-1)*a[indx];
}
inline void del(ll indx){
    ll x = cnt[a[indx]]--;
    sum-= (x+x-1)*a[indx];
}

int main(){
    ll i, n , q , L=0, R=-1;;
    scanf("%lld%lld",&n,&q);
    K = sqrt(n);
    for(i=1;i<=n;i++) scanf("%lld",&a[i]);
    for( i=1;i<=q;i++){scanf("%lld%lld",&query[i].L,&query[i].R);query[i].index = i;}
    sort(query+1, query+q+1);
    for(int i=1;i<=q;i++){
        while(R<query[i].R) add(++R);
        while(L<query[i].L) del(L++);
        while(R>query[i].R) del(R--);
        while(L>query[i].L) add(--L);
        ans[query[i].index] = sum;
    }
    for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
    return 0;
}
//https://codeforces.com/contest/86/problem/D
