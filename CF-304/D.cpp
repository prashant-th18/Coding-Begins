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

const int N = 5000001;
vector<int> spf(N, -1);
vector<int> pre(N, 0);
void calc()
{
    for(ll i = 2; i * i < N; ++i)
    {
        if(spf[i] == -1)
        {
            for(ll j = i * i; j < N; j += i)
            {
                spf[j] = i;
            }
        }
    }
}
void init()
{
    for(ll i = 2; i < N; ++i)
    {
        pre[i] += pre[i - 1];
        ll temp = i;
        while(spf[temp] != -1)
        {
            ll num = spf[temp];
            int c = 0;
            while(temp % num == 0) temp /= num, ++c;
            pre[i] += c;
        }
        if(temp != 1)
        {
            pre[i]++;
        }
    }
}
// *-> KISS*
int solve() {
    int a, b; cin >> a >> b;
    cout << pre[a] - pre[b];
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    cin >> TET;
    cout << fixed << setprecision(6);
    calc();
    init();
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
