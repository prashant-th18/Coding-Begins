#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
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
vector<int> v;
vector<set<int>> t;
void build(int in = 1, int s = 0, int e = n - 1) {
    if(s == e) {
        t[in].insert(v[s]);;
    }
    else {
        int mid = (s + e) / 2;
        build(2 * in, s, mid);
        build(2 * in + 1, mid + 1, e);
        for(auto val : t[2 * in]) {
            t[in].insert(val);
        }
        for(auto val : t[2 * in + 1]) {
            if(t[in].count(val)) t[in].erase(val);
            else t[in].insert(val);
        }
    }
}
void update(int in, int s, int e, int pos, int nval) {
    if(s == e) {
        t[in].erase(v[s]);
        v[s] = nval;
        t[in].insert(v[s]);
    }
    else {
        int mid = (s + e) / 2;
        if(pos <= mid) update(2 * in, s, mid, pos, nval);
        else update(2 * in + 1, mid + 1, e, pos, nval);
        t[in].clear();
        for(auto val : t[2 * in]) t[in].insert(val);
        for(auto val : t[2 * in + 1]) {
            if(t[in].count(val)) t[in].erase(val);
            else t[in].insert(val);
        }
    }
}
set<int> query(int in, int s, int e, int qs, int qe) {
    if(qs > qe) {
        return {};
    }
    else if(s == qs && e == qe) {
        return t[in];
    }
    else {
        int mid = (s + e) / 2;
        auto st1 = query(2 * in, s, mid, qs, min(mid, qe));
        auto st2 = query(2 * in + 1, mid + 1, e, max(qs, mid + 1), qe);
        set<int> st;
        for(auto val : st1) st.insert(val);
        for(auto val : st2) {
            if(st.count(val)) st.erase(val);
            else st.insert(val);
        }
        return st;
    }
}
// *-> KISS*
int solve() {
    cin >> n;
    v.assign(n, 0);
    t.assign(4 * n, {});
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    build();
    int q; cin >> q;
    while(q--) {
        int tt; cin >> tt;
        if(tt == 1) {
            int i, val; cin >> i >> val;
            update(1, 0, n - 1, i - 1, val);
        }
        else {
            int l, r; cin >> l >> r;
            --l, --r;
            auto mp = query(1, 0, n - 1, l, r);
            if(sz(mp) <= 1) cout << "YES";
            else cout << "NO";
            cout << '\n';
        }
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
