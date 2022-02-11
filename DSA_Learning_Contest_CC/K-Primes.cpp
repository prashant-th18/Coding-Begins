#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    cin >> test;
    int N = 1e5 + 1;
    vector<int> v(N, -1); // -1 means the number is prime, otherwise v[i] will be the spf of that number
    for(int i = 2; i * i < N; ++i)
    {
        if(v[i] == -1)
        {
            // Okay, so a prime number is encountered
            for(int j = i * i; j < N; j += i)
            {
                if(v[j] == -1) v[j] = i;
            }
        }
    }
    auto factor = [&](int num) -> int
    {
        int c = 0;
        while(v[num] != -1)
        {
            ++c;
            int pr = v[num];
            while(num % pr == 0) num /= pr;
        }
        if(num != 1) ++c;
        return c;
    };
    vector<array<ll, 5>> dp(N, {0, 0, 0, 0, 0});
    for(ll i = 2; i < N; ++i)
    {
        int num = factor(i);
        int a = 0, b = 0, c = 0, d = 0, e = 0;
        if(num == 1) a = 1;
        else if(num == 2) b = 1;
        else if(num == 3) c = 1;
        else if(num == 4) d = 1;
        else if(num == 5) e = 1;
        dp[i][0] = dp[i - 1][0] + a; dp[i][1] = dp[i - 1][1] + b; dp[i][2] = dp[i - 1][2] + c; dp[i][3] = dp[i - 1][3] + d;
        dp[i][4] = dp[i - 1][4] + e;
    }
    for(int t_ = 0; t_ < test; t_++)
    {
        int a, b, k; cin >> a >> b >> k;
        --a; --k;
        cout << dp[b][k] - dp[a][k];
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
