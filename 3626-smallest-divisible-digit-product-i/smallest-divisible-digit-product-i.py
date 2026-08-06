class Solution:
    def smallestNumber(self, n, t):
        while True:
            p = 1
            for c in str(n):
                p *= ord(c) - 48
            if p % t == 0:
                return n
            n += 1