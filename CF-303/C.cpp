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

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
// use -> auto gcd = y_combinator([](auto gcd, int a, int b) -> int { return b == 0 ? a : gcd(b, a % b);});

// *-> KISS*
int solve() {
    ll n; cin >> n;
    vector<array<ll, 2>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    vector<array<ll, 3>> dp(n, {-1, -1, -1});
    auto fun = y_combinator([&](auto f, int index, ll right = LLONG_MAX) -> ll
    {
        if(index < 0) return 0;
        
        if(index == 0) return 1;
        ll maxx = 0;
        // left, -, right
        // left
        if(v[index][0] - v[index][1] > v[index - 1][0])
        {
            if(dp[index][0] != -1) maxx = max(maxx, dp[index][0]);
            else
            {
                dp[index][0] = 1 + f(index - 1, v[index][0] - v[index][1]);
                maxx = max(maxx, dp[index][0]);
            }
        }
        
        // -
        if(dp[index][1] != -1) maxx = max(maxx, dp[index][1]);
        else
        {
            dp[index][1] = f(index - 1, v[index][0]);
            maxx = max(maxx, dp[index][1]);
        }

        // right
        if(v[index][0] + v[index][1] < right)
        {
            if(dp[index][2] != -1) maxx = max(maxx, dp[index][2]);
            else
            {
                dp[index][2] = 1 + f(index - 1, v[index][0]);
                maxx = max(maxx, dp[index][2]);
            }
        }
        return maxx;
    });
    cout << fun(n - 1);
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