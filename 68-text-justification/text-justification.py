class Solution:
    def fullJustify(self, words, maxWidth):
        res, cur, letters = [], [], 0

        for w in words:
            if letters + len(w) + len(cur) > maxWidth:
                for i in range(maxWidth - letters):
                    cur[i % (len(cur) - 1 or 1)] += " "
                res.append("".join(cur))
                cur, letters = [], 0

            cur.append(w)
            letters += len(w)

        return res + [" ".join(cur).ljust(maxWidth)]