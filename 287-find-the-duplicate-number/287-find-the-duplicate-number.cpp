class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(i=0;i<n;i++)
        {
            if(nums[i] == nums[i+1])
                break;
        }
        return nums[i];
    }
};