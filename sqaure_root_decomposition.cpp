#include<bits/stdc++.h>
using namespace std;
#define           ll            long long int
#define           MX            100005
ll seg[MX],input[MX],seg_size;
ll build( ll n)
{
    for (ll i=0; i<n; i++) seg[i/seg_size] += input[i];
}
ll query(ll l,ll r)
{
    ll sum = 0;
    while (l < r && l % seg_size != 0) sum += input[l++];
    while (l + seg_size <= r)
    {
        sum += seg[l / seg_size];
        l += seg_size;
    }
    while (l<=r) sum += input[l++];
    return sum;
}
void update(ll i, ll val)
{
    ll seg_no = i / seg_size;
    //seg[seg_no] -= input[i];
    seg[seg_no] += val;
    input[i] += val;
}
int main()
{
    ll  i, j, n, q, a, l, r,indx, val,type ;
    cin >> n >> q ;
    seg_size = sqrt(n);
    for( i = 0 ; i < n ; i++ ) cin >> input[i] ;
    build(n);
    for( i = 0 ; i < q ; i++ )
    {
        cin >> type;
        if( type == 0 )
        {
            cin>> indx >> val ;
            update(--indx,val);
        }
        else
        {
            cin >> l >> r  ;
            cout<<query(--l,--r)<<endl;
        }
    }
    return 0 ;
}
