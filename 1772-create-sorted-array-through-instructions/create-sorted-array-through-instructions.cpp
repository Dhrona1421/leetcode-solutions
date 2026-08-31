class Solution {
public:
    static const int MOD = 1e9 + 7;

    void update(vector<int>& bit, int i) {
        while (i < bit.size()) {
            bit[i]++;
            i += i & -i;
        }
    }

    int query(vector<int>& bit, int i) {
        int sum = 0;

        while (i > 0) {
            sum += bit[i];
            i -= i & -i;
        }

        return sum;
    }

    int createSortedArray(vector<int>& instructions) {
        const int MAXV = 100000;

        vector<int> bit(MAXV + 1);
        long long cost = 0;
        int seen = 0;

        for (int x : instructions) {
            int smaller = query(bit, x - 1);
            int greater = seen - query(bit, x);

            cost = (cost + min(smaller, greater)) % MOD;

            update(bit, x);
            seen++;
        }

        return cost;
    }
};