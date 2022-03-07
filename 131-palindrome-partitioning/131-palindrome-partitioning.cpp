class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> cur;
        dfs(result,cur,0,s);
        return result;
    }
    
    void dfs(vector<vector<string>> &result, vector<string> &cur, int st, string &s)
    {
        if(st>=s.size())
            result.push_back(cur);
        for(int i=st;i<s.size();i++)
        {
            if(isPalindrome(s, st, i))
            {
                cur.push_back(s.substr(st,i-st+1));
                dfs(result, cur, i+1, s);
                cur.pop_back();
            }
        }
    }
    
    bool isPalindrome(string &s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
};