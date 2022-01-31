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
    ll n = nxt();
    vector<ll> v(n);
    for (ll &val : v) {
        cin >> val;
    }
    // Every Term is ->
    // SUM{ (j + 1) * a[(i - j + 1 + n) % n  } where we say v[i]
    // 12 = 1 * a0 + 3 * a1 + 2 * a2
    // 16 = 1 * a1 + 2 * a0 + 3 * a2
    // 14 = 1 * a2 + 2 * a1 + 3 * a0
    //
    //
    // 12 = 1 * a0 + 3 * a1 + 2 * a2
    // 16 = 2 * a0 + 1 * a1 + 3 * a2
    // 14 = 3 * a0 + 2 * a1 + 1 * a2
    ll sum = accumulate(all(v), 0LL);
    if(sum % (n * (n + 1) / 2) != 0)
    {
        cout << "NO";
        return 0;
    }
    vector<ll> res(n);
    sum /= (n * (n + 1) / 2);
    for(int i = 0; i < n; ++i)
    {
        ll t = v[i] - v[(i - 1 + n) % n];
        ll rem = sum;
        rem -= t;
        if(rem <= 0 || rem % n != 0)
        {
            cout << "NO";
            return 0;
        }
        res[i] = rem / n;
    }
    cout << "YES\n";
    for(auto val : res) cout << val << ' ';
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
