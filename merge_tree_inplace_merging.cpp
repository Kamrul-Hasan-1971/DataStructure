#define iterator vector<pair<int,int>>::iterator
class Solution
{
public:
    void fun(iterator l, iterator r,vector<int>&res)
    {
        if(r-l<=1)
            return ;
        iterator m = l + (r - l) / 2;
        fun(l,m,res);
        fun(m,r,res);
        for( iterator i = l, j = m ; i<m ; i++)
        {
            while(j<r && (*i).first>(*j).first)
                j++;
            res[(*i).second]+=j-m;
        }
        inplace_merge(l,m,r);
    }
    vector<int> countSmaller(vector<int>& nums)
    {
        if(nums.size()==0)
            return vector<int>();
        vector<pair<int,int> > v;
        for( int i = 0 ; i <  nums.size() ; i++)
            v.push_back({nums[i],i});
        vector<int>res(nums.size(),0);
        fun(v.begin(),v.end(),res);
        return res;
    }
};
