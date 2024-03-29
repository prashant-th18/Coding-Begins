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
using pll = pair<ll, ll>;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
    void debug_print(string s) {
        cerr << "\"" << s << "\"";
    }

    void debug_print(const char* s) {
        debug_print((string)s);
    }

    void debug_print(bool val) {
        cerr << (val ? "true" : "false");
    }

    void debug_print(int val) {
        cerr << val;
    }

    void debug_print(ll val) {
        cerr << val;
    }

    void debug_print(double val) {
        cerr << val;
    }

    template<typename F, typename S>
    void debug_print(pair<F, S> val) {
        cerr << "(";
        debug_print(val.first);
        cerr << ", ";
        debug_print(val.second);
        cerr << ")";
    }

    void debug_print(vector<bool> val) {
        cerr << "{";
        bool first = true;
        for (bool x : val) {
            if (!first) {
                cerr << ", ";
            } else {
                first = false;
            }
            debug_print(x);
        }
        cerr << "}";
    }

    template<typename T>
    void debug_print(T val) {
        cerr << "{";
        bool first = true;
        for (const auto &x : val) {
            if (!first) {
                cerr << ", ";
            } else {
                first = false;
            }
            debug_print(x);
        }
        cerr << "}";
    }

    void debug_print_collection() {
        cerr << endl;
    }

    template<typename First, typename... Args>
    void debug_print_collection(First val, Args... args) {
        cerr << " ";
        debug_print(val);
        debug_print_collection(args...);
    }

#define debug(...) cerr << "@@@ " << #__VA_ARGS__ << " ="; debug_print_collection(__VA_ARGS__);

#else
    #define debug(...) 
#endif

// *-> KISS*
int solve() {
    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);
    int n; cin >> n;
    vector<pll> h(n);
    vector<ll> bit1(n + 1), bit2(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> h[i].ff; h[i].ss = i;
    }
    sort(h.begin(), h.end());
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        v[h[i].ss] = i + 1;
    }
    vector<ll> left(n), right(n);
    auto upd = [&](int in, ll delta, vector<ll>& bit) {
        for(; in <= n; in += in & -in) bit[in] += delta;
    };
    auto query = [&](int in, vector<ll>& bit) {
        ll s = 0;
        for(; in > 0; in -= in & -in) s += bit[in];
        return s;
    };
    for(int i = n - 1; i >= 0; --i) {
        right[i] = query(n, bit1) - query((int)v[i], bit1);
        upd(v[i], 1, bit1);
    }
    for(int i = 0; i < n; ++i) {
        left[i] = query(n, bit2) - query(v[i], bit2);
        upd(v[i], 1, bit2);
    }
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        ll sm = min(left[i], right[i]);
        ll ma = max(left[i], right[i]);
        if(ma > sm * 2) {
            ++ans;
        }
    }
    cout << ans;
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
