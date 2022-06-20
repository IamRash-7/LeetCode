class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>res;
        recur(candidates,target,ans,res,0,0);
        return ans;
    }
    void recur(vector<int>& candidates, int target, vector<vector<int>>&ans, vector<int>&res, int sum, int st)
    {
        if(sum==target)
            ans.push_back(res);
        if(sum>target)
            return;
        for(int i=st;i<candidates.size();i++)
        {
            res.push_back(candidates[i]);
            sum = sum+candidates[i];
            recur(candidates,target,ans,res,sum,i);
            res.pop_back();
            sum = sum-candidates[i];
        }
    }
};