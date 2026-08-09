class Solution:
    def stoneGameII(self, piles):
        n = len(piles)
        suffix = [0] * (n + 1)

        for i in range(n - 1, -1, -1):
            suffix[i] = suffix[i + 1] + piles[i]

        dp = [[0] * (n + 2) for _ in range(n)]

        for i in range(n - 1, -1, -1):
            for m in range(n, 0, -1):
                if i + 2 * m >= n:
                    dp[i][m] = suffix[i]
                    continue

                best = 0
                for x in range(1, 2 * m + 1):
                    best = max(best, suffix[i] - dp[i + x][max(m, x)])
                dp[i][m] = best

        return dp[0][1]