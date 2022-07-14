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

vector<int> bits(int bor) {
    vector<int> bits(31, 0);
    for (int i = 0; i < 31; i++) {
        bits[i] = ((bor >> i) & 1);
    }
    return bits;
}
vector<int> qor(int i, int j) {
    cout << "or " << i << ' ' << j << endl;
    int bor;
    cin >> bor;
    return bits(bor);
}
vector<int> qand(int i, int j) {
    cout << "and " << i << ' ' << j << endl;
    int band; cin >> band;
    return bits(band);
}
// *-> KISS*
int solve() {
    int n, k; cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(31, -1)); // -1 denotes we don't know the bit till now
    auto hor = [&](int in, vector<int>& h) -> void {
        for (int i = 0; i < 31; i++) {
            if(h[i] == 0) v[in][i] = v[in + 1][i] = 0;
        }
    };
    auto hand = [&](int in, vector<int>& h) -> void {
        for (int i = 0; i < 31; i++) {
            if(h[i] == 1) v[in][i] = v[in + 1][i] = 1;
        }
    };
    for(int i = 1; i < n - 1; ++i) {
        // 0 i, i i + 1
        array<vector<int>, 2> f = {qor(1, i + 1), qand(1, i + 1)};
        decltype(f) s = {qor(i + 1, i + 2), qand(i + 1, i + 2)};
        debug(f[0], f[1]);
        debug(s[0], s[1]);
        hor(i - 1, f[0]); hand(i - 1, f[1]);
        hor(i, s[0]); hand(i, s[1]);
        for(int j = 0; j < 31; ++j) {
            if(v[i - 1][j] == -1) {
                if(s[0][j] == 0) {
                    v[i - 1][j] = 1;
                }
                else if(s[1][j] == 1) {
                    v[i - 1][j] = 0;
                }
                else {
                    v[i - 1][j] = 1;
                    v[i][j] = 0;
                    v[i + 1][j] = 1;
                }
            }
            else {
                
            }
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < 31; ++j) {
            assert(v[i][j] != -1);
            if(v[i][j] == 1) ans[i] += (1 << j);
        }
    }
    debug(ans);
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
