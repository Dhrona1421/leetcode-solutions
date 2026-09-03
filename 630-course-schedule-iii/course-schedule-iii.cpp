class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),
             [](const auto& a, const auto& b) {
                 return a[1] < b[1];
             });

        priority_queue<int> pq;
        int time = 0;

        for (auto& c : courses) {
            int duration = c[0];
            int deadline = c[1];

            time += duration;
            pq.push(duration);

            if (time > deadline) {
                time -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};