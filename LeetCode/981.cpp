class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int t) {
        vector<pair<int, string>>& v = mp[key];
        string s = "";
        int ind = upper_bound(begin(v), end(v), make_pair(t + 1, s)) - begin(v);
        --ind;
        if(ind < 0) return "";
        return v[ind].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
