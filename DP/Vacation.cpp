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
    vector<array<ll, 3>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    /*
    vector<vector<ll>> dp(n + 1, vector<ll>(4, -1));
    auto fun = y_combinator([&](auto f, int index, int pre = 3) -> ll
    {
        if(index < 0) return 0;

        if(dp[index][pre] != -1) return dp[index][pre];

        for (int i = 0; i < 3; i++) {
            if(i == pre) continue;
            dp[index][pre] = max(dp[index][pre], v[index][i] + f(index - 1, i));
        }
        return dp[index][pre];
    });
    cout << fun(n - 1);
    */
    vector<vector<ll>> dp(n, vector<ll>(3, 0));
    for (int i = 0; i < n; i++) {
        if(i == 0)
        {
            dp[i][0] = v[i][0];
            dp[i][1] = v[i][1];
            dp[i][2] = v[i][2];
        }
        else
        {
            dp[i][0] = v[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = v[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = v[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
        }
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
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
