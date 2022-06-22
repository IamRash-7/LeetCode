class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int left = 0, right = n;
        while(left<right)
        {
            int mid = (left+right)/2;
            if((mid%2 == 0 && nums[mid+1]==nums[mid]) || (mid%2==1 && nums[mid]==nums[mid-1]))
            {
                left = mid+1;
            }
            else
            {
                right = mid;
            }
            
        }
        return nums[left];
    }
};