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

int N = 5005;
int32_t main() {
    string a, b; cin >> a >> b;
    // Top-Down Approach
    vector<vector<int>> dp(N, vector<int>(N, -1));
    auto fun = y_combinator([&](auto f, int i, int j) -> int // i is for string "a", j is for string "b"
    {
        if(i == sz(a) || j == sz(b))
        {
            return max(sz(b) - j, sz(a) - i);
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int mini = 1e9;
        if(a[i] == b[j])
        {
            mini = f(i + 1, j + 1); // Same characters
        }
        int op1 = 1 + f(i, j + 1); // Insert
        int op2 = 1 + f(i + 1, j); // Delete
        int op3 = 1 + f(i + 1, j + 1); // Replace
        return dp[i][j] = min({mini, op1, op2, op3});
    });
    cout << fun(0, 0);
    return 0;
}
// -> Keep It Simple Stupid!
