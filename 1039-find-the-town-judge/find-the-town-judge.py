class Solution:
    def findJudge(self, n, trust):
        score = [0] * (n + 1)

        for a, b in trust:
            score[a] -= 1
            score[b] += 1

        for person in range(1, n + 1):
            if score[person] == n - 1:
                return person

        return -1