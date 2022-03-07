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

char fun(char ind, ll p, ll k)
{
    if(p == 0)
    {
        return ind;
    }
    map<char, string> mp;
    mp['A'] = "BC"; mp['B'] = "CA"; mp['C'] = "AB";
    if((1LL << (p - 1)) >= k)
    {
        return fun(mp[ind][0], p - 1, k);
    }
    else
    {
        return fun(mp[ind][1], p - 1, k - ((1LL << (p - 1))));
    }
}
// *-> KISS*
int solve() {
    string s;
    cin >> s;
    int q; cin >> q;
    while(q--)
    {
        ll t, k; cin >> t >> k;
        int si = 0, ei = sz(s) - 1;
        int ans = -1;
        while(si <= ei)
        {
            ll mid = (si + ei) >> 1;
            if(t >= 60)
            {
                ans = mid;
                ei = mid - 1;
            }
            else if((mid + 1) > (ll)1e18 / (1LL << t))
            {
                ans = mid;
                ei = mid - 1;
            }
            else if((mid + 1) * (1LL << t) >= k)
            {
                ans = mid;
                ei = mid - 1;
            }
            else
            {
                si = mid + 1;
            }
        }
        if(t >= 60)
        {
            char ch = s[0];
            string temp = "ABC";
            ll diff = (t - 60);
            diff %= 3;
            ll index = temp.find(ch);
            index = (index + diff) % 3;
            cout << fun(s[index], 60, k) << '\n';
        }
        else
        {
            debug("HERE");
            k -= (ans * (1LL << t));
            assert(k >= 0);
            cout << fun(s[ans], t, k) << '\n';
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
