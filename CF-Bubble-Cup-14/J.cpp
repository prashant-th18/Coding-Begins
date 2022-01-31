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
template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
// use -> auto gcd = y_combinator([](auto gcd, int a, int b) -> int { return b == 0 ? a : gcd(b, a % b);});
int solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    auto dfs = y_combinator([&](auto dfs, int x, int y) -> int
    {
         int cc = 1;
         vis[x][y] = true;
         for(auto val : {0, 1, 2, 3}) // Left, Down, Right, Up
         {
            ll temp = 1 << val;
            if((v[x][y] & temp) == 0)
            {
                if(val == 0)
                {
                    if(!vis[x][y - 1] && ((v[x][y - 1] & (1 << 2)) == 0)) cc += dfs(x, y - 1);
                }
                else if(val == 1)
                {
                    if(!vis[x + 1][y] && ((v[x + 1][y] & (1 << 3)) == 0)) cc += dfs(x + 1, y);
                }
                else if(val == 2)
                {
                    if(!vis[x][y + 1] && ((v[x][y + 1] & (1 << 0)) == 0)) cc += dfs(x, y + 1);
                }
                else
                {
                    if(!vis[x - 1][y] && ((v[x - 1][y] & (1 << 1)) == 0)) cc += dfs(x - 1, y);
                }
            }
         }
         return cc;
    });
    vector<int> res;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(!vis[i][j])
            {
                res.push_back(dfs(i, j));
            }
        }
    }
    sort(res.rbegin(), res.rend());
    for(auto val : res) cout << val << ' ';
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
