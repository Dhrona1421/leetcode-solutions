class Solution:
    def remainingMethods(self, n, k, invocations):
        graph = [[] for _ in range(n)]
        rev = [[] for _ in range(n)]

        for u, v in invocations:
            graph[u].append(v)
            rev[v].append(u)

        suspicious = [False] * n
        stack = [k]

        while stack:
            u = stack.pop()
            if suspicious[u]:
                continue
            suspicious[u] = True
            for v in graph[u]:
                if not suspicious[v]:
                    stack.append(v)

        for i in range(n):
            if not suspicious[i]:
                for v in graph[i]:
                    if suspicious[v]:
                        return list(range(n))

        return [i for i in range(n) if not suspicious[i]]