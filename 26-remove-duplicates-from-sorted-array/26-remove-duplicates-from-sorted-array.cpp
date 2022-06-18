class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0;
        int m = 1;
        while(m<nums.size())
        {
            if(nums[l]!=nums[m])
            {
                l++;
                swap(nums[l],nums[m]);
            }
            m++;
        }
        return l+1;
    }
};