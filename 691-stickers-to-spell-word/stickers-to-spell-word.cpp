class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = target.size();
        int total = 1 << n;

        vector<int> dp(total, n + 1);
        dp[0] = 0;

        vector<vector<int>> cnt(stickers.size(), vector<int>(26));

        for (int i = 0; i < stickers.size(); i++)
            for (char c : stickers[i])
                cnt[i][c - 'a']++;

        for (int mask = 0; mask < total; mask++) {
            if (dp[mask] == n + 1) continue;

            for (auto &sticker : cnt) {
                vector<int> have = sticker;
                int newMask = mask;

                for (int i = 0; i < n; i++) {
                    if (!(newMask & (1 << i)) && have[target[i] - 'a']) {
                        newMask |= 1 << i;
                        have[target[i] - 'a']--;
                    }
                }

                dp[newMask] = min(dp[newMask], dp[mask] + 1);
            }
        }

        return dp[total - 1] == n + 1 ? -1 : dp[total - 1];
    }
};