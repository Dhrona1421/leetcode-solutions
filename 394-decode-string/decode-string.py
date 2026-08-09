class Solution:
    def decodeString(self, s):
        stack = []
        num = cur = ""
        
        for c in s:
            if c.isdigit():
                num += c
            elif c == '[':
                stack.append((cur, int(num)))
                cur, num = "", ""
            elif c == ']':
                prev, k = stack.pop()
                cur = prev + cur * k
            else:
                cur += c
        
        return cur