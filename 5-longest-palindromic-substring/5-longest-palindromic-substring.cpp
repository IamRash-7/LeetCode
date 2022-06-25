class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<2)
            return s;
        int start = 0, end = 0;
        for(int i=0;i<s.size();i++)
        {
            recur(s,i,i,start,end);
            recur(s,i,i+1,start,end);
            // int len = max(len1,len2);
            // if(len >= end-start)
            // {
            //     start = i - ((len-1)/2);
            //     end = i + (len/2);
            // }
        }
        return s.substr(start,end);
    }
    
    void recur(string s, int left, int right, int &start, int &end)
    {
        while(left>=0 && right<s.size() && s[left]==s[right])
        {
            left--;
            right++;
        }
        if(end<right-left-1)
        {
            end = right-left-1;
            start = left+1;
        }
    }
};