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
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    // Binary Search
    ll si = 0, ei = n - 1, ans = 0;
    while(si <= ei)
    {
        int mid = (si + ei) / 2;
        int temp = k;
        bool flag = false;
        ll extra = 0;
        for(int j = mid; j >= 0; --j)
        {
            int num = (s[j] - '0' + extra) % 10;
            if(num == 0)
            {
                continue;
            }
            else
            {
                int diff = 10 - num;
                if(temp >= diff)
                {
                    temp -= diff;
                    extra += diff;
                }
                else
                {
                    flag = true; break;
                }
            }
        }
        if(flag)
        {
            ei = mid - 1;
        }
        else
        {
            ans = mid + 1;
            si = mid + 1;
        }
    }
    cout << ans;
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
