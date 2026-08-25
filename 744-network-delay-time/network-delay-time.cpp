class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> g(n + 1);
        for (auto &t : times)
            g[t[0]].push_back({t[1], t[2]});

        vector<int> d(n + 1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        d[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [time, u] = pq.top();
            pq.pop();

            if (time > d[u]) continue;

            for (auto [v, w] : g[u]) {
                if (time + w < d[v]) {
                    d[v] = time + w;
                    pq.push({d[v], v});
                }
            }
        }

        int ans = *max_element(d.begin() + 1, d.end());
        return ans == INT_MAX ? -1 : ans;
    }
};