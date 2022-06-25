class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int cnt = 1;
        string res = a;
        while(res.size()<b.size())
        {
            res = res+a;
            cnt++;
        }
        if(res==b)
            return cnt;
        if(hash(res,b)!=-1)
            return cnt;
        if(hash(res+a,b)!=-1)
            return cnt+1;
        return -1;
    }
    
    int hash(string source, string target)
    {
        if(source == "" or target == "") return -1;
        int BASE = 1000000;
        int power = 1;
        int targetcode = 0;
        int sourcecode = 0;
        int m = target.size();
        for(int i=0;i<m;i++)
        {
            power = (power*31)%BASE;
        }
        for(int i=0;i<m;i++)
        {
            targetcode = (targetcode*31 + target[i])%BASE;
        }
        for(int i=0;i<source.size();i++)
        {
            sourcecode = (sourcecode*31 + source[i])%BASE;
            if(i<m-1)
                continue;
            if(i>=m)
            {
                sourcecode = (sourcecode - source[i-m]*power)%BASE;
            }
            if(sourcecode<0)
                sourcecode += BASE;
            if(sourcecode == targetcode)
            {
                if(source.substr(i-m+1,m)==target)
                    return i-m+1;
            }
        }
        return -1;
    }
};