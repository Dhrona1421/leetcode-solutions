class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; --i)
            suffixMin[i] = min(suffixMin[i + 1], (long long)nums[i]);

        long long prefixMax = 0;

        for (int i = 0; i < n; ++i) {
            prefixMax = max(prefixMax, (long long)nums[i]);

            if (prefixMax - suffixMin[i] <= k)
                return i;
        }

        return -1;
    }
};