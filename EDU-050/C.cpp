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
    ll a, b; cin >> a >> b;
    auto ncr = [&](ll n, ll r) -> ll
    {
        if(r > n) return 0;
        if(r == 0)
        {
            return 1;
        }
        else if(r == 1)
        {
            return n;
        }
        else return n * (n - 1) / 2;
    };
    // No - Constraint
    auto noc = [&](ll dig, ll cnt) -> ll // cnt tells how many non-zero digits used till now
    {
        if(dig <= 0) return 1;
        // MSB -> 1
        ll x = ncr(dig - 1, 0), y = ncr(dig - 1, 1) * 9, z = ncr(dig - 1, 2) * 81;
        ll res = 9;
        if(dig == 1)
        {
            if(cnt <= 2)
            {
                res++;
            }
            return res;
        }
        if(cnt == 0)
        {
            res *= (x + y + z);
        }
        else if(cnt == 1)
        {
            res *= (x + y);
        }
        else if(cnt == 2)
        {
            res *= (x);
        }
        else
        {
            res = 1;
        }
        return res;
    };
    ll sdig, edig;
    sdig = 2 + floor(log10(a)); edig = floor(log10(b));
    ll ans = 0;
    for(ll i = sdig; i <= edig; ++i) ans += noc(i, 0);
    // Constraint 
    auto c = [&] (ll up) -> ll
    {
        if(up == 0) return 1;
        ll res = 0;
        // Let's Work on MSB
        string s = to_string(up);
        res += ((s[0] - '0') - 1) * noc(sz(s) - 1, 0);
        int c_non = 1;
       // debug(res);
        for(int i = 1; i < sz(s); ++i)
        {
            if(c_non > 3) break;
            ll digit = s[i] - '0';
            if(digit == 0) continue;
            else
            {
                res += (digit) * noc(sz(s) - i - 1, c_non);
                c_non++;
            }
        }
        if(sz(s) == 1) ++res;
        if(c_non <= 3) { ++res; }
        debug(res);
        return res;
    };
    debug(ans);
    ll last = c(b);
    ll first = 0;
    string f1 = to_string(a), f2 = to_string(b);
    ll index = (ll)pow(10, sz(f1));
    if(sz(f1) != sz(f2))
    {
        first += noc(index - 1, 0);
        if(sz(to_string(a)) == sz(to_string(a - 1)))
        first -= c(a - 1);
    } 
    else
    {
        if(sz(to_string(a)) == sz(to_string(a - 1)))
        {
            first -= c(a - 1);
        }
    }
    cout << ans + first + last;
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
        if(solve())
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
