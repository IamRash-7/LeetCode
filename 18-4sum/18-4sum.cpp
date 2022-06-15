class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int left=0, right = nums.size()-1;
        int i=0, j=0;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                left = j+1;
                right = nums.size()-1;
                int sum1 = target-nums[i]-nums[j];
                
                while(left<right)
                {
                    int sum2 = nums[left]+nums[right];
                    if(sum2<sum1)
                        left++;
                    else if(sum2>sum1)
                        right--;
                    else
                    {
                        vector<int> quad(4,0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[left];
                        quad[3] = nums[right];
                        ans.push_back(quad);
                        
                        while(left<right && nums[left]==quad[2])
                            left++;
                        while(left<right && nums[right]==quad[3])
                            right--;
                    }
                }
                
                while(j+1 < nums.size() && nums[j] == nums[j+1])
                    j++;
            }
            while(i+1 < nums.size() && nums[i]==nums[i+1])
                i++;
        }
        return ans;
    }
};