class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n = p.size(), ans = 0;
        vector<int> d(n, INT_MAX);
        vector<bool> used(n);
        d[0] = 0;

        for (int i = 0; i < n; i++) {
            int u = -1;
            for (int j = 0; j < n; j++)
                if (!used[j] && (u == -1 || d[j] < d[u])) u = j;

            used[u] = true;
            ans += d[u];

            for (int v = 0; v < n; v++)
                if (!used[v])
                    d[v] = min(d[v],
                               abs(p[u][0] - p[v][0]) +
                               abs(p[u][1] - p[v][1]));
        }

        return ans;
    }
};