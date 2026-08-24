class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = s.size(), w = words[0].size(), total = words.size();

        unordered_map<string, int> need;
        for (string &word : words) need[word]++;

        for (int start = 0; start < w; start++) {
            unordered_map<string, int> have;
            int left = start, count = 0;

            for (int right = start; right + w <= n; right += w) {
                string word = s.substr(right, w);

                if (!need.count(word)) {
                    have.clear();
                    count = 0;
                    left = right + w;
                    continue;
                }

                have[word]++;
                count++;

                while (have[word] > need[word]) {
                    have[s.substr(left, w)]--;
                    left += w;
                    count--;
                }

                if (count == total) {
                    ans.push_back(left);
                    have[s.substr(left, w)]--;
                    left += w;
                    count--;
                }
            }
        }

        return ans;
    }
};