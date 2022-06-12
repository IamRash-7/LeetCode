class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0], sum=0;
        for(int i=0;i<prices.size();i++)
        {
            mini = min(mini,prices[i]);
            sum = max(sum,prices[i]-mini);
        }
        return sum;
    }
};