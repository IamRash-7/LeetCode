class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        sort(nums.begin(),nums.end());
        recur(nums,0,ans,res);
        return ans;
    }
    void recur(vector<int>& nums, int st, vector<vector<int>>& ans, vector<int>& res)
    {
        ans.push_back(res);
        for(int i=st;i<nums.size();i++)
        {
            if(i!=st && nums[i]==nums[i-1])
                continue;
            res.push_back(nums[i]);
            recur(nums,i+1,ans,res);
            res.pop_back();
        }
    }
};