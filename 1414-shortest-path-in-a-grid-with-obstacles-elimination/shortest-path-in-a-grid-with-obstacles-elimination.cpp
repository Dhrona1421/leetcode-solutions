class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        if (m == 1 && n == 1)
            return 0;

        vector<vector<int>> best(m, vector<int>(n, -1));
        queue<array<int, 3>> q;

        q.push({0, 0, k});
        best[0][0] = k;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, rem] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    int nextRem = rem - grid[nr][nc];

                    if (nextRem < 0 || nextRem <= best[nr][nc])
                        continue;

                    if (nr == m - 1 && nc == n - 1)
                        return steps + 1;

                    best[nr][nc] = nextRem;
                    q.push({nr, nc, nextRem});
                }
            }

            steps++;
        }

        return -1;
    }
};
