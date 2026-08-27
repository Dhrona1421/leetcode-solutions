class Solution:
    def findCriticalAndPseudoCriticalEdges(self, n, edges):
        E = sorted((w, u, v, i) for i, (u, v, w) in enumerate(edges))

        def mst(skip=-1, force=-1):
            p = list(range(n))

            def find(x):
                while p[x] != x:
                    p[x] = p[p[x]]
                    x = p[x]
                return x

            cost = 0

            if force != -1:
                w, u, v, _ = E[force]
                p[find(u)] = find(v)
                cost += w

            for i, (w, u, v, _) in enumerate(E):
                if i == skip or i == force:
                    continue
                a, b = find(u), find(v)
                if a != b:
                    p[a] = b
                    cost += w

            return cost if all(find(i) == find(0) for i in range(n)) else float('inf')

        base = mst()
        critical, pseudo = [], []

        for i in range(len(E)):
            if mst(skip=i) > base:
                critical.append(E[i][3])
            elif mst(force=i) == base:
                pseudo.append(E[i][3])

        return [critical, pseudo]