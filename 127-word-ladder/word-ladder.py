from collections import deque

class Solution:
    def ladderLength(self, beginWord, endWord, wordList):
        words = set(wordList)

        if endWord not in words:
            return 0

        q = deque([(beginWord, 1)])
        visited = {beginWord}

        while q:
            word, steps = q.popleft()

            if word == endWord:
                return steps

            for i in range(len(word)):
                for ch in 'abcdefghijklmnopqrstuvwxyz':
                    new_word = word[:i] + ch + word[i + 1:]

                    if new_word in words and new_word not in visited:
                        visited.add(new_word)
                        q.append((new_word, steps + 1))

        return 0