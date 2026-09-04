class Solution {
public:
    int minimumDistance(string word) {
        int n = word.size();
        
        auto dist = [](int a, int b) {
            int x1 = a / 6, y1 = a % 6;
            int x2 = b / 6, y2 = b % 6;
            return abs(x1 - x2) + abs(y1 - y2);
        };

        const int INF = 1e9;

        vector<vector<int>> dp(26, vector<int>(26, INF));

        int first = word[0] - 'A';

        // One finger starts at the first character.
        // The other finger can start anywhere for free.
        for (int j = 0; j < 26; j++)
            dp[first][j] = 0;

        for (int i = 1; i < n; i++) {
            int cur = word[i] - 'A';
            int prev = word[i - 1] - 'A';

            vector<vector<int>> ndp(26, vector<int>(26, INF));

            for (int a = 0; a < 26; a++) {
                for (int b = 0; b < 26; b++) {
                    if (dp[a][b] == INF)
                        continue;

                    // Finger 1 types current character.
                    ndp[cur][b] = min(
                        ndp[cur][b],
                        dp[a][b] + dist(a, cur)
                    );

                    // Finger 2 types current character.
                    ndp[a][cur] = min(
                        ndp[a][cur],
                        dp[a][b] + dist(b, cur)
                    );
                }
            }

            dp.swap(ndp);
        }

        int ans = INF;

        for (int a = 0; a < 26; a++)
            for (int b = 0; b < 26; b++)
                ans = min(ans, dp[a][b]);

        return ans;
    }
};