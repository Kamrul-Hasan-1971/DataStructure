int findKthLargest(vector<int>& nums, int k)
{
    int res = nums.size() - k,l = 0, r = nums.size() - 1;
    unsigned seed = 0;
    shuffle(nums.begin(), nums.end(), default_random_engine(seed));
    //random_shuffle(nums.begin(),nums.end());
    while(l < r)
    {
        int indx = Partition(nums, l, r);
        if(indx == res)break;
        else if(indx < res) l = indx + 1;
        else r = indx - 1;
    }
    return nums[res];
}
int Partition(vector<int>&nums, int l, int r)
{
    int last = nums[r],indx = l;
    for(int i = l; i < r; i++)
    {
        if(nums[i] <= last)
        {
            swap(nums[i],nums[indx]);
            indx++;
        }
    }
    swap(nums[indx],nums[r]);
    return indx;
}
