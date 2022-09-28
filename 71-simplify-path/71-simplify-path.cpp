class Solution {
public:
    string simplifyPath(string path) {
        string ans, s;
        stringstream ss(path);
        stack<string> st;
        
        while(getline(ss,s,'/'))
        {
            if(s == "" || s == ".")
                continue;
            if(s==".." && !st.empty())
                st.pop();
            else if(s!="..")
                st.push(s);
        }
        
        while(!st.empty())
        {
            ans = "/"+st.top()+ans;
            st.pop();
        }
        return ans.empty()?"/":ans;
    }
};