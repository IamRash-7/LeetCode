class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> res;
        vector<vector<int>>ans;
        recur(nums,res,ans);
        return ans;
    }
    
    void recur(vector<int>& nums, vector<int>&res, vector<vector<int>>&ans)
    {
        if(res.size()==nums.size())
            ans.push_back(res);
        for(int i=0;i<nums.size();i++)
        {
            if(find(res.begin(),res.end(),nums[i])!=res.end())
                continue;
            res.push_back(nums[i]);
            recur(nums,res,ans);
            res.pop_back();
        }
    }
};