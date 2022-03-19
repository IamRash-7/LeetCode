class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size()<k || s.size()==0)
            return 0;
        map<char, int> mp;
        for(char p:s)
            mp[p]++;
        int i=0;
        while(i <s.size() && mp[s[i]]>=k) 
            i++;
        if(i==s.size())
            return s.size();
        
        int l = longestSubstring(s.substr(0,i),k);
        int r = longestSubstring(s.substr(i+1),k);
        return max(l, r);
        
       
    }
};