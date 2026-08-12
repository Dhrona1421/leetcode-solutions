class Solution:
    def sumOfDistancesInTree(self, n, edges):
        graph = [[] for _ in range(n)]

        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        count = [1] * n
        ans = [0] * n

        def dfs1(node, parent):
            for nei in graph[node]:
                if nei == parent:
                    continue

                dfs1(nei, node)
                count[node] += count[nei]
                ans[node] += ans[nei] + count[nei]

        def dfs2(node, parent):
            for nei in graph[node]:
                if nei == parent:
                    continue

                ans[nei] = ans[node] - count[nei] + (n - count[nei])
                dfs2(nei, node)

        dfs1(0, -1)
        dfs2(0, -1)

        return ans