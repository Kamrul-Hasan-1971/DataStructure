#include<bits/stdc++.h>
using namespace std;

#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
#define  INF            100000000
vector<ll>v1;
ll a ,dp[2][2][100005];
ll fun(ll start,ll endd , ll indx )
{
    if(indx>=a || endd==1) return 0;
    ll ret1 = -INF,ret2=-INF;
    ll x = dp[start][endd][indx];
    if(x!=-1) return x;
    if(!start)
    {
        ret1 = v1[indx]+fun(1,endd,indx+1);
        ret2 = fun(start,endd,indx+1);
    }
    else
    {
        ret1 = v1[indx]+fun(start,endd,indx+1);
        ret2 = fun(start,1,indx+1);
    }
    return dp[start][endd][indx]=max(ret1,ret2);
}
int main()
{
    CIN;
    ll  b,i;
    memset(dp,-1,sizeof dp);
    cin>> a ;
    for( i = 0 ; i < a ; i++)
    {
        cin >> b ;
        v1.push_back(b);
    }
    cout<<fun(0,0,0)<<endl;
    return 0 ;
}
