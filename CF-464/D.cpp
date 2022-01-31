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
int N = 26;
vector<vector<int>> adj(N);
vector<bool> vis(N, false);
int solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    vector<vector<bool>> v(26, vector<bool>(26, false));
    for (int i = 0; i < n; i++) {
        if(a[i] != b[i])
        {
            v[a[i] - 97][b[i] - 97] = v[b[i] - 97][a[i] - 97] = true;
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if(v[i][j])
            {
                adj[i].push_back(j);
            }
        }
    }
    vector<pair<int, int>> ans;
    auto fun = [&](int num) -> void
    {
        vis[num] = true;
        queue<int> q; q.push(num);
        while(!q.empty())
        {
            int f = q.front(); q.pop();
            for(const auto& val : adj[f])
            {
                if(!vis[val])
                {
                    q.push(val); vis[val] = true;
                    ans.push_back(pair(val, f));
                }
            }
        }
    };
    for(int i = 0; i < 26; ++i)
    {
        if(!vis[i])
        {
            fun(i);
        }
    }
    cout << sz(ans) << '\n';
    reverse(all(ans));
    for(auto [x, y] : ans)
    {
        cout << (char)(x + 97) << ' ' << (char)(y + 97) << '\n';
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
