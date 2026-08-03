class Solution:
    def firstUniqChar(self, s):
        count = {}

        for c in s:
            count[c] = count.get(c, 0) + 1

        for i, c in enumerate(s):
            if count[c] == 1:
                return i

        return -1