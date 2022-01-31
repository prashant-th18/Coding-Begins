#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
// *-> KISS*

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

int32_t main() {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x; cin >> n >> x;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    vector<vector<ll>> dp(x + 1, vector<ll>(n + 1, INT_MAX));
    auto fun = y_combinator([&](auto f, int index, ll sum) -> ll
    {
         if(sum == 0) return 0;
         else if(index < 0) return -2;
         else if(dp[sum][index] != INT_MAX) return dp[sum][index];

         ll fact = sum / v[index];
         for(int i = 0; i <= fact; ++i)
         {
            // i + f(index - 1, sum - v[index]*i)
            ll tt = f(index - 1, sum - v[index] * i);
            if(tt != -2) tt += i;
            else continue;
            dp[sum][index] = min(dp[sum][index], tt);
         }
         if(dp[sum][index] == INT_MAX) dp[sum][index] = -2;
         return dp[sum][index];
    });
    cout << ((fun(sz(v) - 1, x) == -2) ? (-1) : (dp[x][sz(v) - 1]));
    return 0;
}
// -> Keep It Simple Stupid!
