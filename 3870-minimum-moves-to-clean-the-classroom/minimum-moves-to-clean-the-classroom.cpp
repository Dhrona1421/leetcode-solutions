class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int sr = 0, sc = 0, k = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (classroom[i][j] == 'L') {
                    id[i][j] = k++;
                }
            }
        }

        if (k == 0) return 0;

        int fullMask = (1 << k) - 1;

        struct State {
            int r, c, mask, energy;
        };

        queue<State> q;

        int totalStates = m * n * (1 << k) * (energy + 1);
        vector<char> visited(totalStates, false);

        auto encode = [&](int r, int c, int mask, int e) {
            return (((r * n + c) * (1 << k) + mask) * (energy + 1) + e);
        };

        q.push({sr, sc, 0, energy});
        visited[encode(sr, sc, 0, energy)] = true;

        int moves = 0;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                State cur = q.front();
                q.pop();

                if (cur.mask == fullMask)
                    return moves;

                if (cur.energy == 0 && classroom[cur.r][cur.c] != 'R')
                    continue;

                for (int d = 0; d < 4; ++d) {
                    int nr = cur.r + dr[d];
                    int nc = cur.c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    if (cur.energy == 0)
                        continue;

                    int ne = cur.energy - 1;
                    int nmask = cur.mask;

                    if (classroom[nr][nc] == 'L') {
                        nmask |= (1 << id[nr][nc]);
                    }

                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    int key = encode(nr, nc, nmask, ne);

                    if (!visited[key]) {
                        visited[key] = true;
                        q.push({nr, nc, nmask, ne});
                    }
                }
            }

            ++moves;
        }

        return -1;
    }
};