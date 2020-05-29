#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define  max3(a,b,c)    max(a,max(b,c))
ll arr[100005];
ll combine(ll l, ll m, ll h)
{
    ll sum = 0;
    ll l_sum = LLONG_MIN,r_sum = LLONG_MIN;
    for (ll i = m; i >= l; i--)
    {
        sum += arr[i];
        if (sum > l_sum) l_sum = sum;
    }
    sum = 0;
    for (ll i = m+1; i <= h; i++)
    {
        sum += arr[i];
        if (sum > r_sum) r_sum = sum;
    }
    return max3(l_sum + r_sum, l_sum, r_sum);
}

ll fun(ll l, ll h)
{
    if (l == h) return arr[l];
    ll m = (l + h)/2;
    return max3(fun(l, m),fun(m+1, h), combine(l, m, h));
}
int main()
{
    ll n , i , j ;
    cin >> n ;
    for( i = 1 ; i <= n ; i++) cin >> arr[i];
    ll max_sum = fun(1, n);
    cout<<max_sum<<endl;
    return 0;
}
