class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                                vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        int n = intervals.size();

        // Intervals completely before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        // Merge overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        // Add merged interval
        ans.push_back(newInterval);

        // Intervals completely after newInterval
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};