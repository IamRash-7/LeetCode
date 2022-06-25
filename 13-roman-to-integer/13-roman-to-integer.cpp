class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if (i < (s.size() - 1) && ('I' == s[i] && ('V' == s[i + 1] || 'X' == s[i + 1]) ||'X' == s[i] && ('L' == s[i + 1] || 'C' == s[i + 1]) ||'C' == s[i] && ('D' == s[i + 1] || 'M' == s[i + 1]) )) 
    {
		ans -= mp[s[i]];
	} else {
		ans += mp[s[i]];
	}
        }
        return ans;
    }
};