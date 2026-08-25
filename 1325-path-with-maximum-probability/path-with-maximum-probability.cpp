class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& p, int s, int t) {
        vector<vector<pair<int,double>>> g(n);
        for (int i = 0; i < e.size(); i++)
            g[e[i][0]].push_back({e[i][1], p[i]}),
            g[e[i][1]].push_back({e[i][0], p[i]});

        vector<double> d(n);
        priority_queue<pair<double,int>> q;
        d[s] = 1;
        q.push({1, s});

        while (!q.empty()) {
            auto [x,u] = q.top(); q.pop();
            if (u == t) return x;
            if (x < d[u]) continue;

            for (auto [v,w] : g[u])
                if (x*w > d[v])
                    d[v] = x*w, q.push({d[v],v});
        }
        return 0;
    }
};