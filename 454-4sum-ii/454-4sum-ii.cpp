class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int cnt = 0;
        map<int,int> mp;
        for(int l : nums4)
            for(int k : nums3)
                mp[l+k]++;
        
        for(int i : nums1)
            for(int j: nums2)
                    cnt += mp[-(i+j)];
        return cnt;
    }
};