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
int N = 2e5;
vector<vector<int>> v(N);
vector<bool> vis(N, false);
vector<ll> sum(N, 0);
vector<ll> value(N, 0);
vector<ll> parent(N, 0);
int solve() {
    ll n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a; cin >> a;
        parent[i + 2] = a;
        // i + 2, a
        v[a].push_back(i + 2);
        v[i + 2].push_back(a);
    }
    // Now I have the tree
    for (int i = 0; i < n; i++) {
        ll a; cin >> a;
        sum[i + 1] = a;
    }
    ll c = 0;
    function<bool(ll, ll)> dfs = [&](ll node, ll depth) -> bool
    {
          vis[node] = true;
          if(depth & 1)
          {
              for(const auto& val : v[node])
              {
                  if(!vis[val])
                  {
                  if(!dfs(val, depth + 1))
                  {
                      return false;
                  }
                  }
              }
              return true;
          }
          else
          {
                ll pre_sum = sum[parent[node]];
                ll mini = 1e18;
                for(const auto& val : v[node])
                {
                    if(!vis[val])
                    {
                        mini = min(mini, sum[val]);
                    }
                }
                if(mini == (ll)1e18) {}
                else
                {
                    if(mini < pre_sum) return false;
                    else
                    {
                        value[node] = mini - pre_sum;
                        for(const auto& val : v[node])
                        {
                            if(!vis[val])
                            {
                                value[val] = sum[val] - pre_sum - value[node];
                                if(dfs(val, depth + 1) == false) return false;
                            }
                        }
                    }
                }
                return true;
          }
    };
    if(!dfs(1, 1))
    {
        cout << -1;
        return 0;
    }
    c = 0;
    value[1] = sum[1];
    for(int i = 1; i <= n; ++i) c += value[i];
    cout << c;
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
