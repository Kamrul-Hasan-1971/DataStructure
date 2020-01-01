#include<bits/stdc++.h>
using namespace std;

#define           ll                 long long int

ll segment[10000],input[100000];
ll preprocess( ll n)
{
    ll current_segment = -1;
    ll segment_size = sqrt(n);

    for (ll i=0; i<n; i++)
    {
        if (i % segment_size == 0)
        {
            current_segment++;
        }
        segment[current_segment] += input[i];
    }
    return segment_size;
}

ll query(ll segment_size, ll l,ll r)
{
    ll sum = 0;

    while (l < r && l % segment_size != 0)
    {
        sum += input[l];
        l++;
    }
    while (l + segment_size <= r)
    {
        sum += segment[l / segment_size];
        l += segment_size;
    }
    while (l<=r)
    {
        sum += input[l];
        l++;
    }
    return sum;
}

void update(ll segment_size, ll i, ll val)
{
    ll segment_no = i / segment_size;
    segment[segment_no] -= input[i];
    segment[segment_no] += val;
    input[i] = val;
}


int main()
{
    ll  i, j, n, q, a, l, r,indx, val,type ;

    cin >> n >> q ;

    for( i = 0 ; i < n ; i++ )
    {
        cin >> input[i] ;
    }
    ll sz = preprocess(n);

    for( i = 0 ; i < q ; i++ )
    {
        cin >> type;
        if( type == 0 )
        {
            cin>> indx >> val ;
            indx--;
            update(sz,indx,val);
        }
        else
        {
            cin >> l >> r  ;
            l--;
            r--;
            cout<<query(sz,l,r)<<endl;
        }
    }
    return 0 ;
}
