#include"bits/stdc++.h"
using namespace std;
using ll = long long;
int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<ll> bit1(n + 1, 0), bit2(n + 1, 0);
    auto sum1 = [&](int i) -> ll {
        ll res = 0;
        for(; i > 0; i -= (i & -i)) {
            res += bit1[i];
        }
        return res;
    };

    auto sum2 = [&](int i) -> ll {
        ll res = 0;
        for(; i > 0; i -= (i & -i)) {
            res += bit2[i];
        }
        return res;
    };

    auto upd1 = [&](int in, ll delta) -> void {
        for(; in <= n; in += (in & -in)) {
            bit1[in] += delta;
        }
    };

    auto upd2 = [&](int in, ll delta) -> void {
        for(; in <= n; in += (in & -in)) {
            bit2[in] += delta;
        }
    };

    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        ll t = sum1(n) - sum1(v[i]);
        ans += sum2(n) - sum2(v[i]);
        upd1(v[i], 1);
        upd2(v[i], t);
    }
    cout << ans;
    return 0;
}
