#include<bits/stdc++.h>
using namespace std;
#define           ll                 long long int
#define           MX                 200005
#define           pii                pair<ll,ll>
#define           INF                10e9

pii tree[MX*3];
ll ara[MX+3];


// for min just change '>' to '<'
pii combine(pii a, pii b)
{
    if( a.first > b.first )
        return a ;
    if( b.first > a.first )
        return b ;
    return {a.first,a.second+b.second};
}

void built_tree( int node, int a, int b )
{
    if( a == b )
    {
        tree[node] = {ara[a],1} ;
        return ;
    }
    int left = node << 1 ;
    int right = ( node << 1)+ 1 ;
    int mid = ( a + b ) / 2 ;

    built_tree( left, a, mid ) ;
    built_tree( right, mid+1, b ) ;
    tree[node] = combine( tree[left], tree[right]) ;
}

pii query_tree( int node, int a, int b, int i, int j )
{
    if( i > b || j < a )
        return {-INF,0} ;
    if( a >= i  && b <= j )
        return tree[node] ;

    int left = node << 1 ;
    int right = ( node << 1)+ 1 ;
    int mid = ( a + b ) / 2 ;
    pii ret1 = query_tree( left, a, mid, i, j ) ;
    pii ret2 = query_tree( right, mid+1, b, i, j ) ;
    return combine(ret1,ret2) ;
}

void update_tree( int node, int a, int b, int indx, ll newValue)
{
    if( indx > b  || indx < a )
        return ;
    if( a == b)
    {
        tree[node] = {newValue,1} ;
        return ;
    }
    int left = node << 1 ;
    int right = ( node << 1)+ 1 ;
    int mid = ( a + b ) / 2 ;
    update_tree( left, a, mid, indx,  newValue ) ;
    update_tree( right, mid+1, b, indx, newValue ) ;
    tree[node] = combine(tree[left], tree[right]) ;
}

int main()
{
    ll i, n, j,inp , a ,b,c,d,type;
    scanf("%lld", &n ) ;
    for( i = 1 ; i <= n ; i++ )
    {
        scanf("%lld",&ara[i]) ;
    }

    built_tree( 1, 1, n ) ;

    for( i = 1 ; i <= n ; i++ )
    {
        cin >> type;
        if(type==1){
        cin >> a >> b ;
        update_tree( 1, 1, n, a, b ) ;
        }
        else{
        cin >> c >> d ;
        pii x =query_tree( 1, 1, n, c, d );
        cout<<x.first<<" "<<x.second<<endl;
        }

    }
    return 0 ;
}
