class RangeModule {
public:
    map<int, int> mp;

    RangeModule() {
    }

    void addRange(int left, int right) {
        auto it = mp.lower_bound(left);

        if (it != mp.begin()) {
            auto prev = std::prev(it);

            if (prev->second >= left) {
                left = min(left, prev->first);
                right = max(right, prev->second);
                it = mp.erase(prev);
            }
        }

        while (it != mp.end() && it->first <= right) {
            right = max(right, it->second);
            it = mp.erase(it);
        }

        mp[left] = right;
    }

    bool queryRange(int left, int right) {
        auto it = mp.upper_bound(left);

        if (it == mp.begin())
            return false;

        --it;

        return it->second >= right;
    }

    void removeRange(int left, int right) {
        auto it = mp.lower_bound(left);

        if (it != mp.begin()) {
            auto prev = std::prev(it);

            if (prev->second > left) {
                int oldEnd = prev->second;

                if (oldEnd > right) {
                    prev->second = left;
                    mp[right] = oldEnd;
                    return;
                }

                prev->second = left;
            }
        }

        while (it != mp.end() && it->first < right) {
            int oldEnd = it->second;

            if (oldEnd > right) {
                mp.erase(it);
                mp[right] = oldEnd;
                return;
            }

            it = mp.erase(it);
        }
    }
};