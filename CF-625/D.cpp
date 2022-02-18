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

vector<vector<int>> v;
vector<vector<int>> t;
vector<bool> vis;
vector<int> dist;
// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
    v = vector<vector<int>>(n + 1);
    t = v;
    vis.assign(n + 1, false);
    dist.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        t[b].push_back(a);
    }
    auto bfs = [&](int node) -> void
    {
        queue<int> q; q.push(node); vis[node] = true;
        dist[node] = 0;
        while(!q.empty())
        {
            int f = q.front(); q.pop();
            for(const auto& val : t[f])
            {
                if(!vis[val])
                {
                    vis[val] = true;
                    dist[val] = 1 + dist[f];
                    q.push(val);
                }
            }
        }
    };
    int k; cin >> k;
    vector<int> perm(k);
    for (int &val : perm) {
        cin >> val;
    }
    bfs(perm[k - 1]);
    ll maxx = 0, minn = 0;
    for(int i = 0; i < k; ++i)
    {
        int node = perm[i];
        vector<int> temp;
        for(const auto& val : v[node])
        {
            temp.push_back(dist[val]);
        }
        sort(temp.begin(), temp.end());
        if(i != k - 1)
        {
            ll next = dist[perm[i + 1]];
            ll maxi = upper_bound(all(temp), next) - temp.begin();
            --maxi;
            if(maxi > 0) maxi = 1;
            else maxi = 0;
            maxx += maxi;
            ll mini = lower_bound(all(temp), next) - begin(temp);
            if(mini > 0) mini = 1;
            else mini = 0;
            minn += mini;
        }
    }
    cout << minn << ' ' << maxx;
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
    return 0;
}
// -> Keep It Simple Stupid!
