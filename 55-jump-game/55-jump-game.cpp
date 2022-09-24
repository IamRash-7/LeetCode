class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int i = 0;
        for(int reach=0;i<nums.size() && i<=reach;i++)
        {
            reach = max(i+nums[i], reach);
        }
        return i==nums.size();
        
        // vector<bool> ans(nums.size(),false);
        // ans[0]=true;
        // for(int i=1;i<nums.size();i++)
        // {
        //     for(int j=i-1;j>=0;j--)
        //     {
        //         if(ans[j] && j+nums[j]>=i)
        //         {
        //              ans[i]=true;
        //              break;
        //          }
        //     }
        // }
        // return ans[nums.size()-1];
    }
};