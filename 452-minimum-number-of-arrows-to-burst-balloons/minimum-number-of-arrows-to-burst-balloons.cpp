class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        sort(points.begin(), points.end(),
             [](const auto& a, const auto& b) {
                 return a[1] < b[1];
             });

        int arrows = 1;
        long long pos = points[0][1];

        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > pos) {
                ++arrows;
                pos = points[i][1];
            }
        }

        return arrows;
    }
};