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
    int n; cin >> n; int cnt = 0;
    vector<int> v(n);
    iota(all(v), 1);
    do {
        bool flag = true;
        for(int i = 2; i < n; ++i)
        {
            if(v[i] == v[i - 1] + v[i - 2])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            ++cnt;
        }
        
    } while (next_permutation(all(v)));
    cout << cnt;
    /*
    vector<int> v(n);
    iota(all(v), 1);
    reverse(all(v));
    for (int i = 0; i < n; i++) {
        for(auto val : v)
        {
            cout << val << ' ';
        }
        cout << '\n';
        if(i != n - 1)
        swap(v[0], v[i + 1]);
    }
    */
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