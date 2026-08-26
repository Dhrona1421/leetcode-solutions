class Solution:
    def spiralMatrixIII(self, rows, cols, rStart, cStart):
        ans = []
        r, c, step = rStart, cStart, 1

        while len(ans) < rows * cols:
            for _ in range(step):
                if 0 <= r < rows and 0 <= c < cols:
                    ans.append([r, c])
                c += 1
            for _ in range(step):
                if 0 <= r < rows and 0 <= c < cols:
                    ans.append([r, c])
                r += 1
            step += 1

            for _ in range(step):
                if 0 <= r < rows and 0 <= c < cols:
                    ans.append([r, c])
                c -= 1
            for _ in range(step):
                if 0 <= r < rows and 0 <= c < cols:
                    ans.append([r, c])
                r -= 1
            step += 1

        return ans