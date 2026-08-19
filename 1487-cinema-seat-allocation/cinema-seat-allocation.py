class Solution:
    def maxNumberOfFamilies(self, n, reservedSeats):
        rows = {}

        for r, s in reservedSeats:
            if r not in rows:
                rows[r] = set()
            rows[r].add(s)

        ans = (n - len(rows)) * 2

        for seats in rows.values():
            left = all(s not in seats for s in [2, 3, 4, 5])
            middle = all(s not in seats for s in [4, 5, 6, 7])
            right = all(s not in seats for s in [6, 7, 8, 9])

            if left and right:
                ans += 2
            elif left or middle or right:
                ans += 1

        return ans