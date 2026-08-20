class SummaryRanges {
public:
    map<int, int> intervals;

    SummaryRanges() {
    }

    void addNum(int value) {
        auto it = intervals.upper_bound(value);

        // Check if value is already inside/covered by left interval
        if (it != intervals.begin()) {
            auto prev = std::prev(it);

            if (prev->second >= value)
                return;
        }

        bool mergeLeft = false;
        bool mergeRight = false;

        auto right = it;

        if (it != intervals.begin()) {
            auto left = std::prev(it);
            mergeLeft = (left->second + 1 == value);
        }

        if (right != intervals.end()) {
            mergeRight = (value + 1 == right->first);
        }

        // Connect two intervals through value
        if (mergeLeft && mergeRight) {
            auto left = std::prev(it);
            left->second = right->second;
            intervals.erase(right);
        }

        // Extend left interval
        else if (mergeLeft) {
            auto left = std::prev(it);
            left->second = value;
        }

        // Extend right interval
        else if (mergeRight) {
            int end = right->second;
            intervals.erase(right);
            intervals[value] = end;
        }

        // Create new interval
        else {
            intervals[value] = value;
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;

        for (auto& [start, end] : intervals)
            ans.push_back({start, end});

        return ans;
    }
};