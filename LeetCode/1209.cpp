#define ss second
#define ff first
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> v;
        int n = s.size();
        int c = 0; char pre = s[0];
        for(int i = 0; i <= n; ++i) {
            if(i != n && s[i] == pre) ++c;
            else {
                if(v.size() == 0) v.push_back(pair(pre, c));
                else {
                    if(c % k == 0) {
                        if(i != n) pre = s[i], c = 1;
                        continue;
                    }
                    else {
                        while(v.size() && v.back().ff == pre) {
                            auto t = v.back(); v.pop_back();
                            c += t.ss;
                            c %= k;
                            if(c == 0) break;
                        }
                        if(c != 0) v.push_back(pair(pre, c));
                    }
                }
                if(i != n) pre = s[i]; c = 1;
            }
        }
        string p = "";
        for(int i = 0; i < v.size(); ++i) {
            p += string(v[i].ss % k, v[i].ff);
        }
        return p;
    }
};
