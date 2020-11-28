#include<bits/stdc++.h>
using namespace std;
#define  CIN      ios_base::sync_with_stdio(false),cin.tie(NULL)
#define  ll       int
#define  MX       50005
struct data
{
    int sum,pref,suff,ans;
    data()
    {
        sum=0;
        pref=suff=ans=-1e9;
    };
    data(int val)
    {
        sum=pref=suff=ans=val;
    }
};

data tree[MX*3];
ll ara[MX+3];

data combine(data &left,data &right)
{
    data res;
    res.sum=left.sum+right.sum;
    res.pref=max(left.pref,left.sum+right.pref);
    res.suff=max(right.suff,left.suff+right.sum);
    res.ans=max(max(left.ans,right.ans),left.suff+right.pref);
    return res;
}
void built_tree( int node , int a , int b )
{
    if( a == b )
    {
        tree[node] = data(ara[a]) ;
        return ;
    }
    int left = node << 1 ;
    int right = ( node << 1)+ 1 ;
    int mid = ( a + b ) / 2 ;

    built_tree( left , a , mid ) ;
    built_tree( right , mid+1 , b ) ;
    tree[node] = combine(tree[left] , tree[right]) ;
}
data query_tree( int node , int a , int b , int i , int j )
{
    if( i > b || j < a ) return data() ;
    if( a >= i  && b <= j ) return tree[node] ;
    int left = node << 1 ;
    int right = ( node << 1)+ 1 ;
    int mid = ( a + b ) / 2 ;
    data ret1 = query_tree( left , a , mid , i , j ) ;
    data ret2 = query_tree( right , mid+1 , b , i , j ) ;
    return combine(ret1,ret2) ;
}

int main()
{
    CIN;
    ll  q,n,b,c,i;
    cin >> n ;
    for( i = 1 ; i <= n ; i++) cin >> ara[i];
    built_tree(1,1,n);
    cin>>q;
    for( i = 1 ; i <= q; i++)
    {
        cin >> b >>c;
        cout<<query_tree(1,1,n,b,c).ans<<endl;
    }
    return 0 ;
}
