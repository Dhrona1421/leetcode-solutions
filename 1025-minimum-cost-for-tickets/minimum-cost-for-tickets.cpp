class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int one = dp[i + 1] + costs[0];

            int j = i;
            while (j < n && days[j] < days[i] + 7)
                j++;
            int seven = dp[j] + costs[1];

            j = i;
            while (j < n && days[j] < days[i] + 30)
                j++;
            int thirty = dp[j] + costs[2];

            dp[i] = min({one, seven, thirty});
        }

        return dp[0];
    }
};