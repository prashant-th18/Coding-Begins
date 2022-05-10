#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include <bits/stdc++.h>
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

const int N = 2500;
// *-> KISS*
int solve() {
    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    vector<array<int, 2>> powers(n, {0, 0});
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        int c = 0;
        while(v[i] % 5 == 0) ++c, v[i] /= 5;
        powers[i][1] = c;
        c = 0;
        while(v[i] % 2 == 0) ++c, v[i] /= 2;
        powers[i][0] = c;
    }
    debug(powers);
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(k + 1, vector<int>(N, -1)));
    for(int j = 0; j <= k; ++j) {
        dp[0][j][0] = 0;
    }
    for(int i = 1; i <= n; ++i) {
        // Till index i
        for(int j = 0; j <= k; ++j) {
            // I have chosen "j" items
            if(j == 0) {
                dp[i % 2][j][0] = 0;
                continue;
            }
            else {
                // Either choose this number or don't choose it
                for(int p = 0; p < N; ++p) {
                    ll op1 = dp[(i - 1) % 2][j][p];
                    ll op2 = -1;
                    if(p >= powers[i - 1][1]) {
                        if(dp[(i - 1) % 2][j - 1][p - powers[i - 1][1]] == -1) op2 = -1;
                        else
                        op2 = dp[(i - 1) % 2][j - 1][p - powers[i - 1][1]] + powers[i - 1][0];
                    }
                    dp[i % 2][j][p] = max(op1, op2);
                }
            }
        }
    }
    int maxx = 0;
    for(int p = 0; p < N; ++p) {
        maxx = max(maxx, min(p, dp[n % 2][k][p]));
    }
    cout << maxx;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    //cin >> TET;
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
