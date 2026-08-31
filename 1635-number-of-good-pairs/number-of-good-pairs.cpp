class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        unordered_map<int, int> freq;

        for (int num : nums) {
            count += freq[num];
            freq[num]++;
        }

        return count;
    }
};