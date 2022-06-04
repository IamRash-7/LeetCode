class Solution {
public:
    bool isPalindrome(string s) {
        string res;
        for(char c:s)
        {
            if(isalnum(c))
            {
                res.push_back(tolower(c));
            }
        }
        cout<<res;
        int l=0,r=res.size()-1;
        while(l<r)
        {
            if(res[l]!=res[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};