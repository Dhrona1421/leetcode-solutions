class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> first;
        first[0] = -1;

        int sum = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 1 ? 1 : -1);

            if (first.count(sum)) {
                ans = max(ans, i - first[sum]);
            } else {
                first[sum] = i;
            }
        }

        return ans;
    }
};