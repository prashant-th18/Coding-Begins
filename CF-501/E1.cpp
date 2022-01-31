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
int n, m;
vector<vector<bool>> mp(1011, vector<bool>(1011, false)), center(1011, vector<bool>(1011, false));
vector<vector<char>> v(1001, vector<char>(1001, '.'));
vector<tuple<int, int, int>> t;
void call(int a, int b)
{
    ll tt1 = -1;
    int si = 1, ei = 2000;
    while(si <= ei)
    {
        int mid = (si + ei) / 2;
        if(2 * mid + 1 <= n - a) tt1 = mid, si = mid + 1;
        else ei = mid - 1;
    }

    ll tt2 = (b);

    ll tt3 = (m - b - 1);

    ll mini = min(tt1, min(tt2, tt3));
    debug(mini);
    for(int i = 2 * mini + 1; i >= 3 ; i -= 2)
    {
        debug(i);
        if(center[a + i / 2 + 1][b + 1] == true) continue;
        vector<vector<bool>> temp(1001, vector<bool>(1001, false));
            bool flag = true;
            for(int j = a; j < a + i; ++j)
            {
                if(v[j][b] == '.')
                {
                    flag = false; break;
                }
                temp[j][b] = true;
            }
            if(!flag) continue;
            // a + i / 2
            for(int j = b - i / 2; j <= b + i / 2; ++j)
            {
                if(v[a + i / 2][j] == '.') { flag = false; break; }
                temp[a + i / 2][j] = true;    
            }
            debug(flag);
            if(flag)
            {
                bool fflag = false;
                for(const auto& val : temp)
                {
                    if(mp[val[0]][val[1]] == false)
                    {
                        fflag = true; break;
                    }
                }
                if(fflag)
                {
                    for(const auto& val : temp) 
                    {
                        mp[val[0]][val[1]] = true;
                    }
                    t.push_back(tuple(a + i / 2 + 1, b + 1, i / 2));
                    center[a + i / 2 + 1][b + 1] = true;
                    debug("HELLO");
                }
            }
        }
}
int solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(v[i][j] == '*')
            {
                call(i, j);
                if(mp[i][j] == false)
                {
                    cout << -1; return 0;
                }
            }
        }
    }
    cout << sz(t) << '\n';
    for(auto val : t)
    {
        cout << get<0>(val) << ' ' << get<1>(val) << ' ' << get<2>(val) << '\n';
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
}
// -> Keep It Simple Stupid!
