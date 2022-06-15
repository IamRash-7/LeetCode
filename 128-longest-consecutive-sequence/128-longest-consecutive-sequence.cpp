class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]] = i;
        int ans = 0;
        int cnt=1;
        int prev=mp.begin()->first;
        for(auto i = mp.begin(); i!= mp.end(); i++)
        {
            if(i->first == prev)
                continue;
            else if(i->first == prev+1)
            {
                cnt++;
            }
            else
            {     
                ans = max(ans,cnt);
                cnt = 1;
            }
            prev = i->first;
        }
        return max(ans,cnt);
    }
};