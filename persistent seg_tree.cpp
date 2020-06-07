#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define ll  long long int
struct node
{
	ll val;
	node* left, *right;
	node() {}
	node(node* l, node* r, ll v)
	{
		left = l;
		right = r;
		val = v;
	}
};

ll arr[MAXN];
node* version[102];
void build(node* n,ll low,ll high)
{
	if (low==high)
	{
		n->val = arr[low];
		return;
	}
	ll mid = (low+high) / 2;
	n->left = new node(NULL, NULL, 0);
	n->right = new node(NULL, NULL, 0);
	build(n->left, low, mid);
	build(n->right, mid+1, high);
	n->val = n->left->val + n->right->val;
}

void upgrade(node* prev, node* cur, ll low, ll high,ll idx, ll value)
{
	if (idx > high or idx < low or low > high) return;
	if (low == high)
	{
		cur->val = value;
		return;
	}
	ll mid = (low+high) / 2;
	if (idx <= mid)
	{
		cur->right = prev->right;
		cur->left = new node(NULL, NULL, 0);
		upgrade(prev->left,cur->left, low, mid, idx, value);
	}
	else
	{
		cur->left = prev->left;
		cur->right = new node(NULL, NULL, 0);
		upgrade(prev->right, cur->right, mid+1, high, idx, value);
	}
	cur->val = cur->left->val + cur->right->val;
}

ll query(node* n, ll low, ll high, ll l, ll r)
{
	if (l > high or r < low or low > high)return 0;
	if (l <= low and high <= r) return n->val;
	ll mid = (low+high) / 2;
	ll p1 = query(n->left,low,mid,l,r);
	ll p2 = query(n->right,mid+1,high,l,r);
	return p1+p2;
}

int main()
{
    ll n , q ,type , idx ,l,r, pos , v ,i,last = 1;
	scanf("%lld",&n);
	for (ll i=0; i<n; i++) scanf("%lld,",&arr[i]);
	node* root = new node(NULL, NULL, 0);
	build(root, 0, n-1);
	version[0] = root;
	scanf("%lld",&q);
	for( i = 1 ; i <= q ; i++)
    {
        scanf("%lld",&type);
        if(type==1)
        {
            scanf("%lld%lld%lld",&idx,&pos,&v);
            pos--;
            version[last] = new node(NULL, NULL, 0);
            ll x = query(version[idx],0,n-1,pos,pos);
            upgrade(version[idx], version[last++], 0, n-1, pos, v+x);
        }
        else
        {
            scanf("%lld%lld%lld",&idx,&l,&r);
            ll x = query(version[idx],0,n-1,--l,--r);
            printf("%lld\n",x);
        }
    }
	return 0;
}
//https://www.spoj.com/problems/PSEGTREE/
