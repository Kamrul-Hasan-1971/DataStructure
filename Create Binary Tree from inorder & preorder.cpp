class Solution
{
public:
    unordered_map<int,int>mp;
    TreeNode* fun(vector<int>&pre, int i,int j, vector<int>&in, int ii, int jj)
    {
        if(j<=0) return NULL;
        int baki = mp[pre[i]]-ii;
        TreeNode* root = new TreeNode(pre[i]);
        root->left = fun(pre,i+1,baki,in,ii,baki);
        root->right = fun(pre,i+baki+1,j-baki-1,in,ii+baki+1,j-baki-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        for( int i = 0 ; i < inorder.size() ; i++) mp[inorder[i]]=i;
        return fun(preorder,0,preorder.size(),inorder,0,inorder.size());
    }
};
