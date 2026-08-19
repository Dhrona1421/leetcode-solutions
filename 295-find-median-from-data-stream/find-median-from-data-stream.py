import heapq

class MedianFinder:

    def __init__(self):
        self.small = []
        self.large = []

    def addNum(self, num):
        heapq.heappush(self.small, -num)

        if self.large and -self.small[0] > self.large[0]:
            x = -heapq.heappop(self.small)
            y = heapq.heappop(self.large)

            heapq.heappush(self.small, -y)
            heapq.heappush(self.large, x)

        if len(self.small) > len(self.large) + 1:
            heapq.heappush(self.large, -heapq.heappop(self.small))

        elif len(self.large) > len(self.small):
            heapq.heappush(self.small, -heapq.heappop(self.large))

    def findMedian(self):
        if len(self.small) > len(self.large):
            return -self.small[0]

        return (-self.small[0] + self.large[0]) / 2.0