class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        if(n==2)
            return "11";
        
        string res = countAndSay(n-1);
        string ans;
        int cnt = 1;
        int i=0;
        for(i=1;i<res.size();i++)
        {
            if(res[i-1]==res[i])
            {
                cnt++;
            }
            else
            {
                ans += to_string(cnt) + res[i-1];
                cnt=1;
            }
        }
        ans += to_string(cnt) + res[i-1];

        return ans;
    }
};