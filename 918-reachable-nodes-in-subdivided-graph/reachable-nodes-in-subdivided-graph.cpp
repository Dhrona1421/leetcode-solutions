class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int n) {
        vector<vector<pair<int,int>>> g(n);
        for(auto &e: edges) {
            g[e[0]].push_back({e[1],e[2]});
            g[e[1]].push_back({e[0],e[2]});
        }

        vector<int> d(n, M + 1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        d[0] = 0;
        pq.push({0,0});

        while(!pq.empty()) {
            auto [du,u] = pq.top(); pq.pop();
            if(du != d[u]) continue;

            for(auto [v,w] : g[u]) {
                int nd = du + w + 1;
                if(nd <= M && nd < d[v])
                    d[v] = nd, pq.push({nd,v});
            }
        }

        int ans = 0;
        for(int x : d)
            ans += x <= M;

        for(auto &e : edges) {
            int a = max(0, M - d[e[0]]);
            int b = max(0, M - d[e[1]]);
            ans += min(e[2], a + b);
        }

        return ans;
    }
};