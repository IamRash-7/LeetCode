class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>res;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        recur(candidates,target,ans,res,0,0);
        return ans;
    }
    
    void recur(vector<int>&candidates, int target, vector<vector<int>>&ans, vector<int>&res, int st, int sum)
    {
        if(sum==target)
            ans.push_back(res);
        if(sum>target)
            return;
        for(int i=st;i<candidates.size();i++)
        {
            if(i!=st && candidates[i]==candidates[i-1])
                continue;
            sum += candidates[i];
            res.push_back(candidates[i]);
            recur(candidates,target, ans,res,i+1,sum);
            res.pop_back();
            sum -= candidates[i];
        }
    }
};