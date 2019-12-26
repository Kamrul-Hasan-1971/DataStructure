#include<bits/stdc++.h>
using namespace std;

#define           ll                 long long int

vector<ll>MaxRes , MinRes ;

void printKMax( ll ara[] , ll n , ll k )
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

void printKMin( ll ara[] , ll n , ll k )
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
    ll  i , j ;
    ll ara[]={10 , 50 , 15 , 12 , 4} ;
    ll n = sizeof(ara) / sizeof(ara[0]);
    ll k = 3 ;
    printKMax( ara , n , k ) ;
    printKMin( ara , n , k ) ;

    for( i = 0 ; i < MaxRes.size() ; i++ )
    {
        cout<<MaxRes[i]<<" ";
    }
    cout<<endl;
    for( i = 0 ; i < MinRes.size() ; i++ )
    {
        cout<<MinRes[i]<<" ";
    }
    cout<<endl;
    return 0 ;
}
