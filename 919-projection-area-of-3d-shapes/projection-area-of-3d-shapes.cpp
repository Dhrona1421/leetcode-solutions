class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;

        for (int i = 0; i < n; i++) {
            int row = 0, col = 0;
            for (int j = 0; j < n; j++) {
                ans += grid[i][j] > 0;
                row = max(row, grid[i][j]);
                col = max(col, grid[j][i]);
            }
            ans += row + col;
        }

        return ans;
    }
};