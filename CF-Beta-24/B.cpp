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
    int tt; cin >> tt;
    int x[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
    unordered_map<string, array<int, 51>> mp; // array[0] -> points, array[1] -> first win, array[2] -> second win
    for (int i = 0; i < tt; i++) {
        int n; cin >> n;
        for (int j = 0; j < n; j++) {
            string s; cin >> s;
            if(j < 10)
            {
                mp[s][0] += x[j];
            }
            mp[s][j + 1]++;
        }
    }
    vector<string> a1;
    for(const auto& val : mp) a1.push_back(val.ff);
    auto f1 = [&](string a, string b) -> bool
    {
          for(int i = 0; i < 51; ++i)
          {
              if(mp[a][i] != mp[b][i])
              {
                  return mp[a][i] > mp[b][i];
              }
          }
          return a < b;
    };
    sort(a1.begin(), a1.end(), f1);
    auto f2 = [&](string a, string b) -> bool
    {
        if(mp[a][1] != mp[b][1]) return mp[a][1] > mp[b][1];
        if(mp[a][0] != mp[b][0]) return mp[a][0] > mp[b][0];
        for(int i = 2; i < 51; ++i)
        {
            if(mp[a][i] != mp[b][i])
            {
                return mp[a][i] > mp[b][i];
            }
        }
        return a < b;
    };
    vector<string> a2 = a1;
    sort(a2.begin(), a2.end(), f2);
    cout << a1[0] << '\n' << a2[0];
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
}
// -> Keep It Simple Stupid!
