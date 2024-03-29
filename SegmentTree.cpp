#include<bits/stdc++.h>
using namespace std;
#define           ll        long long int
#define           MX        200005

ll tree[MX*3],ara[MX+3];

void built_tree( ll node , ll a , ll b )
{
    if(a>b) return ;//extra care for runtime error
    if( a == b )
    {
        tree[node] = ara[a] ;
        return ;
    }
    ll left = (node << 1) ,right = ( node << 1)+ 1,mid = ( a + b ) / 2 ;
    built_tree( left , a , mid ) ;
    built_tree( right , mid+1 , b ) ;
    tree[node] = tree[left] + tree[right] ;
}

ll query_tree( ll node , ll a , ll b , ll i , ll j )
{
    if(a > b || i > b || j < a ) return 0 ;
    if( a >= i  && b <= j ) return tree[node] ;
    ll left = (node << 1) ,right = ( node << 1)+ 1,mid = ( a + b ) / 2 ;
    ll ret1 = query_tree( left , a , mid , i , j ) ;
    ll ret2 = query_tree( right , mid+1 , b , i , j ) ;
    return ret1+ret2 ;
}

void update_tree( ll node , ll a , ll b , ll indx , ll newValue)
{
    if( indx > b  || indx < a ) return ;
    if( a == b) {
        tree[node] = newValue ;
        return ;
    }
    ll left = (node << 1) ,right = ( node << 1)+ 1,mid = ( a + b ) / 2 ;
    update_tree( left , a , mid , indx ,  newValue ) ;
    update_tree( right , mid+1 , b , indx , newValue ) ;
    tree[node] = tree[left] + tree[right] ;
}

int main()
{
    ll i , n , j ,inp ;
    scanf("%lld", &n ) ;
    for( i = 1 ; i <= n ; i++ ) scanf("%lld",&ara[i]) ;
    built_tree( 1 , 1 , n ) ;
    update_tree( 1 , 1 , n , 2 , 0 ) ;
    cout<<query_tree( 1 , 1 , n  , 1 , 3 ) <<endl ;
    update_tree( 1 , 1 , n , 2 , 2 ) ;
    cout<<query_tree( 1 , 1 , n  , 2 , 2 )<<endl ;
    return 0 ;
}
