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
    int n; cin >> n;
    map<int, vector<int>> mp;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]].push_back(i + 1);
    }
    sort(v.begin(), v.end());
    vector<pair<int, bool>> prefix(n); // common difference , true => AP 
    vector<pair<int, bool>> suffix(n);
    for (int i = 0; i < n; i++) {
        if(i == 0)
        {
            prefix[i] = {0, true};
        }
        else if(i == 1)
        {
            prefix[i] = {v[i] - v[i - 1], true};
        }
        else if(prefix[i - 1].ss == false)
        {
            prefix[i] = prefix[i - 1];
        }
        else
        {
            if(v[i] - v[i - 1] == prefix[i - 1].ff)
            {
                prefix[i] = prefix[i - 1];
            }
            else
            {
                prefix[i] = {0, false};
            }
        }
    }
    for(int i = n - 1; i >= 0; --i)
    {
        if(i == n - 1)
        {
            suffix[i] = {0, true};
        }
        else if(i == n - 2)
        {
            suffix[i] = {v[i + 1] - v[i], true};
        }
        else if(suffix[i + 1].ss == false)
        {
            suffix[i] = suffix[i + 1];
        }
        else
        {
            if(v[i + 1] - v[i] == suffix[i + 1].ff)
            {
                suffix[i] = suffix[i + 1];
            }
            else
            {
                suffix[i] = {0, false};
            }
        }
    }
    if(n <= 3)
    {
        cout << 1; return 0;
    }
    for(int i = 0; i < n; ++i)
    {
        if(i == 0)
        {
            if(suffix[i + 1].ss)
            {
                cout << mp[v[i]].back();
                return 0;
            }
        }
        else if(i == n - 1)
        {
            if(prefix[i - 1].ss) { cout << mp[v[i]].back(); return 0; }
        }
        else if(i == 1)
        {
           if(suffix[i + 1].ss)
           {
                ll ndiff = v[i + 1] - v[i - 1];
                if(suffix[i + 1].ff == ndiff)
                {
                    cout << mp[v[i]].back(); return 0;
                }
           }
        }
        else if(i == n - 2)
        {
            if(prefix[n - 3].ss && (v[n - 1] - v[n - 3] == prefix[n - 3].ff))
            {
                cout << mp[v[i]].back(); return 0;
            }
        }
        else
        {
            if(prefix[i - 1].ss && suffix[i + 1].ss && prefix[i - 1].ff == suffix[i + 1].ff && (v[i + 1] - v[i - 1] == prefix[i - 1].ff))
            {
                cout << mp[v[i]].back(); return 0;
            }
        }
    }
    cout << -1;
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
