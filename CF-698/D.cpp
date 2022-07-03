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

// *-> KISS*
int solve() {
    // READ SEGMENT TREE !!!!
    int n, q; cin >> n >> q;
    string s, f; cin >> s >> f;
    vector<pair<int, int>> v(q);
    for (int i = 0; i < q; i++) {
        cin >> v[i].ff >> v[i].ss;
        --v[i].ff; --v[i].ss;
    }
    ordered_set z, o;
    for (int i = 0; i < n; i++) {
        if(f[i] == '0') z.insert(i);
        else o.insert(i);
    }
    for(int i = q - 1; i >= 0; --i) {
        int l = v[i].ff, r = v[i].ss;
        int maxi = (r - l + 2) / 2; --maxi;
        int zz = z.order_of_key(r + 1) - z.order_of_key(l);
        int oo = o.order_of_key(r + 1) - o.order_of_key(l);
        int mini = min(zz, oo);
        if(mini > maxi) {
            cout << "NO"; return 0;
        }
        int val = l;
        if(zz < oo) {
            auto it = z.lower_bound(val);
            while(it != z.end() && (*it) <= r) {
                o.insert(*it);
                z.erase(it);
                it = z.lower_bound(val);
            }
        }
        else {
            auto it = o.lower_bound(val);
            while(it != o.end() && (*it) <= r) {
                z.insert(*it);
                o.erase(it);
                it = o.lower_bound(val);
            }
        }
    }
    for(auto val : z) f[val] = '0';
    for(auto val : o) f[val] = '1';
    if(f == s) cout << "YES";
    else cout << "NO";
    z.clear();
    o.clear();
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
