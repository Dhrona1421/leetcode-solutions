class LFUCache {
    int capacity, minFreq;
    unordered_map<int, pair<int, int>> keyInfo;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> pos;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void updateFreq(int key) {
        int freq = keyInfo[key].second;

        freqList[freq].erase(pos[key]);

        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq)
                minFreq++;
        }

        keyInfo[key].second++;
        freqList[freq + 1].push_front(key);
        pos[key] = freqList[freq + 1].begin();
    }

    int get(int key) {
        if (!keyInfo.count(key))
            return -1;

        int value = keyInfo[key].first;
        updateFreq(key);
        return value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (keyInfo.count(key)) {
            keyInfo[key].first = value;
            updateFreq(key);
            return;
        }

        if (keyInfo.size() == capacity) {
            int keyToRemove = freqList[minFreq].back();
            freqList[minFreq].pop_back();

            if (freqList[minFreq].empty())
                freqList.erase(minFreq);

            keyInfo.erase(keyToRemove);
            pos.erase(keyToRemove);
        }

        keyInfo[key] = {value, 1};
        freqList[1].push_front(key);
        pos[key] = freqList[1].begin();
        minFreq = 1;
    }
};
