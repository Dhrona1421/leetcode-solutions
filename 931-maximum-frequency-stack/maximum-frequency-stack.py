class FreqStack:

    def __init__(self):
        self.freq = {}
        self.groups = {}
        self.max_freq = 0

    def push(self, val):
        f = self.freq.get(val, 0) + 1
        self.freq[val] = f
        self.max_freq = max(self.max_freq, f)

        self.groups.setdefault(f, []).append(val)

    def pop(self):
        val = self.groups[self.max_freq].pop()
        self.freq[val] -= 1

        if not self.groups[self.max_freq]:
            self.max_freq -= 1

        return val