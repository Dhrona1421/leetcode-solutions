class Solution {
public:
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;
        vector<vector<int>> ans;

        for (int i = 0; i < words.size(); ++i)
            mp[words[i]] = i;

        for (int i = 0; i < words.size(); ++i) {
            string& w = words[i];
            int n = w.size();

            for (int j = 0; j <= n; ++j) {
                if (isPalindrome(w, 0, j - 1)) {
                    string right = w.substr(j);
                    reverse(right.begin(), right.end());

                    if (mp.count(right) && mp[right] != i)
                        ans.push_back({mp[right], i});
                }

                if (j < n && isPalindrome(w, j, n - 1)) {
                    string left = w.substr(0, j);
                    reverse(left.begin(), left.end());

                    if (mp.count(left) && mp[left] != i)
                        ans.push_back({i, mp[left]});
                }
            }
        }

        return ans;
    }
};