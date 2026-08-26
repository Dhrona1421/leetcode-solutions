class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> d(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; i++)
            d[i][i] = 0;

        for (auto &e : edges) {
            d[e[0]][e[1]] = e[2];
            d[e[1]][e[0]] = e[2];
        }

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

        int ans = -1, best = n;

        for (int i = 0; i < n; i++) {
            int cnt = 0;

            for (int j = 0; j < n; j++)
                if (i != j && d[i][j] <= distanceThreshold)
                    cnt++;

            if (cnt <= best) {
                best = cnt;
                ans = i;
            }
        }

        return ans;
    }
};