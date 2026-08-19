class Solution:
    def longestIncreasingPath(self, matrix):
        rows = len(matrix)
        cols = len(matrix[0])

        dp = [[0] * cols for _ in range(rows)]

        def dfs(r, c):
            if dp[r][c]:
                return dp[r][c]

            best = 1

            for dr, dc in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                nr = r + dr
                nc = c + dc

                if (0 <= nr < rows and
                    0 <= nc < cols and
                    matrix[nr][nc] > matrix[r][c]):

                    best = max(best, 1 + dfs(nr, nc))

            dp[r][c] = best
            return best

        answer = 0

        for r in range(rows):
            for c in range(cols):
                answer = max(answer, dfs(r, c))

        return answer