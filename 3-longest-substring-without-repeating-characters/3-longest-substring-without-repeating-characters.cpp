class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int maxcnt=0;
        int left=0,right=0;
        while(right<s.size())
        {
            mp[s[right]]++;
            while(mp[s[right]]>1)
            {
                mp[s[left]]--;
                left++;
            }
            maxcnt = max(maxcnt, right-left+1);
            right++;
        }
        return maxcnt;
    }
};