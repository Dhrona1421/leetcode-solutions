class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                
                if (dp[i] <= INT_MAX - dp[i - coin]) {
                    dp[i] += dp[i - coin];
                } else {
                    dp[i] = INT_MAX; 
                }
            }
        }

        return dp[amount];
    }
};
