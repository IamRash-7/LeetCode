class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0, j=0;
        int n1 = version1.size(), n2 = version2.size();
        double val1 = 0, val2=0;
        while(i<n1 || j<n2)
        {
            while(i<n1 && version1[i]!='.')
            {
                val1 += val1*10 + (version1[i]-'0');
                i++;
            }
            
            while(j<n2 && version2[j]!='.')
            {
                val2 += val2*10 + (version2[j]-'0');
                j++;
            }
            
            if(val1<val2)
                return -1;
            else if(val2<val1)
                return 1;
            
            val1= 0;
            val2 = 0;
            i++;
            j++;
        }
        return 0;
    }
};