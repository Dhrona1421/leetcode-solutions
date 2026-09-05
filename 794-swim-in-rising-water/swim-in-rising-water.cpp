class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        int lo = grid[0][0], hi = n * n - 1;

        auto canReach = [&](int t) {
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            queue<pair<int, int>> q;

            if (grid[0][0] > t)
                return false;

            q.push({0, 0});
            vis[0][0] = true;

            int dr[] = {1, -1, 0, 0};
            int dc[] = {0, 0, 1, -1};

            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                if (r == n - 1 && c == n - 1)
                    return true;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                        !vis[nr][nc] && grid[nr][nc] <= t) {
                        vis[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }

            return false;
        };

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (canReach(mid))
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};