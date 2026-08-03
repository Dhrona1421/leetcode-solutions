class Solution:
    def groupAnagrams(self, strs):
        groups = {}

        for s in strs:
            key = tuple(sorted(s))
            groups.setdefault(key, []).append(s)

        return list(groups.values())