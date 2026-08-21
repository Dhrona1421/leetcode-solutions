class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<bool> dp(n + 1, false);

        dp[0] = true;

        for (int j = 2; j <= n; j += 2)
            if (p[j - 1] == '*')
                dp[j] = dp[j - 2];

        for (int i = 1; i <= m; i++) {
            vector<bool> cur(n + 1, false);

            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    cur[j] = dp[j - 1];
                } 
                else if (p[j - 1] == '*') {
                    cur[j] = cur[j - 2];

                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1])
                        cur[j] = cur[j] || dp[j];
                }
            }

            dp = cur;
        }

        return dp[n];
    }
};