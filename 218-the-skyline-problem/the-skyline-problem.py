import heapq

class Solution:
    def getSkyline(self, buildings):
        events = []

        for left, right, height in buildings:
            events.append((left, -height, right))
            events.append((right, 0, 0))

        events.sort()

        heap = [(0, float("inf"))]
        result = []
        prev = 0

        for x, neg_height, right in events:
            while heap[0][1] <= x:
                heapq.heappop(heap)

            if neg_height:
                heapq.heappush(heap, (neg_height, right))

            curr = -heap[0][0]

            if curr != prev:
                result.append([x, curr])
                prev = curr

        return result