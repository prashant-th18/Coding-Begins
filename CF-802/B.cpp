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
    string s; cin >> s;
    string res = string(n + 1, '.');
    int j = n;
    auto check = [&]() {
        for(int i = 1; i < n; ++i) {
            if(s[i] != '0') return true;
        }
        return false;
    };
    int carry = 0;
    if(s[0] == '9' && (check() || s[n - 1] >= '3')) {
            for(int i = n - 1; i >= 0; --i) {
                if(i == n - 1 || i == n - 2 || i == 0) {
                    // Make 1
                    int num = s[i] - '0';
                    num += carry;
                    if(num <= 1) {
                        res[j--] = (1 - num) + '0';
                        carry = 0;
                    }
                    else {
                        res[j--] = (11 - num) + '0';
                        carry = 1;
                    }
                }
                else {
                    int num = s[i] - '0';
                    num += carry;
                    if(num == 0) {
                        res[j--] = '0'; carry = 0;
                    }
                    else {
                        res[j--] = (10 - num) + '0';
                        carry = 1;
                    }
                }
            }
            cout << res.substr(1);
            return 0;
    }
    for(int i = n - 1; i >= 0; --i) {
        int num = s[i] - '0';
        num += carry;
        if(i == n - 1) {
            // 1 bnana hai
            if(num <= 1) {
                carry = 0;
                res[j--] = (1 - num) + '0';
            }
            else {
                res[j--] = (11 - num) + '0';
                carry = 1;
            }
        }
        else {
            // 0 bnana hai
            if(num == 0) {
                res[j--] = '0';
                carry = 0;
            }
            else {
                res[j--] = (10 - num) + '0';
                carry = 1;
            }
        }
    }
    for(int i = 0; i < n + 1; ++i) {
        if('1' <= res[i] && res[i] <= '9') {
            cout << res.substr(i);
            return 0;
        }
    }
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    if(TET) cin >> TET;
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
