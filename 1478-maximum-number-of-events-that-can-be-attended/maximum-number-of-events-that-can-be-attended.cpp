class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> pq;

        int n = events.size();
        int i = 0;
        int day = 0;
        int ans = 0;

        while (i < n || !pq.empty()) {
            if (pq.empty())
                day = events[i][0];

            while (i < n && events[i][0] <= day) {
                pq.push(events[i][1]);
                ++i;
            }

            while (!pq.empty() && pq.top() < day)
                pq.pop();

            if (!pq.empty()) {
                pq.pop();
                ++ans;
                ++day;
            }
        }

        return ans;
    }
};