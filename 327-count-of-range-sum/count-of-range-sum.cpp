class Solution {
public:
    long long count = 0;
    long long lower, upper;

    void mergeSort(vector<long long>& sums, int left, int right) {
        if (right - left <= 1)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(sums, left, mid);
        mergeSort(sums, mid, right);

        int j = mid, k = mid;

        for (int i = left; i < mid; i++) {
            while (j < right && sums[j] - sums[i] < lower)
                j++;

            while (k < right && sums[k] - sums[i] <= upper)
                k++;

            count += k - j;
        }

        inplace_merge(sums.begin() + left,
                      sums.begin() + mid,
                      sums.begin() + right);
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        this->lower = lower;
        this->upper = upper;

        vector<long long> prefix(nums.size() + 1, 0);

        for (int i = 0; i < nums.size(); i++)
            prefix[i + 1] = prefix[i] + nums[i];

        mergeSort(prefix, 0, prefix.size());

        return count;
    }
};
