class DSU:
    def __init__(self, n):
        self.p = list(range(n))
        self.c = n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        a, b = self.find(a), self.find(b)
        if a == b:
            return False
        self.p[a] = b
        self.c -= 1
        return True


class Solution:
    def maxNumEdgesToRemove(self, n, edges):
        A, B = DSU(n), DSU(n)
        used = 0

        for t, u, v in edges:
            if t == 3:
                if A.union(u - 1, v - 1):
                    B.union(u - 1, v - 1)
                    used += 1

        for t, u, v in edges:
            if t == 1 and A.union(u - 1, v - 1):
                used += 1
            elif t == 2 and B.union(u - 1, v - 1):
                used += 1

        return len(edges) - used if A.c == 1 and B.c == 1 else -1