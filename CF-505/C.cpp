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
    string s; cin >> s;
    char sl = s[0], er = s[sz(s) - 1]; // sl -> starting left, er -> ending right
    int n = sz(s);
    int len = 1, index = 1, end = n;
    int max_len = 1;
    while(1)
{
    bool flag = false;
    for (int i = index; i < end; i++) {
        if(s[i] != s[i - 1]) { ++len; }
        else
        {
            // Check if sl is not the same as the last character of the right sub-string
            if(sl != er)
            {
               sl = s[i - 1];
               er = s[i];
               ++len;
               max_len = max(max_len , len);
               flag = true;
               index = i;
               break;
            }
            else max_len = max(max_len, len), len = 1;
        }
        max_len = max(max_len, len);
    }
    if(!flag) break;
    flag = false;
    for(int i = end - 2; i >= index; --i)
    {
        if(s[i] != s[i + 1]) ++len;
        else
        {
            if(sl != er)
            {
                sl = s[i + 1]; er = s[i];
                ++len; max_len = max(max_len, len);
                flag = true;
                end = i;
                break;
            }
            else max_len = max(max_len, len), len = 1;
        }
        max_len = max(max_len, len);
    }
    if(!flag) break;
}
    cout << max_len;
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
