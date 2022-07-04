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
const long long MOD = 1000000007;
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

const int N = 2e5;
vector<ll> fact(N, 0);
template<typename T>
T binexp(T a, T b) {
    T ans = 1;
    while (b) {
        if (b & 1) {
            ans = 1LL * ans * a % MOD;
        }
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return ans;
}
ll inv(ll n) {
    return binexp(n, MOD - 2);
}
ll ncr(ll n, ll r) {
    if(r > n || r < 0) return 0;
    else {
        return fact[n] * inv(fact[n - r]) % MOD * inv(fact[r]) % MOD;
    }
}
ll add(ll a, ll b) {
    return (a + b) % MOD;
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<int> v(n);
    unordered_map<int, int> occ;
    for(int i = 0; i < n; ++i) cin >> v[i], ++occ[v[i]];
    unordered_map<int, int> mp;
    for(int i = 0; i < n; ++i) {
        int temp = v[i];
        for(int j = 1; j * j <= temp; ++j) {
            if(temp % j == 0) {
                ++mp[j];
                if(j != temp / j) ++mp[temp / j];
            }
        }
    }
    ll ans = 0;
    for(const auto& [x, y] : mp) {
        if(x == 1) continue;
        // x -> length
        // y -> occ
        ans = add(ans, ncr(y, x));
    }
    for(const auto& [x, y] : occ) {
        // x -> number
        // y -> occ
        for(int i = 2; i <= y; ++i) {
            if(i == x || x % i == 0) continue;
            else {
                ans = add(ans, ncr(y, i));
            }
        }
    }
    cout << ans;
    return 0;
}
void init() {
    // nCr
    fact[0] = fact[1] = 1;
    for(ll i = 2; i < sz(fact); ++i) {
        fact[i] = i * fact[i - 1] % MOD;
    }
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = true;
    int TET = 1;
    if(test) cin >> TET;
    cout << fixed << setprecision(6);
    init();
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

