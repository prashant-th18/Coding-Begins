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
    vector<int> rel(n + 10);
    for (int i = 0; i < n; i++) {
        rel[i] = n - 1 - i;
    }
    if(k == n - 1)
    {
        int num = 1;
        vector<int> maybe, maybe2;
        vector<bool> vis(n + 10);
        for(; num <= n / 2; num *= 2)
        {
            maybe.push_back(num);
            maybe2.push_back(rel[num]);
            vis[num] = vis[rel[num]] = true;
        }
        vector<pair<int, int>> ans;
            swap(maybe2[sz(maybe) / 2], maybe2[0]);
        for(int i = 0; i < sz(maybe); ++i)
        {
            ans.push_back({maybe[i], maybe2[sz(maybe) - i - 1]});
        }
        for(int i = 0; i <= n - 1; ++i)
        {
            if(!vis[i] && !vis[rel[i]] && i != rel[i])
            {
                ans.push_back({i, rel[i]});
                vis[i] = vis[rel[i]] = true;
            }
        }
        if(sz(ans) != n / 2) cout << -1;
        else
        for(auto val : ans) cout << val.ff << ' ' << val.ss << '\n';
    }
    else
    {
        vector<bool> vis(n + 1, false);
        vector<pair<int, int>> ans;
        set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(i);
        }
        int j = k;
        ans.push_back({j, n - 1});
        st.erase(n - 1); st.erase(j); vis[n - 1] = vis[j] = true;
        ++j;
        while(sz(st) > 2)
        {
            j %= n;
            if(!vis[j] && !vis[rel[j]])
            {
                vis[j] = vis[rel[j]] = true;
                ans.push_back({j, rel[j]});
                st.erase(j); st.erase(rel[j]);
            }
            ++j;
        }
        if(sz(st) != 0)
        {
            int n1 = *st.begin();
            st.erase(st.begin());
            assert(sz(st) > 0);
            int n2 = *st.begin();
            st.erase(st.begin());
            ans.push_back({n1, n2});
        }
        ll sum = 0;
        for (int i = 0; i < sz(ans); i++) {
            sum += ans[i].ff & ans[i].ss;
        }
        if(sum != k || sz(ans) != n / 2) cout << -1;
        else
        {
            for(auto val : ans) cout << val.ff << ' ' << val.ss << '\n';
        }
    }
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
