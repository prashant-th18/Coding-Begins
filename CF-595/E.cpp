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
    // It's DP! :(
    ll n, c; cin >> n >> c;
    vector<ll> a(n - 1), b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    vector<ll> pre1(n), pre2(n);
    for (int i = 0; i < n - 1; i++) {
        pre1[i + 1] = pre1[i] + a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        pre2[i + 1] = pre2[i] + b[i];
    }
    vector<ll> help(n);
    vector<ll> ans;
    bool up = false;
    for(int i = 1; i <= n - 1; ++i)
    {
        if(up)
        {
            if(a[i - 1] < b[i - 1] + c)
            {
                help[i] = help[i - 1] + a[i - 1];
            }
            else
            {
                // I want to go down from (i - 2) -> (i - 1)
                ll oneway = help[i - 1] + c;
                ll twoway = help[ans.back()] + pre2[i - 1] - pre2[ans.back()];
                ans.pop_back();
                up = false;
                if(oneway < twoway)
                {
                    help[i] = oneway + b[i - 1];
                }
                else
                {
                    help[i] = twoway + b[i - 1];
                }
            }
        }
        else
        {
            if((i == 1) ? (a[i - 1] < b[i - 1] + c) : (a[i - 1] < b[i - 1]))
            {
                help[i] = help[i - 1] + a[i - 1];
                up = true; ans.push_back(i - 1);
            }
            else
            {
                help[i] = help[i - 1] + b[i - 1];
                if(i == 1)
                {
                    help[i] += c;
                }
            }
        }
    }
    for(auto val : help) cout << val << ' ';
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
