class Solution:
    def generateParenthesis(self, n):
        result = []

        def backtrack(s, left, right):
            if len(s) == 2 * n:
                result.append(s)
                return

            if left < n:
                backtrack(s + "(", left + 1, right)

            if right < left:
                backtrack(s + ")", left, right + 1)

        backtrack("", 0, 0)
        return result