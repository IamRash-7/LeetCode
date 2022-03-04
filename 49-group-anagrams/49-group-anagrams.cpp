class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> m;
        vector<vector<string>> ans;
        for(auto s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            m[t].push_back(s);
        }
        for(auto p : m)
        {
            ans.push_back(p.second);
        }
        return ans;
    }
};