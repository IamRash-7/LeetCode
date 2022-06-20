class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>res;
        recur(s,0,ans,res);
        return ans;
    }
    
    bool ispal(string s, int l, int r)
    {
        while(l<=r)
        {
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    void recur(string s, int l, vector<vector<string>> &ans, vector<string> &res)
    {
        if(l==s.size())
        {
            ans.push_back(res);
            return;
        }
        for(int i=l;i<s.size();i++)
        {
            if(ispal(s,l,i))
            {
                res.push_back(s.substr(l,i-l+1));
                recur(s,i+1,ans,res);
                res.pop_back();
            }
            
        }
    }
    
    
};