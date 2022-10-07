class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }

        int totalProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            // Checking if we can profit with previous day's price.
            // If yes, then we buy on previous day and sell on current day.
            // Add all such profits to get the total profit.
            if (prices[i - 1] < prices[i]) {
                totalProfit += prices[i] - prices[i - 1];
            }
        }

        return totalProfit;
    }
};