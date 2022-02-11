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
int N = 2e5 + 1;
int solve() {
    ll n, x; cin >> n >> x;
    vector<vector<pair<ll, ll>>> cost(N);
    vector<vector<ll>> ans;
    for (int i = 0; i < n; i++) {
        ll l, r, c;
        cin >> l >> r >> c;
        vector<ll> ttt = {l, r, c};
        ans.push_back(ttt);
        cost[r - l + 1].push_back(pair(l, c));
    }
    vector<vector<ll>> mini(N);
    for (int i = 0; i < N; ++i) {
        sort(cost[i].begin(), cost[i].end());
        vector<ll> temp;
        ll maxx = 1e10;
        for(int j = sz(cost[i]) - 1; j >= 0; --j)
        {
            maxx = min(maxx, cost[i][j].ss);
            temp.push_back(maxx);
        }
        reverse(all(temp));
        mini[i] = temp;
    }
    ll amount = 1e18;
    for (int i = 0; i < n; i++) {
        ll last = ans[i][1], cc = ans[i][2], diff = ans[i][1] - ans[i][0] + 1;
        diff = x - diff;
        if(diff < 0) continue;
        vector<pair<ll, ll>>& temp = cost[diff];
        ll s = 0, e = sz(temp) - 1;
        ll a = -1;
        while(s <= e)
        {
            int mid = (s + e) / 2;
            if(temp[mid].ff > last)
            {
                a = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        if(a != -1)
        {
            amount = min(amount, cc + mini[diff][a]);
        }
    }
    if(amount == (ll)1e18) amount = -1;
    cout << amount;
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
