from collections import defaultdict

class Solution:
    def findItinerary(self, tickets):
        graph = defaultdict(list)

        for a, b in sorted(tickets, reverse=True):
            graph[a].append(b)

        route = []

        def dfs(airport):
            while graph[airport]:
                next_airport = graph[airport].pop()
                dfs(next_airport)

            route.append(airport)

        dfs("JFK")

        return route[::-1]