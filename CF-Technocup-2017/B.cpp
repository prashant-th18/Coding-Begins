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
void _print(long double a) {cout << a;}

// *-> KISS*
int solve() {
    string s; cin >> s;
    int n = sz(s);
    ld sum = 0;
    for(int i = 0; i < n; ++i)
    {
        if('0' <= s[i] && s[i] <= '9')
        {
            int j;
            string res = "";
            for(j = i; j < n && (('0' <= s[j] && s[j] <= '9') || s[j] == '.'); ++j)
            {
                res += s[j];
            }
            i = j - 1;
            int ff = (int)res.rfind('.');
            if(ff == -1)
            {
                sum += stold(res);
            }
            else
            {
                debug(res);
                debug(sum);
                // sz(res) - ff - 1
                if(sz(res) - ff - 1 == 2)
                {
                    sum += (0.1 * (res[ff + 1] - '0') + 0.01 * (res[ff + 2] - '0'));
                    res = res.substr(0, ff);
                }
                string na = "";
                for(int k = 0; k < sz(res); ++k)
                {
                    if(res[k] == '.') continue;
                    else na += res[k];
                }
                sum += stold(na);
                debug(sum);
            }
        }
    }
    string an = "";
    if(sum - (ll)sum != 0)
    {
        string what = to_string(sum);
        int f = what.find('.');
        an += (what[f + 2]);
        an += what[f + 1];
        if(an == "00") an = "";
        else an += ".";
    }
    string ans = to_string((ll)sum);
    for(int i = sz(ans) - 1, cnt = 0; i >= 0; --i, cnt++)
    {
        if(cnt % 3 == 0 && cnt != 0)
        {
            an += ".";
        }
        an += ans[i];
    }
    reverse(all(an));
    cout << an;
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
}
// -> Keep It Simple Stupid!
