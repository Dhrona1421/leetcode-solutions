class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int m = h.size(), n = h[0].size();
        vector<vector<int>> d(m, vector<int>(n, INT_MAX));
        priority_queue<tuple<int,int,int>,
                       vector<tuple<int,int,int>>,
                       greater<>> q;

        d[0][0] = 0;
        q.push({0, 0, 0});

        int dr[] = {1,-1,0,0}, dc[] = {0,0,1,-1};

        while (!q.empty()) {
            auto [e,r,c] = q.top(); q.pop();
            if (r == m-1 && c == n-1) return e;
            if (e > d[r][c]) continue;

            for (int k = 0; k < 4; k++) {
                int x = r + dr[k], y = c + dc[k];
                if (x < 0 || y < 0 || x >= m || y >= n) continue;

                int ne = max(e, abs(h[r][c] - h[x][y]));
                if (ne < d[x][y])
                    d[x][y] = ne, q.push({ne,x,y});
            }
        }
        return 0;
    }
};