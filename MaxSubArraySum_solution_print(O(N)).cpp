#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[100005],n;
ll fun()
{
	ll mx = LLONG_MIN, now = 0,
	start =0, endd = 0, s=0;

	for (ll i=1; i<=n; i++ )
	{
		now += ara[i];
		if (mx < now)
		{
			mx = now;
			//start = s;
			//endd = i;
		}
		if (now < 0)
		{
			now = 0;
			//s = i+1;
		}
	}
    return mx ;
}
int main()
{
    ll i , j ;
    cin >> n ;
    for( i = 1 ; i <= n ; i++) cin >> ara[i];
    ll max_sum = fun();
    cout<<max_sum<<endl;
    return 0;
}
