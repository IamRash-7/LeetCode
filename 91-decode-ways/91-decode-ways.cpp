class Solution {
public:
    int numDecodings(string s) {
        vector<int> memo(s.size()+1, -1);
        memo[s.size()] = 1;
        return s.empty()? 0 : recur(0,s,memo);
    }
    
    int recur(int p, string s, vector<int> &memo)
    {
        int n = s.size();
        if(memo[p]>-1)
            return memo[p];
        if(s[p]=='0')
            return memo[p]=0;
        int res = recur(p+1, s,memo);
        if(p<n-1 && (s[p]=='1' || (s[p]=='2' && s[p+1]<'7')))
            res+= recur(p+2, s,memo);
        return memo[p] = res;
    }
};