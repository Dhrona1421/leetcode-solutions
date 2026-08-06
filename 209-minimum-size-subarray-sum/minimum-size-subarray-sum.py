class Solution:
    def minSubArrayLen(self, target, nums):
        l = s = 0
        ans = float('inf')
        for r, x in enumerate(nums):
            s += x
            while s >= target:
                ans = min(ans, r - l + 1)
                s -= nums[l]
                l += 1
        return 0 if ans == float('inf') else ans