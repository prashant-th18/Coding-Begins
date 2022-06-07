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

const int N = 1e5 + 10;
vector<ll> dp;
ll binexp(ll base, ll power) {
    ll res = 1;
    base %= MOD;
    while(power) {
        if(power & 1) res = res * base % MOD;
        power >>= 1;
        base *= base; base %= MOD;
    }
    return res;
}
ll inv(ll num) {
    return binexp(num, MOD - 2);
}
ll mul(ll a, ll b) {
    return a * b % MOD;
}
ll sub(ll a, ll b) {
    return (a - b + MOD) % MOD;
}
ll add(ll a, ll b) {
    return (a + b) % MOD;
}
ll cal(ll a, ll n, ll r) {
    //a * (r^n - 1) / (r - 1)
    ll pr = r;
    a = binexp(10, a);
    r = binexp(10, r);
    return mul(mul(sub(binexp(r, n), 1), a), dp[pr]);
}
// *-> KISS*
int solve() {
    string s; cin >> s;
    ll n = sz(s);
    ll g1 = n - 1, g2 = 2 * n - 1;
    ll ans = 0;
    if(n == 1) {
        cout << s; return 0;
    }
    // 2 -> 0, 5, 7
    // 1 -> 1, 3, 8
    // 3 -> 2, 4, 6
    for(int i = n - 2; i >= 0; --i) {
        ll n1 = n - 1 - i;
        ll n2 = i + 1;
        ll s1 = n - 2 - i;
        ll s2 = s1 + g1 * (n1 - 1) + g2;
        ll f = cal(s1, n1, g1);
        ll ss = cal(s2, n2, g1);
        f = add(f, ss);
        f = mul(f, (s[i] - '0'));
        ans = add(ans, f);
        // GP
        // [s1, ...n1]
        // [s2, ...n2]
    }
    ans = add(ans, mul(s[n - 1] - '0', cal(g1, n, g1)));
    cout << ans;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    cin >> TET;
    dp.assign(N, 1);
    ll ten = 1;
    for(int i = 0; i < N; ++i) {
        dp[i] = inv(sub(ten, 1));
        ten *= 10; ten %= MOD;
    }
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
