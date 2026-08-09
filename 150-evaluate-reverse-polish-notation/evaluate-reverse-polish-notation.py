class Solution:
    def evalRPN(self, tokens):
        s = []
        for x in tokens:
            if x not in "+-*/":
                s.append(int(x))
            else:
                b, a = s.pop(), s.pop()
                if x == '+':
                    s.append(a + b)
                elif x == '-':
                    s.append(a - b)
                elif x == '*':
                    s.append(a * b)
                else:
                    s.append(a // b if a * b >= 0 else -(abs(a) // abs(b)))
        return s[-1]