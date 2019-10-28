#include<bits/stdc++.h>
using namespace std;
#define           ll                 long long int
#define           MX        200005

ll tree[MX*3],ara[MX+3];

void MakeTree( int node , int start , int endd )
{
    if( start == endd )
    {
        tree[node] = ara[start] ;
        return ;
    }
    int left = node * 2 ;
    int right = ( node * 2 ) + 1 ;
    int mid = ( start + endd ) / 2 ;

    MakeTree( left , start , mid ) ;
    MakeTree( right , mid+1 , endd ) ;
    tree[node] = tree[left] + tree[right] ;
}

ll query( int node , int start , int endd , int range1 , int range2 )
{
    if( range1 > endd || range2 < start ) return 0 ;
    if( start >= range1  && endd <= range2 ) return tree[node] ;

    int left = node * 2 ;
    int right = ( node * 2 )+ 1 ;
    int mid = ( start + endd ) / 2 ;
    ll ret1 = query( left , start , mid , range1 , range2 ) ;
    ll ret2 = query( right , mid+1 , endd , range1 , range2 ) ;
    return ret1+ret2 ;
}

void update( int node , int start , int endd , int indx , ll newValue)
{
    if( indx > endd  || indx < start ) return ;
    if( start == endd) {
        tree[node] = newValue ;
        return ;
    }
    int left = node * 2 ;
    int right = ( node * 2 ) + 1 ;
    int mid = ( start + endd ) / 2 ;
    update( left , start , mid , indx ,  newValue ) ;
    update( right , mid+1 , endd , indx , newValue ) ;
    tree[node] = tree[left] + tree[right] ;
}

int main()
{
    ll i , n , j ,inp ;
    scanf("%lld", &n ) ;
    for( i = 1 ; i <= n ; i++ )
    {
        scanf("%lld",&ara[i]) ;
    }

    MakeTree( 1 , 1 , n ) ;
    update( 1 , 1 , n , 2 , 0 ) ;
    cout<<query( 1 , 1 , n  , 1 , 3 ) <<endl ;
    update( 1 , 1 , n , 2 , 2 ) ;
    cout<<query( 1 , 1 , n  , 2 , 2 )<<endl ;
    return 0 ;
}

