from bisect import bisect_left, insort

class Solution:
    def countSmaller(self, nums):
        s = []
        ans = []
        for x in nums[::-1]:
            i = bisect_left(s, x)
            ans.append(i)
            insort(s, x)
        return ans[::-1]