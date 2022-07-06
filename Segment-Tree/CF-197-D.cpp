#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include "bits/stdc++.h"
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */

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
vector<int> v, t;
void build(int in = 1, int s = 0, int e = n - 1) {
    if(s == e) {
        t[in] = v[s];
    }
    else {
        int mid = (s + e) / 2;
        build(2 * in, s, mid);
        build(2 * in + 1, mid + 1, e);
        int val = log2(e - s + 1);
        if(val & 1) {
            t[in] = t[2 * in] | t[2 * in + 1];
        }
        else {
            t[in] = t[2 * in] ^ t[2 * in + 1];
        }
    }
}
void update(int in, int s, int e, int pos, int nval) {
    if(s == e) {
        t[in] = nval;
        v[s] = nval;
    }
    else {
        int mid = (s + e) / 2;
        if(pos <= mid) update(2 * in, s, mid, pos, nval);
        else update(2 * in + 1, mid + 1, e, pos, nval);
        int val = log2(e - s + 1);
        if(val & 1) {
            t[in] = t[2 * in] | t[2 * in + 1];
        }
        else {
            t[in] = t[2 * in] ^ t[2 * in + 1];
        }
    }
}
// *-> KISS*
int solve() {
    cin >> n;
    n = (1 << n);
    int m; cin >> m;
    v.assign(n, 0);
    t.assign(4 * n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    build();
    while(m--) {
        int i, j; cin >> i >> j;
        update(1, 0, n - 1, i - 1, j);
        cout << t[1] << '\n';
    }
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
        if (solve())
        {
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
