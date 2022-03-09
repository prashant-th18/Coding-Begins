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
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        mp[t].push_back(i);
    }
    vector<vector<int>> v;
    for(auto val : mp)
        v.push_back(val.ss);
    sort(v.begin(), v.end(), [&](vector<int> a, vector<int> b) {
        return sz(a) < sz(b);
            });
    int a = 0, b = 0;
    /*auto f = [&]() -> void
    {
        if(a < b)  
    };*/
    string s = string(n, '.');
    for (int i = 0; i < sz(v); i++) {
        if(sz(v[i]) == 1)
        {
            if(a <= b)
            {
                ++a, s[v[i][0]] = 'A';
            }
            else if(b < a)
            {
                ++b, s[v[i][0]] = 'B';
            }
        }
        else if(sz(v[i]) == 2)
        {
            s[v[i][0]] = s[v[i][1]] = 'A';
        }
        else
        {
            if(a < b)
            {
                ++a;
                s[v[i][0]] = 'A';
                for(int j = 1; j < sz(v[i]); ++j) s[v[i][j]] = 'B';
            }
            else if(b < a)
            {
                s[v[i][0]] = 'B';
                ++b;
                for(int j = 1; j < sz(v[i]); ++j) s[v[i][j]] = 'A';
            }
            else 
            {
                for(int j = 0; j < sz(v[i]); ++j) s[v[i][j]] = 'A';
            }
        }
    }
    if(a != b)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    cout << s;
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
