class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long reach = 0;
        int patches = 0;
        int i = 0;

        while (reach < n) {
            if (i < nums.size() && nums[i] <= reach + 1) {
                reach += nums[i];
                i++;
            } else {
                reach += reach + 1;
                patches++;
            }
        }

        return patches;
    }
};