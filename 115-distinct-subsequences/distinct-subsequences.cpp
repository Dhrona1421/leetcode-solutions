class Solution {
public:
    int numDistinct(string s, string t) {
        vector<unsigned long long> dp(t.size() + 1);
        dp[0] = 1;

        for (char c : s)
            for (int j = t.size(); j >= 1; --j)
                if (c == t[j - 1])
                    dp[j] += dp[j - 1];

        return dp[t.size()];
    }
};