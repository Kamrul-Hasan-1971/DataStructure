#include<bits/stdc++.h>
using namespace std;
#define           ll                 long long int
#define           MX                 100005
#define           inf                0x3f3f3f3f


ll tree[MX*3] , ara[MX] , lazy[MX*3];

void build_tree( int node, int a, int b ) //node=current node, a-b=current range
{
    if( a > b ) return ; //out of range
    if( a == b ) //Leaf node
    {
        tree[node] = ara[a] ; //initialize value
        return ;
    }
    int left = node * 2 ;
    int right = ( node * 2 ) + 1 ;
    int mid = ( a + b ) / 2 ;

    build_tree( left, a, mid ) ;
    build_tree( right, mid+1, b ) ;
    tree[node] = min(tree[left], tree[right]);
}

ll query_tree( int node, int a, int b, int i, int j )
{
    if( a > b || a > j || b < i ) return -inf ; // Out of range
    if( lazy[node]!=0)
    {
        tree[node]+=lazy[node]; // Update it
        if(a!=b) //not leaf node.mark it's child as lazy
        {
            lazy[node*2] += lazy[node]; //mark child as lazy
            lazy[(node*2)+1]=lazy[node]; //mark child as lazy
        }
        lazy[node]=0; // Reset it
    }
    if(a>=i && b <= j) return tree[node];
    int left = node * 2 ;
    int right = ( node * 2 )+ 1 ;
    int mid = ( a + b ) / 2 ;
    ll q1 = query_tree(left , a , mid , i , j ) ;
    ll q2 = query_tree(right , mid+1 , b , i , j ) ;
    return min(q1,q2) ; // Return final result
}

void update_tree( int node, int a, int b, int i, int j ,ll newValue)
{
    if( lazy[node] != 0 ){ //This node needs to be updated
        tree[node] += lazy[node] ; //update it
        if( a!=b )
        {
            lazy[node*2] += lazy[node]; //mark child as lazy
            lazy[(node*2)+1]=lazy[node]; //mark child as lazy
        }
        lazy[node]=0; //Reset it
    }

    if( a > b || a > j || b < i ) return ; //current segment is not within range
    if( a>=i && b <=j )
    {
        tree[node]+=newValue;
        if(a!=b)// Not leaf node
        {
            lazy[node*2] += newValue ;
            lazy[(node*2)+1] += newValue ;
        }
        return ;
    }
    int left = node * 2 ;
    int right = ( node * 2 )+ 1 ;
    int mid = ( a + b ) / 2 ;
    update_tree( left , a , mid , i , j , newValue ) ;
    update_tree( right , mid+1 , b , i , j , newValue ) ;
    tree[node]=min(tree[left],tree[right]) ;
}


int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&ara[i]);
    build_tree(1,0,n-1);
    memset(lazy,0,sizeof(lazy));
    update_tree(1,0,n-1,0,3,5);  //increment range [0,3] by 5
    update_tree(1,0,n-1,7,10,12); // Incremenet range [7, 10] by 12
    update_tree(1,0,n-1, 10,n-1,100); // Increment range [10, N-1] by 100
    int ans=query_tree(1,0,n-1,0,n-1);  //Get min value in range [0,n-1]
    cout<<ans<<endl;
    return 0;
}
//http://delower13.blogspot.com/2017/06/blog-post_92.html#more

