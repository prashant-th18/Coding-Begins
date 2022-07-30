#include"bits/stdc++.h"
using namespace std;
using ll = long long;
#define ss second
int n;
vector<int> v, bit, h;
void update(int in, ll delta = 1) {
    for(; in <= n; in += (in & -in)) {
        bit[in] += delta;
    }
}
ll sum(int r) {
    ll s = 0;
    for(; r > 0; r -= (r & -r)) {
        s += bit[r];
    }
    return s;
}
int main() {
    int t_; cin >> t_;
    while(t_--) {
        cin >> n;
        v.assign(n, 0);
        bit.assign(n + 1, 0);
        for(int i = 0; i < n; ++i) cin >> v[i];
        // Since all values are distinct, hash them into integers from "1" to "n"
        {
            map<int, int> mp;
            for (int i = 0; i < n; i++) {
                mp[v[i]];
            }
            int ctr = 1;
            for(auto& val : mp) {
                val.ss = ctr++;
            }
            for (int i = 0; i < n; i++) {
                v[i] = mp[v[i]];
            }
        }
        // BIT Array, vo order wise, frequency ko store krte jaata hai
        ll ans = 0;
        for(int i = 0; i < n; ++i) {
            update(v[i], 1);
            ans += (sum(n) - sum(v[i]));
        }
        cout << ans << '\n';
    }
    return 0;
}
