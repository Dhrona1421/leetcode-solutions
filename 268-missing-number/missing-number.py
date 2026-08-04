class Solution:
    def missingNumber(self, nums):
        return len(nums) * (len(nums) + 1) // 2 - sum(nums)