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
    ll n, p, q; cin >> n >> p >> q;
    string s; cin >> s;
    int x = 0, y = 0;
    int dir = -1;
    // We will simulate the whole process
    // dir == 1 means movement in x axis otherwise in y axis
    // We will try to reach (p, q) everytime
    // if s[i] == '1' go in the opposite direction but take such step such that you reach more near to 
    // your destination
    // Reached the destination but still string is left??
    // Try to stay as close as possible to the point
    // Let's start with movement towards x - axis;
    dir = 1;
    auto movement = [&]()
    {
        if(dir == 1)
        {
            if(p >= x) ++x;
            else --x;
        }
        else
        {
            if(q >= y) ++y;
            else --y;
        }
    };
    for (int i = 0; i < n; i++) {
        if(s[i] == '1')
        {
            movement();
        }
        else
        {
            dir = 1 - dir;
            movement();
        }
    }
    if(x == p && y == q)
    {
        cout << "YES";
        return 0;
    }
    dir = 0;
    x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if(s[i] == '1') movement();
        else dir = 1 - dir, movement();
    }
    if(x == p && y == q) cout << "YES";
    else cout << "NO";
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
