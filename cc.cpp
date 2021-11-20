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
int dp[101][4][3];
vector<int> v;
int recursive_function(const vector<int>& a, int pre, int i, int cnt = 0)
{
    if (i >= sz(a))
    {
        return cnt;
    }
    int x = INT_MAX, y = INT_MAX, z = INT_MAX;
    if (dp[i][pre + 1][0] == -1)
    {
        x = recursive_function(a, -1, i + 1, cnt + 1);
    }
    if (pre == -1)
    {
        if (v[i] == 1)
        {
            y = recursive_function(a, 1, i + 1, cnt);
        }
        if (v[i] == 2)
        {
            z = recursive_function(a, 2, i + 1, cnt);
        }
        else if (v[i] == 3)
        {
            y = recursive_function(a, 1, i + 1, cnt);
            z =  recursive_function(a, 2, i + 1, cnt);
        }
        return min({x, y, z});
    }
    else if (pre == v[i])
    {
        return x;
    }
    else
    {
        if (v[i] == 3)
        {
            if (pre == 1) {z = recursive_function(a, 2, i + 1, cnt);}
            if (pre == 2) {y = recursive_function(a, 1, i + 1, cnt); }
        }
        else
        {
            if (v[i] == 2) {z =  recursive_function(a, 2, i + 1, cnt); }
            if (v[i] == 1) {y = recursive_function(a, 1, i + 1, cnt); }
        }
        return min( {x, y, z} );
    }
}
int solve() {
    for (auto& val : dp)
    {
        for (auto& vv : val)
        {
            for (auto &v2 : vv)
                v2 = -1;
        }
    }
    int n; cin >> n;
    v = vector<int>(n);
    for (auto &val : v) cin >> val;
    cout << recursive_function(v, -1, 0, 0);
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
