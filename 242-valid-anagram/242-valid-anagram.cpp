class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> table(26,0);
        if(s.size()<t.size())
            swap(s,t);
        for(char c:s)
        {
            table[c-97]++;
        }
        for(char c:t)
        {
            table[c-97]--;
        }
        for(int i=0;i<table.size();i++)
        {
            if(table[i]>0)
                return false;
        }
        return true;
    }
};