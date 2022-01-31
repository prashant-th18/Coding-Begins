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
    int r, c, k; cin >> r >> c >> k;
    vector<vector<char>> v(r, vector<char>(c, '.'));
    int cnt = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
            if(v[i][j] == 'R') ++cnt;
        }
    }
    int rem = cnt % k;
    int temp_c = 0, cfc = 0;
    vector<char> ans;
    for(char ch = 'a'; ch <= 'z'; ++ch) ans.push_back(ch);
    for(char ch = 'A'; ch <= 'Z'; ++ch) ans.push_back(ch);
    for(char ch = '0'; ch <= '9'; ++ch) ans.push_back(ch);
    int j = 0, i = 0;
    auto f = [&](int in, int jn) -> void
    {
        char ch = v[in][jn];
        v[in][jn] = ans.back();
        if(ch == 'R')
        {
            ++temp_c;
            if(temp_c == cnt / k + (rem > 0))
            {
                --rem;
                temp_c = 0;
                ++cfc;
                if(cfc != k) ans.pop_back();
            }
        }
    };
    while(i < r)
    {
        if(i & 1)
        {
            while(j >= 0)
            {
               f(i, j);
               --j;
            }
            if(j == -1) ++i, j = 0;
        }
        else
        {
            while(j < c)
            {
                f(i, j);
                ++j;
            }
            if(j == c) j = c - 1, ++i;
        }
    }
    for (int ii = 0; ii < r; ii++) {
        for (int jj = 0; jj < c; jj++) {
            cout << v[ii][jj];
        }
        if(ii != r - 1) cout << '\n';
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
