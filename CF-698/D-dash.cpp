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

int n, q;
string ss, f, res;
vector<int> t;
vector<bool> vis;
void build(int in = 1, int s = 0, int e = n - 1) {
    if(s == e) {
        vis[in] = true;
        t[in] = f[s] - '0';
    }
    else {
        int mid = (s + e) >> 1;
        build(2 * in, s, mid);
        build(2 * in + 1, mid + 1, e);
    }
}
void push(int in) {
    if(vis[in]) {
        t[2 * in] = t[2 * in + 1] = t[in];
        vis[2 * in] = vis[2 * in + 1] = true;
        vis[in] = false;
    }
}
int q1(int in, int s, int e, int qs, int qe) { // Tells sum
    if(qs > qe) return 0;
    if(s == e || (s == qs && e == qe && vis[in])) {
        return (e - s + 1) * t[in];
    }
    push(in);
    int mid = (s + e) >> 1;
    return q1(2 * in, s, mid, qs, min(qe, mid)) + q1(2 * in + 1, mid + 1, e, max(mid + 1, qs), qe);
}
void update(int in, int s, int e, int qs, int qe, int nval) {
    if(qs > qe) return;
    if(s == qs && e == qe) {
        t[in] = nval;
        vis[in] = true;
    }
    else {
        push(in);
        int mid = (s + e) >> 1;
        update(2 * in, s, mid, qs, min(qe, mid), nval);
        update(2 * in + 1, mid + 1, e, max(qs, mid + 1), qe, nval);
    }
}
void create(int in = 1, int s = 0, int e = n - 1) {
    if(s == e || vis[in]) {
        for(int i = s; i <= e; ++i) res[i] = t[in] + '0';
        return;
    }
    int mid = (s + e) >> 1;
    create(2 * in, s, mid);
    create(2 * in + 1, mid + 1, e);
}
// *-> KISS*
int solve() {
    cin >> n >> q;
    res = string(n, '.');
    cin >> ss >> f;
    vis.assign(4 * n, false);
    t.assign(4 * n, 0);
    build();
    vector<pair<int, int>> v(q);
    for (int i = 0; i < q; i++) {
        cin >> v[i].ff >> v[i].ss;
        --v[i].ff; --v[i].ss;
    }
    for(int i = q - 1; i >= 0; --i) {
        int l = v[i].ff, r = v[i].ss;
        int one = q1(1, 0, n - 1, l, r);
        int zero = (r - l + 1) - one;
        int len = (r - l + 1);
        int maxx = (len - 1) / 2;
        if(min(one, zero) > maxx) {
            cout << "NO";
            return 0;
        }
        if(zero < one) {
            update(1, 0, n - 1, l, r, 1);
        }
        else {
            update(1, 0, n - 1, l, r, 0);
        }
    }
    // ss, f, t
    create();
    if(res == ss) cout << "YES";
    else cout << "NO";
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = true;
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
