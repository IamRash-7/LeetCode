class Solution {
public:
    int minPartitions(string n) {
        int maxi=0;
        for(auto a:n)
        {
            if(a-'0' > maxi)
                maxi = a-'0';
        }
        return maxi;
    }
};