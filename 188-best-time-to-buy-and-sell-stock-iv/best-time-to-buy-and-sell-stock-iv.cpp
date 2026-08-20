class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty() || k == 0)
            return 0;

        // If k is large enough, transactions are effectively unlimited
        if (k >= prices.size() / 2) {
            int profit = 0;

            for (int i = 1; i < prices.size(); i++)
                profit += max(0, prices[i] - prices[i - 1]);

            return profit;
        }

        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);

        for (int price : prices) {
            for (int t = 1; t <= k; t++) {
                buy[t] = max(buy[t], sell[t - 1] - price);
                sell[t] = max(sell[t], buy[t] + price);
            }
        }

        return sell[k];
    }
};