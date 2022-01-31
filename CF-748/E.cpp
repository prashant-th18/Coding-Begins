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

// *-> KISS*
int solve() {
    int n, k; cin >> n >> k;
    vector<set<int>> v(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        v[a].insert(b);
        v[b].insert(a);
    }
    vector<bool> vis(n + 1, false);
    queue<int> q, q1;
    for (int i = 1; i < n + 1; i++) {
        if(sz(v[i]) <= 1) q.push(i), vis[i] = true;
    }
    int cnt = 0;
    while(1)
{
    while(!q.empty() && cnt < n && k > 0)
    {
        int ff = q.front(); q.pop();
        ++cnt;
        if(sz(v[ff]) != 0)
        {
            int fr = *(v[ff].begin());
            v[ff].erase(fr);
            v[fr].erase(ff);
            if(sz(v[fr]) <= 1)
            {
                if(!vis[fr])
                {
                    q1.push(fr); vis[fr] = true;
                }
            }
        }
    }
    --k;
    while(!q1.empty())
    {
        q.push(q1.front()); q1.pop();
    }
    if(k <= 0 || cnt >= n || sz(q) == 0) break;
}
    cout << n - cnt;
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
