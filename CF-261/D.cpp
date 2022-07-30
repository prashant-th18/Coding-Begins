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

int n;
vector<ll> rl;
vector<vector<ll>> t;
void build(int in = 1, int s = 0, int e = n - 1) {
    if(s == e) {
        t[in] = vector<ll>(1, rl[s]);
    }
    else {
        int mid = (s + e) >> 1;
        build(2 * in, s, mid);
        build(2 * in + 1, mid + 1, e);
        merge(all(t[2 * in]), all(t[2 * in + 1]), back_inserter(t[in]));
    }
}
ll query(int in, int s, int e, int qs, int qe, ll val) {
    if(qs > qe) return 0;
    if(s == qs && e == qe) {
        auto it = sz(t[in]) - (upper_bound(all(t[in]), val, greater<int>()) - begin(t[in]));
        return it;
    }
    int mid = (s + e) >> 1;
    return query(2 * in, s, mid, qs, min(mid, qe), val) + query(2 * in + 1, mid + 1, e, max(mid + 1, qs), qe, val);
}
void rev(int in = 1, int s = 0, int e = n - 1) {
    if(s == e) return;
    reverse(all(t[in]));
    int mid = (s + e) >> 1;
    rev(2 * in, s, mid);
    rev(2 * in + 1, mid + 1, e);
}
// *-> KISS*
int solve() {
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    auto f = [&]() -> vector<ll> {
        vector<ll> l(n);
        map<ll, array<ll, 3>> mp;
        for(int i = 0; i < n; ++i) {
            array<ll, 3> pre;
            if(mp.count(v[i]) == false) {
                pre[0] = (i + 1);
                pre[1] = (i + 1);
                pre[2] = i;
            }
            else {
                array<ll, 3> adv = mp[v[i]];
                ll dif = i - adv[2];
                ll su = adv[1] * dif + (i + 1) + adv[0];
                ll dot = adv[1] + (i + 1);
                ll in = i;
                pre[0] = su; pre[1] = dot; pre[2] = in;
            }
            l[i] = pre[0];
            mp[v[i]] = pre;
        }
        return l;
    };
    vector<ll> lr = f();
    reverse(all(v));
    rl = f();
    reverse(all(rl));
    reverse(all(v));
    debug(lr, rl);
    t.assign(4 * n, vector<ll>());
    build();
    rev();
    debug(t);
    ll ans = 0;
    for(int i = 0; i < n - 1; ++i) {
        ans += query(1, 0, n - 1, i + 1, n - 1, lr[i]);
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
