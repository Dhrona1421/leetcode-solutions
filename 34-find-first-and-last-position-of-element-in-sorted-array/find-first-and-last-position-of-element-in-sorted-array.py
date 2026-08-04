from bisect import bisect_left, bisect_right

class Solution:
    def searchRange(self, nums, target):
        l = bisect_left(nums, target)
        r = bisect_right(nums, target) - 1
        return [l, r] if l < len(nums) and nums[l] == target else [-1, -1]