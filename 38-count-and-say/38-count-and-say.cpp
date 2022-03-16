class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        if(n==2)
            return "11";
        int cnt = 1;
        int i=0;
        string res;
        string val = countAndSay(n-1);
        for(i=1;i<val.size();i++)
        {
            if(val[i] == val[i-1])
            {
                cnt++;
            }
            else
            {
                res += to_string(cnt) + val[i-1];
                cnt = 1;
            }
        }
        res += to_string(cnt) + val[i-1];
        return res;
    }
};