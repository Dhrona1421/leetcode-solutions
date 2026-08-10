class Solution:
    def letterCombinations(self, digits):
        if not digits:
            return []

        phone = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        ans = []

        def solve(i, s):
            if i == len(digits):
                ans.append(s)
                return

            for c in phone[int(digits[i])]:
                solve(i + 1, s + c)

        solve(0, "")
        return ans