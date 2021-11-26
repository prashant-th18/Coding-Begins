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
#define debug(x) cout << "----------------" << endl << #x << " : "; _print(x); cout << "-------------" << '\n';
#else
#define debug(x)
#endif

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
    ll n, l, r; cin >> n >> l >> r;
    ll one, two, three;
    one = two = three = 0;
    three += (r / 3 - (l - 1) / 3);
    ll tt = (r / 3 - ((l + 2) / 3));
    one += max(0LL, tt); two += max(0LL, tt);
    ll d1 = (l + 2) / 3 * 3 - l;
    if(d1 >= 2)
    {
        one++; two++;
    }
    else if(d1 == 1) two++;
    ll d2 = r - (r / 3 * 3);
    if(r - l >= 3)
    {
    if(d2 >= 2) { one++; two++; }
    else if(d2 == 1) one++;
    }
    debug(one);
    debug(two);
    debug(three);
    ////////////////////////////////
    vector<ll> dp(n + 1, 0LL);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if(i == 1)
        {
            dp[i] = three % MOD * dp[i - 1];
        }
        else if(i == 2)
        {
            dp[i] = three * dp[i - 1] % MOD;
            dp[i] = (dp[i] + (one * two) % MOD * dp[i - 2] % MOD) % MOD;
        }
        else
        {
            dp[i] = ((three * dp[i - 1] % MOD + (two * one % MOD) * dp[i - 2] % MOD) % MOD);
            dp[i] = (((dp[i] + (one * dp[i - 3] % MOD)) % MOD + (two * dp[i - 3] % MOD)) % MOD);
        }
        debug(dp[i]);
    }
    cout << dp[n];
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    //cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        #ifdef LOCAL
            cout << '\n' << "##################";
        #endif
        cout << '\n';
    }
    #ifdef LOCAL
        cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}
// -> Keep It Simple Stupid!
