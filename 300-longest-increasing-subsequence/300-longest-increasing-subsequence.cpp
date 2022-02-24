class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for(int i=nums.size()-1;i>=0;i--)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j]<nums[i])
                {
                    dp[j] = max(dp[j], dp[i]+1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
    
};