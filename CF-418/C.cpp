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
    string s; cin >> s;
    vector<vector<int>> chars(26);
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < n; j++) {
            if((s[j] - 97) != i)
            {
                chars[i].push_back(j);
            }
        }
    }
    vector<vector<int>> prefix(26, vector<int>(n + 2, 0));
    auto suffix = prefix;
    for (int i = 0; i < 26; i++) {
        for(int j = 0; j < n; ++j)
        {
            if(s[j] - 97 == i)
            {
                prefix[i][j + 1] = 1 + prefix[i][j];
            }
            else
            {
                prefix[i][j + 1] = 0;
            }
        }
        for(int j = n - 1; j >= 0; --j)
        {
            if(s[j] - 97 == i)
            {
                suffix[i][j + 1] = 1 + suffix[i][j + 2];
            }
            else
            {
                suffix[i][j + 1] = 0;
            }
        }
    }
    vector<vector<int>> pre(26, vector<int>(n + 2, 0));
    int q; cin >> q;
    for(int occ = 1; occ <= n; ++occ)
    {
        for(int i = 0; i < 26; ++i)
        {
            auto& v = chars[i];
            if(sz(v) <= occ)
            {
                pre[i][occ] = n;
            }
            else
            {
                for(int j = 0; j < sz(v) - occ + 1; ++j)
                {
                    assert(j + occ - 1 < sz(v));
                    assert(v[j + occ -1] + 2 < n + 2);
                    int how_many = v[j + occ - 1] - v[j] + 1 + prefix[i][v[j]] + suffix[i][v[j + occ - 1] + 2];
                    pre[i][occ] = max(pre[i][occ], how_many);
                }
            }
        }
    }
    while(q--)
    {
        int how; cin >> how; char ch; cin >> ch;
        // Use Precomputed
        cout << pre[ch - 97][how] << '\n';
    }
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
