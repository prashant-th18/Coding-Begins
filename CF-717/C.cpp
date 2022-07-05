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
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    if(sum & 1) cout << 0;
    else {
        int temp = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(temp + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= temp; ++j) {
                if(j == 0) dp[i][j] = true;
                else {
                    bool op1 = dp[i - 1][j];
                    bool op2 = ((v[i - 1] <= j) ? (dp[i - 1][j - v[i - 1]]) : (false));
                    dp[i][j] = (op1 || op2);
                }
            }
        }
        if(dp[n][temp] == false) cout << 0;
        else {
            // sum is even
                for(int i = 0; i < n; ++i) {
                    if(v[i] % 2 == 1) {
                        cout << 1 << '\n' << i + 1;
                        return 0;
                    }
                }
                for(int i = 0; i < n; ++i) {
                    vector<int> tt(n - 1);
                    int last = sum;
                    for(int j = 0, c = 0; j < n; ++j) {
                        if(i != j) tt[c++] = v[j];
                        else last -= v[j];
                    }
                    last /= 2;
                    dp.assign(n, vector<bool>(last + 1, false));
                    dp[0][0] = true;
                    for(int j = 1; j < n; ++j) {
                        for (int k = 0; k <= last; k++) {
                            if(k == 0) dp[j][k] = true;
                            else {
                                bool op1 = dp[j - 1][k];
                                bool op2 = ((k >= tt[j - 1]) ? (dp[j - 1][k - tt[j - 1]]) : (false));
                                dp[j][k] = (op1 || op2);
                            }
                        }
                    }
                    if(dp[n - 1][last] == false) {
                        cout << 1 << '\n' << i + 1; return 0;
                    }
                }
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
