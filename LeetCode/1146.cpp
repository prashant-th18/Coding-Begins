#include<bits/stdc++.h>
class SnapshotArray {
public:
    vector<std::set<pair<int, int>>> v;
    int s;
    SnapshotArray(int length) {
        std::set<pair<int, int>> temp = {{0, 0}};
        v.assign(length, temp);
        s = 0;
    }
    
    int get(int index, int snap_id) {
        pair<int, int> t = {snap_id, 0};
        auto it = v[index].lower_bound(t);
        if(it == v[index].end() || (*it).first > index) --it;
        return (*it).second;
    }
    
    int snap() {
        int t = s;
        s++;
        return t;
    }
    
    void set(int index, int value) {
        if((*(v[index].rbegin())).first == s) {
            v[index].erase(*(v[index].rbegin()));
        }
        pair<int, int> t = {s, value};
        v[index].insert(t);
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
