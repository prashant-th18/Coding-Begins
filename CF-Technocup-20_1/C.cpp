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

inline ll nxt() { ll _; cin >> _; return _; }

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
    ll n; cin >> n;
    vector<ll> v(n);
    for (ll &val : v) {
        cin >> val;
    }
    ll x, a; cin >> x >> a;
    ll y, b; cin >> y >> b;
    if(x < y)
    {
        swap(x, y); swap(a, b);
    }
    ll lc = a / gcd(a, b) * b;
    ll k; cin >> k;
    // Binary Search
    ll s = 1, e = n;
    ll ans = -1;
    sort(v.begin(), v.end(), greater<>());
    while(s <= e)
    {
        ll mid = (s + e) / 2;
        ll j = 0, sum {};
        vector<bool> vis(n + 1, false);
        for(ll i = lc; i <= mid; i += lc)
        {
            vis[i] = true;
            sum += v[j++] / 100 * (x + y);
        }
        for(ll i = a; i <= mid; i += a)
        {
            if(vis[i]) continue;
            else
            {
                vis[i] = true;
                sum += v[j++] / 100 * (x);
            }
        }
        for(ll i = b; i <= mid; i += b)
        {
            if(vis[i]) continue;
            else
            {
                sum += v[j++] / 100 * y;
            }
        }
        if(sum >= k)
        {
            ans = mid;
            e = mid - 1;
        }
        else s = mid + 1;
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
