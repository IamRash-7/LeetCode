class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0,nums.size()-1);
    }
    int mergesort(vector<int>& nums, int left, int right)
    {
        if(left>=right)
            return 0;
        
        int cnt=0;
        int mid = (left+right)/2;

        cnt += mergesort(nums,left,mid);
        cnt += mergesort(nums,mid+1,right);
        cnt += merge(nums,left,mid,right);
        
        return cnt;
    }
    int merge(vector<int>& nums, int left, int mid, int right)
    {
        int cnt=0;
        int j=mid+1;
        for(int i = left;i<=mid;i++)
        {
            while(j<=right && nums[i] > 2LL*nums[j])
                j++;
            cnt += (j-(mid+1));
        }
        
        int p = left, q = mid+1;
        vector<int> temp;
        while(p<=mid && q<=right)
        {
            if(nums[p]<=nums[q])
                temp.push_back(nums[p++]);
            else
                temp.push_back(nums[q++]);
        }
        while(p<=mid)
            temp.push_back(nums[p++]);
        while(q<=right)
            temp.push_back(nums[q++]);
        
        for(int k=left;k<=right;k++)
            nums[k] = temp[k-left];
        
        return cnt;
    }
};