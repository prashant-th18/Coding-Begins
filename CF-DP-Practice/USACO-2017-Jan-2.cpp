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

// *-> KISS*
int solve() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n, k; cin >> n >> k;
    vector<char> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // index, switch, state
    // H -> 0, P -> 1, S -> 2
    map<char, int> mp;
    mp['H'] = 0; mp['P'] = 1; mp['S'] = 2;
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(k + 1, vector<ll>(3, 0)));
    dp[0][0][mp[v[0]]] = 1;
    for(int i = 1; i < n; ++i)
    {
        for(int sw = 0; sw <= min(i + 1, k); ++sw)
        {
            for(int st = 0; st < 3; ++st)
            {
                if(sw == 0)
                {
                    dp[i][sw][st] = max(dp[i][sw][st], (mp[v[i]] == st) + dp[i - 1][sw][st]);
                }
                else
                {
                    // either `i - 1` and `i` is the latest switch
                    // or not!
                    for(int pre = 0; pre < 3; ++pre)
                    {
                       if(st == pre)
                        {
                            // Second Case
                            dp[i][sw][st] = max(dp[i][sw][st], (mp[v[i]] == st) + (dp[i - 1][sw][pre]));
                        }
                        else
                        {
                            // First Case
                            dp[i][sw][st] = max(dp[i][sw][st], (mp[v[i]] == st) + dp[i - 1][sw - 1][pre]);
                        }
                    }
                }
            }
        }
    }
    // debug(dp);
    ll maxx = -1;
    for(int st = 0; st < 3; ++st)
    {
        maxx = max(maxx, dp[n - 1][k][st]);
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
