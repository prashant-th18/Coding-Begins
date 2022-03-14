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

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */
vector<vector<ll>> dp;
const int N = 52;
ll ncr(ll n, ll r)
{
    if(r == n) return 1;
    r = min(r, n - r);
    ll res = 1;
    vector<bool> vis(r + 1, false);
    for(ll j = n; j >= n - (r - 1); --j)
    {
        res *= j;
        for(ll i = 1; i <= r; ++i)
        {
            if(!vis[i] && (res % i == 0))
            {
                res /= i; vis[i] = true;
            }
        }
    }
    return res;
}
void init()
{
    dp.assign(N, vector<ll>(N, 0));
    for(ll i = 1; i < N; ++i)
    {
        for(ll j = 1; j <= i; ++j)
        {
            dp[i][j] = ncr(i, j);
        }
    }
    for(int i = 1; i < N; ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            assert(dp[i][j] >= 1);
        }
    }
}

#ifdef LOCAL
#define debug(x) cout << '\n' << "----------------" << '\n' << #x << " : "; _print(x); cout << '\n' << "-------------" << '\n';
#else
#define debug(x)
#endif

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
    // Case-Work
    /*
    for(int i = 1; i <= 10; ++i)
    {
        // [1 .. (1LL << i) - 1]
        map<int, int> mp;
        for(int j = 1; j < (1 << i); ++j)
        {
            ++mp[__builtin_popcount(j)];
        }
        cout << "[ ";
        for(auto val : mp) cout << val.ss << ' ';
        cout << "]\n";
    }
    */
    ll n, k; cin >> n >> k;
    ll i = 1;
    ll ans = 0;
    while(k > 0)
    {
        if(dp[n][i] <= k)
        {
            k -= dp[n][i];
            ans += (i * dp[n][i]);
            ++i;
        }
        else
        {
            ans += (k * i);
            k = 0;
        }
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
