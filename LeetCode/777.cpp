class Solution {
    public:
        bool canTransform(string a, string b) {
            deque<int> l, r, x;
            for(int i = 0; i < b.size(); ++i) {
                if(b[i] == 'L') l.push_back(i);
                else if(b[i] == 'R') r.push_back(i);
                else x.push_back(i);
            }
            auto del = [&](int j) -> void {
                if(b[j] == 'L') l.pop_front();
                else if(b[j] == 'R') r.pop_front();
                else x.pop_front();
            };
            int i = 0, j = 0, n = a.size();
            while(i < n && j < n) {
                if(a[i] == b[j]) {
                    del(j);
                    ++i, ++j;
                }
                else {
                    if(a[i] == 'L') {
                        return false;
                    }
                    else if(a[i] == 'R') {
                        if(b[i] != 'X') return false;
                        int t1 = i, t2 = i;
                        // a[i] -> 'R'
                        // b[i] -> 'X'
                        while(t1 < n && a[t1] != 'X') ++t1;
                        while(t2 < n && b[t2] != 'R') ++t2;
                        if(t1 == i || t2 == i || t1 == n || t2 == n) return false;
                        int t = max(t1, t2);
                        ++i;
                        while(i <= t && a[i] == 'X') ++i;
                        while(j < t && b[j] == 'X') ++j;
                        if(i != t + 1 && j != t) return false;
                        j = i;
                    }
                    else {
                        if(b[i] != 'L') return false;
                        int t1 = i, t2 = i;
                        // a[i] -> 'X'
                        while(t1 < n && a[t1] != 'L') ++t1;
                        while(t2 < n && b[t2] != 'X') ++t2;
                        if(t1 == i || t2 == i || t1 == n || t2 == n) return false;
                        int t = max(t1, t2);
                        ++i;
                        while(i <= t && a[i] == 'X') ++i;
                        while(j < t && b[j] == 'L') ++j;

                        while(t1 < n && a[t1] != 
                    }
                }
            }
            return i == n && j == n;
        }
};
