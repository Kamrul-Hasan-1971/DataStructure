#include<bits/stdc++.h>
using namespace std;
#define           ll                 long long int
#define           MX                 200005

ll tree[MX*3],ara[MX+3];

ll find_kth( ll node , ll a , ll b , ll k)
{
    if( k > tree[node]) return -1 ;
    if( a == b ) return a ;
    ll mid = (a+b) / 2 ;
    ll left = node << 1 ;
    ll right = left + 1 ;
    if( tree[left]>=k) return find_kth( left , a , mid , k ) ;
    else return find_kth( right , mid+1 , b , k - tree[left]) ;
}

void built_tree( int node , int a , int b )
{
    if( a == b )
    {
        if(ara[a]==0){
        tree[node] = 1 ;
        }
        return ;
    }
    int left = node << 1 ;
    int right = ( node << 1)+ 1 ;
    int mid = ( a + b ) / 2 ;

    built_tree( left , a , mid ) ;
    built_tree( right , mid+1 , b ) ;
    tree[node] = tree[left] + tree[right] ;
}

ll query_tree( int node , int a , int b , int i , int j )
{
    if( i > b || j < a ) return 0 ;
    if( a >= i  && b <= j ) return tree[node] ;

    int left = node << 1 ;
    int right = ( node << 1)+ 1 ;
    int mid = ( a + b ) / 2 ;
    ll ret1 = query_tree( left , a , mid , i , j ) ;
    ll ret2 = query_tree( right , mid+1 , b , i , j ) ;
    return ret1+ret2 ;
}

void update_tree( int node , int a , int b , int indx , ll newValue)
{
    if( indx > b  || indx < a ) return ;
    if( a == b) {
        if(newValue==0 && tree[node]==0){
        tree[node] = 1 ;
        }
        else tree[node]=0;
        return ;
    }
    int left = node << 1 ;
    int right = ( node << 1)+ 1 ;
    int mid = ( a + b ) / 2 ;
    update_tree( left , a , mid , indx ,  newValue ) ;
    update_tree( right , mid+1 , b , indx , newValue ) ;
    tree[node] = tree[left] + tree[right] ;
}

int main()
{
    ll i , n , j ,inp , l , r , type , pos , indx ;
    scanf("%lld", &n ) ;
    for( i = 1 ; i <= n ; i++ )
    {
        scanf("%lld",&ara[i]) ;
    }

    built_tree( 1 , 1 , n ) ;

    for( i = 1 ; i <= n*20 ; i++ )
    {
        cin >> type ;
        if(type==1)
        {
            cin >> l >> r ;
            cout<<query_tree(1,1,n,l,r)<<endl;
        }
        else if ( type == 2 )
        {
            cin >> pos ;
            cout<<find_kth( 1 , 1 , n , pos )<<endl;
        }
        else
        {
            cin >> indx >> inp ;
            update_tree(1,1,n,indx,inp);
        }
    }
    return 0 ;
}
