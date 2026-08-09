class Solution:
    def largestRectangleArea(self, heights):
        stack = []
        ans = 0
        for i, h in enumerate(heights + [0]):
            while stack and heights[stack[-1]] > h:
                j = stack.pop()
                left = stack[-1] if stack else -1
                ans = max(ans, heights[j] * (i - left - 1))
            stack.append(i)
        return ans