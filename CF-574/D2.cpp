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
const int MOD = 998244353;
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
    vector<vector<int>> t(11);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        t[sz(to_string(v[i]))].push_back(v[i]);
    }
    vector<vector<int>> temp(11);
    for(int i = 1; i < 11; ++i) {
        if(sz(t[i]) == 0) continue;
        vector<int> val;
        for(int j = 0; j < i; ++j) {
            int sum = 0;
            for(int k = 0; k < sz(t[i]); ++k) {
                sum += t[i][k] % 10;
                t[i][k] /= 10;
            }
            val.push_back(sum);
        }
        temp[i] = val;
    }
    ll sum = 0;

    auto add = [&](ll a, ll b) {
        return (a + b) % MOD;
    };
    auto mul = [&](ll a, ll b) {
        return a * b % MOD;
    };
    for(int i = 0; i < n; ++i) {
        for(int j = 1; j <= 10; ++j) {
            if(sz(t[j]) == 0) continue;
            string s = to_string(v[i]);
            reverse(all(s));
            ll res = 1;
            for(int c1 = 0, c2 = 0; c1 < sz(s) || c2 < j;) {
                if(c1 < sz(s)) {
                    int num = s[c1] - '0';
                    sum = add(sum, num * sz(t[j]) * res % MOD);
                    ++c1;
                    res = mul(res, 10);
                }
                if(c2 < j) {
                    sum = add(sum, mul(temp[j][c2], res));
                    ++c2;
                    res = mul(res, 10);
                }
                debug(sum);
            }
        }
    }
    cout << sum;
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
