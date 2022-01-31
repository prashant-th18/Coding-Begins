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
#define MOD 1000000007
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second
#ifdef LOCAL
#define debug(x) cout << '\n' << "----------------" << '\n' << #x << " : "; _print(x); cout << '\n' << "-------------" << '\n';
#else
#define debug(x)
#endif

inline ll nxt() { ll x; scanf("%lld", &x); return x; }

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */
template <typename T> void _print(vector <T> v) { cout << "[ "; for (auto myval : v) cout << myval << " "; cout << "]"; }
template <typename T1, typename T2> void _print(vector <T1, T2> v) { cout << "[ "; for (auto myval : v) cout << myval.ff << ' ' << myval.ss << " "; cout << "]"; }
template <typename T> void _print(set <T> v) { cout << "[ "; for (auto myval : v) cout << myval << " "; cout << "]"; }
template <typename T1, typename T2> void _print(map<T1, T2> v) { cout << "[ "; for (auto myval : v) cout << myval.ff << ' ' << myval.ss << " "; cout << "]"; }
void _print(int a) {cout << a;}
void _print(ll a) {cout << a;}
void _print(char a) {cout << a;}
void _print(string a) {cout << a;}
void _print(double a) {cout << a;}
// *-> KISS*
int solve() {
    // 
    // 1 10 1 5 2
    // so aapko last se store krte hue aana hai
    // jese ki
    // dp lg rhi hai
    //  +1 -10 +1 -5 +2
    //  -1 +10 -1 +5 -2
    int n; cin >> n;
    vector<ll> v(n);
    for (ll &val : v) {
        cin >> val;
    }
    // upar vaala -> + - + - + {0th index}
    // niche vaala -> - + - + -
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    for (int i = 0; i < n; i++) {
        //
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][1];
            if(i % 2 == 0)
            {
                dp[i + 1][0] += (1 * v[i]);
                dp[i + 1][1] += (-1 * v[i]);
            }
            else
            {
                dp[i + 1][0] += (-1 * v[i]);
                dp[i + 1][1] += (1 * v[i]);
            }
        //
    }
    ll sum = 0;
    ll ans = dp[n][0];
    for(int i = 0; i < n; ++i)
    {
        ll temp = dp[n][1] - dp[i + 1][1];
        temp += sum;
        if(n % 2 == 0)
        {
            temp -= v[i];
        }
        else temp += v[i];
        ans = max(ans, temp); sum = dp[i + 1][0];
    }
    cout << ans;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    cin >> TET;
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
}
// -> Keep It Simple Stupid!
