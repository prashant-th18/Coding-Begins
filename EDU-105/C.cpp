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
    int n, m; cin >> n >> m;
    vector<ll> na, pa, nb, pb;
    for(int i = 0; i < n; ++i) {
        ll t; cin >> t;
        if(t < 0) na.push_back(t);
        else pa.push_back(t);
    }
    for(int i = 0; i < m; ++i) {
        ll t; cin >> t;
        if(t < 0) nb.push_back(t);
        else pb.push_back(t);
    }
    auto ans = [&](vector<ll>& a, vector<ll>& b) -> ll {
        debug(a); debug(b);
        vector<ll> dp(sz(b) + 1, 0);
        for(int i = sz(b) - 1; i >= 0; --i) {
            int ind = 0;
            if(b[i] < 0) ind = lower_bound(all(a), b[i]) - begin(a);
            else ind = lower_bound(all(a), b[i], greater<int>()) - begin(a);

            if(ind == sz(a)) dp[i] = dp[i + 1];
            else {
                if(a[ind] == b[i]) {
                    dp[i] = 1 + dp[i + 1];
                }
                else {
                    int left = sz(a) - 1 - ind;
                    int ch = 0;
                    if(b[i] < 0) ch = b[i] + left;
                    else ch = b[i] - left;
                    int ind2 = 0;
                    if(b[i] < 0) ind2 = upper_bound(all(b), ch) - begin(b);
                    else ind2 = upper_bound(all(b), ch, greater<int>()) - begin(b);
                    ll ex = ind2 - (i + 1);
                    dp[i] = max(dp[i + 1], 1 + ex);
                }
            }
            debug(b[i], dp[i], ind);
        }
        return dp[0];
    };
    sort(pa.begin(), pa.end(), greater<>());
    sort(pb.begin(), pb.end(), greater<>());
    ll a = ans(na, nb);
    ll b = ans(pa, pb);
    cout << (a + b);
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = true;
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
