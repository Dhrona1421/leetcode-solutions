class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0;
        int prev1 = 0;

        for (int money : nums) {
            int curr = max(prev1, prev2 + money);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};