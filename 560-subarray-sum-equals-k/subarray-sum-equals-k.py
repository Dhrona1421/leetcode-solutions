from collections import defaultdict

class Solution:
    def subarraySum(self, nums, k):
        d = defaultdict(int)
        d[0] = 1
        s = ans = 0
        for x in nums:
            s += x
            ans += d[s - k]
            d[s] += 1
        return ans