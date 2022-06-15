class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> res;
        for(int i=0;i<nums.size();i++)
        {
            if(res.find(target-nums[i])!=res.end())
                return {i,res[target-nums[i]]};
            res[nums[i]] = i;
        }
        return {};
    }
};