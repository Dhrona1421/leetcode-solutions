class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int left = 0, ones = 0;

        for (int right = 0; right < s.size(); right++) {
            if (s[right] == '1') ones++;

            while (ones > k) {
                if (s[left++] == '1') ones--;
            }

            if (ones == k) {
                while (s[left] == '0') left++;

                string cur = s.substr(left, right - left + 1);

                if (ans.empty() || cur.size() < ans.size() ||
                    (cur.size() == ans.size() && cur < ans))
                    ans = cur;
            }
        }

        return ans;
    }
};