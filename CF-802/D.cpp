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

// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<ll> dp(n, 0); // i means i tk kitna time lga bhrne mai sbko
    ll over = 0;
    for(int i = 0; i < n; ++i) {
        if(i == 0) {
            dp[i] = v[i];
        }
        else {
            ll tot = v[i] - over - dp[i - 1];
            if(tot <= 0) {
                dp[i] = dp[i - 1];
                over = abs(tot);
            }
            else {
                // kitne contri krr re
                // -> (i + 1)
                ll extra = (tot + i) / (i + 1);
                dp[i] = dp[i - 1] + extra;
                over = extra * (i + 1) - tot;
            }
        }
    }
    // n pipe se bhrne ke liye dp[n - 1] time lgega
    debug(dp);
    // 5 ki 5 pipe open hone pr dp[i] time lgega
    vector<ll> ti(n + 1, 0);
    ti[n] = dp[n - 1];
    over = 0;
    vector<ll> pre(n + 1, 0);
    pre[1] = v[0];
    for(int i = 1; i < n; ++i) pre[i + 1] = pre[i] + v[i];
    for(int i = n - 2; i >= 0; --i) {
        // ti[i + 1]
        over = dp[i] * (i + 1) - pre[i + 1];
        over = max(0LL, over);
        ll ahead = pre[n] - pre[i + 1];
        ahead -= over;
        if(ahead <= 0) {
            ti[i + 1] = dp[i];
        }
        else {
            ti[i + 1] = dp[i] + (ahead + i) / (i + 1);
        }
    }
    debug(ti);
    int q; cin >> q;
    while(q--) {
       ll t; cin >> t;
       int s = 1, e = n;
       int ind = -1;
       while(s <= e) {
           int mid = (s + e) / 2;
           if(ti[mid] <= t) {
               ind = mid;
               e = mid - 1;
           }
           else s = mid + 1;
       }
       cout << ind << '\n';
    }
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
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
