class Solution:
    def uncommonFromSentences(self, s1, s2):
        from collections import Counter
        c = Counter(s1.split() + s2.split())
        return [w for w in c if c[w] == 1]