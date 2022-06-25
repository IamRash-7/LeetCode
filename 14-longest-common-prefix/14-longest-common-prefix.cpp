class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==1) return strs[0];
        string pref;
        for(int i=1;i<strs.size();i++)
        {
            if(i==1)
            {
                pref = recur(strs[i],strs[i-1]);
            }
            else
            {
                pref = recur(strs[i],pref);
            }
        }
        return pref;
    }
    
    string recur(string a, string b)
    {
        if(a.size()>b.size())
            swap(a,b);
        int right = a.size();
        int i;
        for(i=0;i<right;i++)
        {
            if(a[i]!=b[i])
                break;
        }
        return a.substr(0,i);
    }
};