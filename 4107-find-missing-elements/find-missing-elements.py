class Solution:
    def findMissingElements(self, nums):
        s = set(nums)
        return [i for i in range(min(nums), max(nums) + 1) if i not in s]