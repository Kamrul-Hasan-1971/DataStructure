#include<bits/stdc++.h>
using namespace std;

#define           ll                 long long int

vector<ll>MaxRes , MinRes ;
ll ara[10];

void printKMax( ll n , ll k )
{
    deque<ll>dq ;
    ll i ;
    for( i = 0 ; i < k ; i++ )
    {
        while( (!dq.empty()) && ara[i] >= ara[dq.back()])
            dq.pop_back();
        dq.push_back(i) ;
    }

    for( ; i < n ; i++ )
    {
        MaxRes.push_back(ara[dq.front()]);
        while((!dq.empty()) && dq.front() <= i - k )
            dq.pop_front();
        while((!dq.empty()) && ara[i] >= ara[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    MaxRes.push_back(ara[dq.front()]);
}

void printKMin( ll n , ll k )
{
    deque<ll>dq ;
    ll i ;
    for( i = 0 ; i < k ; i++ )
    {
        while( (!dq.empty()) && ara[i] <= ara[dq.back()])
            dq.pop_back();
        dq.push_back(i) ;
    }

    for( ; i < n ; i++ )
    {
        MinRes.push_back(ara[dq.front()]);
        while((!dq.empty()) && dq.front() <= i - k )
            dq.pop_front();
        while((!dq.empty()) && ara[i] <= ara[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    MinRes.push_back(ara[dq.front()]);
}
int main()
{
    ll  i , j , n , k  ;
    cin >> n >> k ;

    for( i = 0; i < n ; i++)
        cin >> ara[i];

    printKMax( n , k ) ;
    printKMin( n , k ) ;

    for( i = 0 ; i < MaxRes.size() ; i++ )
        cout<<MaxRes[i]<<" ";
    cout<<endl;
    for( i = 0 ; i < MinRes.size() ; i++ )
        cout<<MinRes[i]<<" ";
    cout<<endl;
    return 0 ;
}
