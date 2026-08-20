class Solution {
public:
    int tribonacci(int n) {
        int a = 0, b = 1, c = 1;

        for (int i = 3; i <= n; i++) {
            int next = a + b + c;
            a = b;
            b = c;
            c = next;
        }

        if (n == 0) return a;
        if (n == 1) return b;
        return c;
    }
};