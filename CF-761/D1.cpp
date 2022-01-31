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
    int n; cin >> n;
    vector<int> imp, crew;
    bool ch = false;
    // 1 2 {3 . 4 . 5 . 6 . 7 . 8 . ...}
    int a = 1, b = 2;
    
    int pre = -1;
    vector<bool> im(n + 1, false), cc(n + 1, false);
    for(int i = 3; i <= n; ++i)
    {
        cout << "? " << a << ' ' << b << ' ' << i << endl;
        int num; cin >> num;
        if(pre != -1 && pre != num)
        {
            if(num == 1)
            {
                crew.push_back(i), imp.push_back(i - 1);
            }
            else
            {
                crew.push_back(i - 1), imp.push_back(i);
            }
            ch = true;
            pre = num;
            continue;
        }
        if(num == 0)
        {
            pre = 0;
        }
        else
        {
            pre = 1;
        }
    }
    if(!ch)
    {
        imp.push_back(a), imp.push_back(b);
    }
    a = crew[0];
    b = imp[0];
    for(int i = 1; i <= n; ++i)
    {
        if(i == a || i == b) continue;
        else
        {
            cout << "? " << a << ' ' << b << ' ' << i << endl;
            int num; cin >> num;
            if(num == 1)
            {
                    crew.push_back(i); cc[i] = true;
            }
            else
            {
                    imp.push_back(i); im[i] = true;
            }
        }
    }
    set<int> ttt;
    for(auto val : imp) ttt.insert(val);
    cout << "! " << sz(ttt) << ' ';
    
    for(auto val : ttt) cout << val << ' ';
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
        cout << endl;
    }
#ifdef LOCAL
    cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
// -> Keep It Simple Stupid!
