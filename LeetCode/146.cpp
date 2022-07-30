#define sz(x) ((int)x.size())
class LRUCache {
public:
    unordered_map<int, int> mp;
    int c;
    LRUCache(int capacity) {
        c = capacity;
    }
    
    int get(int key) {
        if(mp.count(key)) return mp[key];
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)) {
            mp.erase(key);
            mp[key] = value;
            return;
        }
        if(sz(mp) == c) {
            mp.erase(mp.begin());
            mp[key] = value;
            return;
        }
        mp[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
