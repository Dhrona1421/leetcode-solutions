class Solution:
    def singleNumber(self, nums):
        x = 0
        for i in nums:
            x ^= i
        return x