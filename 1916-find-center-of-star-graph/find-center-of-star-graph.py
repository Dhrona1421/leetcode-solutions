class Solution:
    def findCenter(self, edges):
        a, b = edges[0]
        c, d = edges[1]

        if a == c or a == d:
            return a
        return b