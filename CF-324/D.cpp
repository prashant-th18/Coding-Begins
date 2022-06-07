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

bool prime(int num) {
    for(ll i = 2; i * i <= num; ++i) {
        if(num % i == 0) return false;
    }
    return true;
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<int> p;
    vector<vector<int>> l(1001);
    for(int i = 2; i < 1001; ++i) {
        if(prime(i)) l[i].push_back(i), p.push_back(i);
        else {
            int ind = -1, s = 4;
            int j = sz(p) - 1;
            while(j >= 0) {
                if(p[j] == i - 1) --j;
                else {
                    int rem = i - p[j];
                    if(sz(l[rem]) < s && sz(l[rem]) != 0) {
                        s = sz(l[rem]);
                        ind = j;
                    }
                    --j;
                }
            }
            l[i].push_back(p[ind]);
            int rem = i - p[ind];
            for(int k = 0; k < sz(l[rem]); ++k) l[i].push_back(l[rem][k]);
        }
    }
    for(int i = n, cnt = 0; i >= 0 && cnt < 1000; ++cnt, --i) {
        if(prime(i)) {
            if(i == n) {
                cout << 1 << '\n' << i; return 0;
            }
            else {
                int rem = n - i;
                if(sz(l[rem]) != 0 && sz(l[rem]) < 3) {
                    vector<int> temp = {i};
                    for(int k = 0; k < sz(l[rem]); ++k) {
                        temp.push_back(l[rem][k]);
                    }
                    cout << sz(temp) << '\n';
                    for(auto val : temp) cout << val << ' ';
                    return 0;
                }
            }
        }
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
