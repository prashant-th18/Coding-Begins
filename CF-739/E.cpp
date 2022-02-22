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
    set<char> pre, cur;
    int n = sz(s);
    int i = n - 1, k = 1, index = n - 1;
    string sec = "";
    while(i >= 0)
    {
        cur.insert(s[i]);
        if(sz(cur) == k + 1)
        {
                cur.erase(s[i]);
                map<char, int> mp;
                for(auto val : cur) mp[val]++;
                for(auto val : pre) mp[val]++;
                for(const auto& val : cur) pre.insert(val);
                if(sz(pre) == k)
                {
                    index = i;
                    ++i;
                    cur.clear();
                    for(auto val : mp) if(val.ss == 1) sec += val.ff;
                }
                else
                {
                    cout << -1; return 0;
                }
                ++k;
        }
        --i;
    }
    if(sz(cur) != 0)
    {
        if(sz(pre) != 0) 
        {
            cout << -1;
            return 0;
        }
        else
        {
            sec += *cur.begin();
        }
    }
    reverse(all(sec));
    cout << (s.substr(0, index + 1)) << ' ' << sec; 
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
    return 0;
}
// -> Keep It Simple Stupid!

