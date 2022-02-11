#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
// *-> KISS*
const int MOD = 1e9 + 7;

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
    int n; cin >> n;
    int x; cin >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    /*
    auto fun = y_combinator([&](auto f, int index, int sum) -> int
    {
        if(sum == 0) return 1;
        if(sum < 0 || index < 0) return 0;
        if(dp[index][sum] != -1) return dp[index][sum];
        // You have index + 1 coins and you need to make a total of "sum" using them
        // SO
        // Either, I can make "sum" using index coins ( Means Excluding the coin at index `index`)
        // OR I can make "sum - v[index]" using index + 1 coins ( Means I am taking the coin at index `index`)
        int one = f(index - 1, sum);
        int two = f(index, sum - v[index]);
        dp[index][sum] = (one % MOD + two % MOD) % MOD;
        // dp[i][x] tells about the number of valid ways to get sum x using coins C1, C2, ... Ci
        return dp[index][sum];
    });
    cout << fun(n - 1, x);
    */
    // Top-Down Approach Is not working at all ( TLE )!
    
    // Bottom-Up Approach
    for(int i = 0; i < n; ++i)
    {
        // i tells me how many coins to use -> [0, i]
        for(int sum = 0; sum <= x; ++sum)
        {
            if(sum == 0)
            dp[i][sum] = 1;
            else
            {
                int op1 = (v[i] > sum) ? (0) : dp[i][sum - v[i]];
                int op2 = (i == 0) ? (0) : dp[i - 1][sum];
                dp[i][sum] = (op1 + op2) % MOD;
            }
        }
    }
    cout << dp[n - 1][x];
    return 0;
}
// -> Keep It Simple Stupid!
