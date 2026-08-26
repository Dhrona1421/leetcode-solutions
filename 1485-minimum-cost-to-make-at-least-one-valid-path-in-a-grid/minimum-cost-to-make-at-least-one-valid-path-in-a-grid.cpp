class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        deque<pair<int,int>> dq;
        vector<vector<int>> dist(m, vector<int>(n, 1e9));

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        dq.push_front({0, 0});
        dist[0][0] = 0;

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                int cost = dist[r][c] + (grid[r][c] != d + 1);

                if (cost < dist[nr][nc]) {
                    dist[nr][nc] = cost;

                    if (grid[r][c] == d + 1)
                        dq.push_front({nr, nc});
                    else
                        dq.push_back({nr, nc});
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};