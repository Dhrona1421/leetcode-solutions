class Solution {
public:
    int n, m;

    int countIslands(vector<vector<int>>& grid) {
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int islands = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    islands++;

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = true;

                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();

                        int dr[] = {1, -1, 0, 0};
                        int dc[] = {0, 0, 1, -1};

                        for (int k = 0; k < 4; k++) {
                            int nr = r + dr[k];
                            int nc = c + dc[k];

                            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                                grid[nr][nc] == 1 && !vis[nr][nc]) {
                                vis[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }

    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        if (countIslands(grid) != 1)
            return 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;

                    if (countIslands(grid) != 1)
                        return 1;

                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};