class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        map<int, int> mp;
        for(int i:nums)
            mp[i]++;
        int maxi = 0, cur = 1;
        int val = mp[nums[0]];
        for (auto i : mp)
        {
            if(i.first == val)
                continue;
            else if(i.first == val+1)
                cur++;
            else
            {
                maxi = max(maxi, cur);
                cur = 1;
            }
            val = i.first;
        }
        return max(maxi, cur);
    }
};