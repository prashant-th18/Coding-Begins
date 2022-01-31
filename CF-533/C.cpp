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
int N = (int)2e5 + 1;
vector<vector<ll>> v(N, vector<ll>(3));
int solve() {
    ll n, l, r; cin >> n >> l >> r;
    ll one, two, three;
    one = two = three = 0;
    map<ll, bool> mp;
    for(ll i = l; i <= min(r, l + 3); ++i)
    {
        if(i % 3 == 0) break;
        else if(i % 3 == 1) ++one;
        else ++two;
        mp[i] = true;
    }
    for(ll i = r; i >= max(l, r - 3); --i)
    {
        if(mp[i]) break;
        if(i % 3 == 0) break;
        else if(i % 3 == 1) ++one;
        else ++two;
    }
    three += (r / 3 - (l - 1) / 3);
    one += max(0LL, three - 1); two += max(0LL, three - 1);
    debug(one); debug(two); debug(three);
    v[1][0] = three; v[1][1] = one; v[1][2] = two;
    for (int i = 2; i <= n; i++) {
        v[i][0] = (((v[i - 1][0] * three % MOD) + (v[i - 1][1] * two % MOD)) % MOD + (v[i - 1][2] * one % MOD)) % MOD;
        v[i][1] = (((v[i - 1][0] * one % MOD) + (v[i - 1][1] * three % MOD)) % MOD + (v[i - 1][2] * two % MOD)) % MOD;
        v[i][2] = (((v[i - 1][0] * two % MOD) + (v[i - 1][2] * three % MOD)) % MOD + (v[i - 1][1] * one % MOD)) % MOD;
    }
    cout << v[n][0];
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
