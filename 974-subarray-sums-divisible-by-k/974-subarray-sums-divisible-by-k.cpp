class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> mp;
        int count = 0;
        mp[0] = 1;
        int pref=0;
        for(auto a : nums)
        {
            pref = (pref+a)%k;
            if(pref<0)
                pref = pref+k;
            
            count += mp[pref];
            mp[pref]++;
        }
        return count;
    }
    
};