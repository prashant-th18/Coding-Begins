using ll = long long;
using pll = pair<ll, ll>;
#define ff first
#define ss second
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& m, int f1) {
        vector<vector<pll>> v;
        v.assign(n + 1, vector<pll>());
        for (int i = 0; i < m.size(); i++) {
            v[m[i][0]].push_back(pair(m[i][1], m[i][2]));
            v[m[i][1]].push_back(pair(m[i][0], m[i][2]));
        }
        v[0].push_back(pair(f1, 0));
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push(pair(0, 0));
        vector<ll> ti(n + 1, INT_MAX);
        while(!pq.empty()) {
            pll f = pq.top(); pq.pop();
            if(ti[f.ff] < f.ss) continue;
            ti[f.ff] = f.ss;
            for(const auto& [x, y] : v[f.ff]) {
                if(y >= ti[f.ff]) {
                    if(ti[x] > y) {
                        ti[x] = y;
                        pq.push(pair(x, y));
                    }
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; ++i) if(ti[i] != INT_MAX) ans.push_back(i);
        return ans;
    }
};
