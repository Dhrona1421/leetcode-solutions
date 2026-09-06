class Solution {
public:
    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (rankv[a] < rankv[b])
            swap(a, b);

        parent[b] = a;

        if (rankv[a] == rankv[b])
            rankv[a]++;
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();

        parent.resize(n);
        rankv.assign(n, 0);

        iota(parent.begin(), parent.end(), 0);

        for (auto& p : pairs)
            unite(p[0], p[1]);

        unordered_map<int, vector<int>> groups;

        for (int i = 0; i < n; i++)
            groups[find(i)].push_back(i);

        for (auto& [root, indices] : groups) {
            string chars;

            for (int i : indices)
                chars += s[i];

            sort(chars.begin(), chars.end());

            for (int i = 0; i < (int)indices.size(); i++)
                s[indices[i]] = chars[i];
        }

        return s;
    }
};