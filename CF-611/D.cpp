#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second
using a4 = array<ll, 4>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct comp {
    bool operator()(const a4& a, const a4&b) const {
        if(a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
    }
};
// *-> KISS*
int solve() {
    ll n, m; cin >> n >> m;
    vector<ll> v(n);
    vector<ll> ans;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    set<a4, comp> st;
    auto get = [&](ll d) {
        int in1 = upper_bound(all(v), d) - begin(v);
        int in2 = in1 - 1;
        return min(v[in1] - d, d - v[in2]);
    };
    auto doIt = [&](ll a, ll b) {
        ll d1 = (a + b) >> 1;
        ll dis1 = get(d1);
        ll d2 = (a + b + 1) >> 1;
        ll dis2 = get(d2);
        if(dis1 < dis2) {
            st.insert({dis1, d1, a, b});
        }
        else st.insert({dis2, d2, a, b});
    };
    for(int i = 1; i < n; ++i) {
        ll a = v[i - 1], b = v[i];
        if(a + 1 == b) continue;
        ++a; --b;
        doIt(a, b);
    }
    ll sum = 0;
    ll x = v[0] - 1, y = v[n - 1] + 1;
    while(m--) {
        ll d1 = v[0] - x, d2 = y - v[n - 1];
        if(sz(st) == 0 || (*st.begin())[0] >= min(d1, d2)) {
            if(d1 < d2) {
                sum += d1;
                ans.push_back(x);
                --x;
            }
            else {
                sum += d2;
                ans.push_back(y);
                ++y;
            }
        }
        else {
            a4 temp = *st.begin(); st.erase(st.begin());
            sum += temp[0];
            ans.push_back(temp[1]);
            ll a = temp[2], b = temp[3];
            ll c = temp[1] - 1, d = temp[1] + 1;
            if(a <= c) doIt(a, c);
            if(d <= b) doIt(d, b);
        }
    }
    cout << sum << '\n';
    for(auto val : ans) cout << val << ' ';
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = false;
    int TET = 1;
    if(test) cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
#ifdef LOCAL
        cout << "##################" << '\n';
#endif

        if (solve()) {
            break;
        }
        cout << '\n';
    }
#ifdef LOCAL
    cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}
// -> Keep It Simple Stupid!
