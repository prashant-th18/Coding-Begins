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
    string s; cin >> s;
    map<char, int> mp;
    for (int i = 0; i < sz(s); i++) {
        ++mp[s[i]];
    }
    sort(s.begin(), s.end());
    vector<pair<int, int>> v;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int tt; cin >> tt;
        v.push_back({tt, i});
    }
    string res = string(n, '.');
    int i = sz(s) - 1;
    while(i >= 0)
    {
        sort(v.begin(), v.end());
        int c {};
        for(int j = 0; j < sz(v); ++j) if(v[j].first == 0) ++c;
        while(i >= 0 && mp[s[i]] < c)
        {
            --i;
        }
        char ch = s[i];
        for(int j = 0; j < c; ++j)
        {
            ll to_dec = v[0].second;
            res[to_dec] = ch;
            for(int k = 0; k < sz(v); ++k)
            {
                if(v[k].first != 0)
                {
                    v[k].first -= abs(to_dec - v[k].second);
                }
            }
            v.erase(v.begin());
        }
        while(i >= 0 && ch == s[i]) --i;
    }
    cout << res;
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
