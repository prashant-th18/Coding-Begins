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
map<pair<ll, ll>, ll> mp;
vector<ll> fact;
ll max_power(ll num)
{
    ll s = 0, e = 60, ans = 0;
    while(s <= e)
    {
        ll mid = (s + e) >> 1;
        ll temp = (1LL << mid);
        if(temp <= num)
        {
            ans = mid;
            s = mid + 1;
        }
        else e = mid - 1;
    }
    return ans;
}
ll fun(ll num, ll index, ll p)
{
    if(num == 0)
    {
        return 0;
    }
    if(__builtin_popcountll(num) == 1)
    {
        return mp[pair(num, index)] = 1;
    }
    if(mp.count(pair(num, index))) return mp[pair(num, index)];
    // 2 ki power use krlo
    // maximum factorial use krlo jo ki abhi tk sirf ek baar use hua hai
    ll ans = LLONG_MAX;
    ll rem = index;
    while(index >= 0 && fact[index] > num) --index;
    if(index >= 0)
    {
        ans = min(ans, 1LL + fun(num - fact[index], index - 1, p));
    }
    while(p >= 0 && (1LL << p) > num) --p;
    ans = min(ans, 1LL + fun(num - (1LL << p), index, p - 1));
    ans = min(ans, 1LL + fun(num - (1LL << p), index - 1, p - 1)); 
    return mp[pair(num, rem)] = ans;
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
    ll n; cin >> n;
    ll max_p = max_power(n);
    cout << fun(n, sz(fact) - 1, max_p);
    return 0;
}
void pre()
{
    ll ans = 1;
    for(ll i = 1; ; ++i)
    {
        ans = ans * i;
        if(i == 2) continue;
        fact.push_back(ans);
        if(ans > (ll)1e13) break;
    }
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    cin >> TET;
    pre();
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
