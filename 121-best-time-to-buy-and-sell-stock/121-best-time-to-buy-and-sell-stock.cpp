class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minval = INT_MAX;
        int maxprof = 0;
        for(int i=0;i<prices.size();i++)
        {
            minval = min(minval, prices[i]);
            maxprof = max(maxprof, prices[i]-minval);
        }
        return maxprof;
    }
};