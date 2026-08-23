class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        for (int i = 0; i < half; i++) {
            if (num[i] == '?')
                leftQ++;
            else
                leftSum += num[i] - '0';
        }

        for (int i = half; i < n; i++) {
            if (num[i] == '?')
                rightQ++;
            else
                rightSum += num[i] - '0';
        }

        int diff = leftSum - rightSum;
        int qDiff = leftQ - rightQ;

        if ((leftQ + rightQ) % 2 == 1)
            return true;

        if (qDiff == 0)
            return diff != 0;

        if (qDiff > 0)
            diff += (qDiff / 2) * 9;
        else
            diff -= (-qDiff / 2) * 9;

        return diff != 0;
    }
};