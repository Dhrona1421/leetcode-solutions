class RandomizedCollection {
    vector<int> nums;
    unordered_map<int, unordered_set<int>> pos;

public:
    RandomizedCollection() {}

    bool insert(int val) {
        bool first = !pos.count(val);
        pos[val].insert(nums.size());
        nums.push_back(val);
        return first;
    }

    bool remove(int val) {
        if (!pos.count(val) || pos[val].empty())
            return false;

        int idx = *pos[val].begin();
        int lastIdx = nums.size() - 1;
        int lastVal = nums[lastIdx];

        pos[val].erase(idx);

        if (idx != lastIdx) {
            nums[idx] = lastVal;
            pos[lastVal].erase(lastIdx);
            pos[lastVal].insert(idx);
        }

        nums.pop_back();

        if (pos[val].empty())
            pos.erase(val);

        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};