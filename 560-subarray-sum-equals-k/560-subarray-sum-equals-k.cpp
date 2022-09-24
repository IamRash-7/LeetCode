class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        map<int,int> mp;
        mp[0]++;
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            cnt += mp[sum-k];
            mp[sum]++;
        }
        return cnt;
    }
};