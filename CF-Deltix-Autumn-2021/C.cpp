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
void _print(double a) {cout << a;}

int N = 1e6 + 1;
vector<bool> vis(N, true);
// *-> KISS*
void pre()
{
    vis[0] = vis[1] = false;
    for(int i = 4; i < N; i += 2) vis[i] = false;
    for(ll i = 3; i < N; ++i)
    {
        if(vis[i])
        {
            for(ll j = i * i; j < N; j += 2 * i) vis[j] = false;
        }
    }
}
int solve() {
    int n, e; cin >> n >> e;
    vector<int> v(n);
    for (int &val : v) {
        cin >> val;
    }
    vector<vector<int>> groups;
    for(int i = 0; i < e; ++i)
    {
        vector<int> temp;
        for(int j = i; j < n; j += e)
        {
            if(v[j] == 1 || vis[v[j]]) temp.push_back(v[j]);
            else
            {
                if(sz(temp) != 0)
                {
                    groups.push_back(temp);
                    temp.clear();
                }
            }
        }
        if(sz(temp) != 0) groups.push_back(temp);
    }
    ll ans = 0;
    vector<vector<int>> next_prime(sz(groups));
    for (int i = 0; i < sz(groups); i++) {
        vector<int> temp(sz(groups[i]));
         int ind = -1;
         for(int j = sz(groups[i]) - 1; j >= 0; --j)
         {
             temp[j] = ind;
             if(vis[groups[i][j]]) ind = j;
         }
        for(int j = 0; j < sz(temp) - 1; ++j)
        {
            if(vis[groups[i][j]])
            {
                int nxt = temp[j];
                if(nxt == -1)
                {
                    ans += (sz(temp) - (j + 1));
                }
                else
                {
                    ans += (nxt - j - 1);
                }
            }
            else
            {
                int nxt = temp[j];
                if(nxt == -1)
                {
                    assert(true);
                }
                else
                {
                    int nnxt = temp[nxt];
                    if(nnxt == -1)
                    {
                        ans += (sz(temp) - nxt);
                    }
                    else
                    {
                        ans += (nnxt - nxt);
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    cin >> TET;
    cout << fixed << setprecision(6);
    pre();
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
    return 0;
}
// -> Keep It Simple Stupid!
