#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include "bits/stdc++.h"
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
const int MOD = 1000000007;
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

vector<string> v;
// *-> KISS*
int solve() {
    int n; cin >> n;
    v.assign(n, string(n, '.'));
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
    auto get = [&](int i, int j) -> string {
        string maxx = "";
        for (int k = 0; k < 8; k++) {
            string res = "";
            int c = 0;
            while(c < n) {
                res += v[i][j];
                i = (i + dx[k] + n) % n;
                j = (j + dy[k] + n) % n;
                ++c;
            }
            maxx = max(maxx, res);
        }  
        return maxx;
    };
    string m = "";
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            m = max(m, get(i, j));
        }
    }
    cout << m;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = false;;
    int TET = 1;
    if(test) cin >> TET;
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
