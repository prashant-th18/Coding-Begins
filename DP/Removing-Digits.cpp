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
    int n; cin >> n;
    /*
    vector<ll> dp(n + 1, -1);
    auto fun = y_combinator([&](auto f, int num) -> ll
    {
       if(num == 0) return 0;

       if(dp[num] != -1) return dp[num];

        int number = num;
        deque<int> dq;
        while(number)
        {
            if(number % 10 != 0) dq.push_back(number % 10);
            number /= 10;
        }
        ll minn = LLONG_MAX;
        while(sz(dq))
        {
            minn = min(minn, 1 + f(num - dq.back()));
            dq.pop_back();
        }
        return dp[num] = minn;
    });
    cout << fun(n);
    */
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    for(int i = 1; i <= n; ++i)
    {
        int temp = i;
        int minSteps = 1e9;
        while(temp)
        {
            int rem = temp % 10;
            temp /= 10;
            if(rem == 0) continue;
            minSteps = min(minSteps, 1 + dp[i - rem]);
        }
        dp[i] = minSteps;
    }
    cout << dp[n];
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
