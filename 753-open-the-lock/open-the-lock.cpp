class Solution {
public:
    string getNext(string s, int i, int dir) {
        s[i] = (s[i] - '0' + dir + 10) % 10 + '0';
        return s;
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> vis;

        if (dead.count("0000"))
            return -1;

        queue<string> q;
        q.push("0000");
        vis.insert("0000");

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                string cur = q.front();
                q.pop();

                if (cur == target)
                    return steps;

                for (int i = 0; i < 4; i++) {
                    for (int dir : {-1, 1}) {
                        string next = getNext(cur, i, dir);

                        if (!dead.count(next) && !vis.count(next)) {
                            vis.insert(next);
                            q.push(next);
                        }
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};