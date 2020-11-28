#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>v1;
ll fun()
{
    ll mx = LLONG_MIN, now = 0, start =0, endd = 0, s=0;
    for (ll i=0; i< v1.size() ; i++ )
    {
        now += v1[i];
        if (mx < now)
        {
            mx = now;
            //start = s;
            //endd = i;
        }
        if (now < 0)
        {
            now = 0;
            //s = i + 1;
        }
    }
    //cout << "Starting "<< start<< endl << "Ending "<< endd << endl;
    return mx;
}

int main()
{
    ll i, j, n, a;
    cin >> n ;
    for( i = 0 ; i < n ; i++)
    {
        cin >> a;
        v1.push_back(a);
    }
    ll max_sum = fun();
    cout<<max_sum<<endl;
    return 0;
}
