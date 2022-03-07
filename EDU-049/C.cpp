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
    /*for(int i = 1; i <= 1000; ++i)
    {
        // i -> l1
        vector<double> v;
        for(int j = i; j <= 1000; ++j)
        {
            v.push_back((double)i / j + (double)j / i);
        }
        for(int j = 1; j < sz(v); ++j)
        {
            assert(v[j] >= v[j - 1]);
        }
    }
    */
    map<int, int> mp;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        mp[t]++;
    }
    vector<int> p;
    for(auto val : mp)
    {
        int i = val.ff;
        if(2 <= val.ss)
        {
            if(4 <= val.ss)
            {
                p.push_back(i);
                p.push_back(i);
            }
            else
            {
                p.push_back(i);
            }
        }
    }
    auto pi = pair(0, 1);
    for(int i = 1; i < sz(p) - 1; ++i)
    {
        ll res1 = p[pi.ff] + p[pi.ss];
        res1 *= res1;
        ll res2 = p[i] + p[i + 1];
        res2 *= res2;
        ll d1 = p[pi.ff] * p[pi.ss];
        ll d2 = p[i] * p[i + 1];
        res1 *= lcm(d1, d2) / d1;
        res2 *= lcm(d1, d2) / d2;
        if(res2 < res1)
        {
            pi = pair(i, i + 1);
        }
    }
    int t1 = p[pi.ff], t2 = p[pi.ss];
    cout << t1 << ' ' << t1 << ' ' << t2 << ' ' << t2;
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
