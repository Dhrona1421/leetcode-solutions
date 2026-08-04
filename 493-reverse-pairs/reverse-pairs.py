from sortedcontainers import SortedList

class Solution:
    def reversePairs(self, nums):
        s = SortedList()
        ans = 0
        for x in nums:
            ans += len(s) - s.bisect_right(2 * x)
            s.add(x)
        return ans