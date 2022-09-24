class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num1=0;
        int c1 = 0;
        for(auto i:nums)
        {
            if(c1==0)
            {
                c1++;
                num1 = i;
            }
            else if(num1==i)
            {
                c1++;
            }
            else
                c1--;
        }
        return num1;
        
        // sort(nums.begin(), nums.end());
        // return nums[nums.size()/2];
    }
};