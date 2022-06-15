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
    ll n, k; cin >> n >> k;
    if(k > n) cout << -1;
    else if(k == 1) cout << n;
    else {
        ll ans = -1;
        auto getAns = [&](ll pass, ll& s, ll &e, ll mid) {
            // k * d * k <= (ll) 1e18
            if(k > (ll)1e18 / k / pass) {
                e = mid - 1; return; // Overflow
            }
            ll first = pass, d = pass;
            ll slsum = (k - 1) * (2 * first + (k - 2) * d) / 2;
            ll slast = first + (k - 2) * d;
            ll last = n - slsum;
            if(last > 0 && last > slast && __gcd(last, first) == first) {
                ans = pass;
                s = mid + 1;
            }
            else e = mid - 1;
        };
        vector<ll> factor;
        for(ll i = 1; i * i <= n; ++i) {
            if(n % i == 0) {
                factor.push_back(i);
                if(i != n / i) factor.push_back(n / i);
            }
        }
        sort(factor.begin(), factor.end());
        ll s = 0, e = sz(factor) - 1;
        while(s <= e) {
            ll mid = (s + e) >> 1;
            ll pass = factor[mid];
            getAns(pass, s, e, mid);
        }
        if(ans == -1) cout << -1;
        else {
            for(ll i = 1; i < k; ++i) {
                cout << i * ans << ' ';
            }
            cout << n - (ans * (k * (k - 1) / 2));
        }
    }
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
