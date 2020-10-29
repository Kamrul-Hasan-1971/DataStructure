https://leetcode.com/problems/count-number-of-teams/submissions/
#define           MX        100004
#define           ll        int
class Solution
{
public:
    ll Ltree[MX*3],Rtree[MX*3],ara[MX+3];

    int query( int tree[],int node, int a, int b, int i, int j )
    {
        if( i > b || j < a )
            return 0 ;
        if( a >= i  && b <= j )
            return tree[node] ;

        int left = node << 1 ;
        int right = ( node << 1)+ 1 ;
        int mid = ( a + b ) / 2 ;
        ll ret1 = query( tree,left, a, mid, i, j ) ;
        ll ret2 = query( tree,right, mid+1, b, i, j ) ;
        return ret1+ret2 ;
    }

    void update(int tree[], int node, int a, int b, int indx, ll newValue)
    {
        if( indx > b  || indx < a )
            return ;
        if( a == b)
        {
            tree[node] += newValue ;
            return ;
        }
        int left = node << 1 ;
        int right = ( node << 1)+ 1 ;
        int mid = ( a + b ) / 2 ;
        update( tree,left, a, mid, indx,  newValue ) ;
        update( tree,right, mid+1, b, indx, newValue ) ;
        tree[node] = tree[left] + tree[right] ;
    }
    int n = 100000;
    int numTeams(vector<int>& rating)
    {
        for( int i = 0 ; i < rating.size() ; i++)
        {
            update(Rtree,1,1,n,rating[i],1);
        }
        int ans =0;
        for( int i = 0 ; i < rating.size() ; i++)
        {
            int val = rating[i];
            update(Rtree,1,1,n,val,-1);
            ans+=query(Ltree,1,1,n,1,val-1)*query(Rtree,1,1,n,val+1,n);
            ans+=query(Ltree,1,1,n,val+1,n)*query(Rtree,1,1,n,1,val-1);
            update(Ltree,1,1,n,val,1);
        }
        return ans;
    }
};
