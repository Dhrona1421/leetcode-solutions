class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        // sort indices by their value in nums
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        vector<int> result(n);
        int i = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && nums[idx[j + 1]] - nums[idx[j]] <= limit) {
                j++;
            }
            // group is idx[i..j], values already sorted ascending
            vector<int> groupIndices(idx.begin() + i, idx.begin() + j + 1);
            sort(groupIndices.begin(), groupIndices.end()); // original positions, ascending
            for (int t = 0; t < (int)groupIndices.size(); t++) {
                result[groupIndices[t]] = nums[idx[i + t]];
            }
            i = j + 1;
        }
        return result;
    }
};