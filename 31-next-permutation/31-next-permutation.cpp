class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k,i;
        for(i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                k = i;
                break;
            }
        }
        
        if(k<0)
            reverse(nums.begin(), nums.end());
        else
        {
            for(i=n-1;i>=0;i--)
            {
                if(nums[i]>nums[k])
                {
                    break;
                }
            }
            swap(nums[i], nums[k]);
            reverse(nums.begin()+k+1, nums.end());
        }
    }
};