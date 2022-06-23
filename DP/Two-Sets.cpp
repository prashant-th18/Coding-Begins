/*

DP State -> dp(i, j) : ways to form x using first i natural numbers {1, 2, 3, ... , i}

So, if two sets are having the same sum and they both in total include all natural numbers till "n", then
What is the sum of each set ->
2 * (Sum of each set) = n * (n + 1) / 2

=> Sum of each set = n * (n + 1) / 4  { S }

Answer -> dp(n, S) / 2 ( Why divide? => Because our dp is calculating each set twice )

Base Case -> 
dp(0, 0) = 1
dp(0, x) = 0 ( where x != 0 )

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
template<typename T>
T binexp(T a, T b) {
    T ans = 1;
    while (b) {
        if (b & 1) {
            ans = 1LL * ans * a % MOD;
        }
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return ans;
}
int modinv(int num) {
    return binexp(num, MOD - 2);
}
int32_t main() {
    int n; cin >> n; // Total Natural numbers starting from 1
    int sum = n * (n + 1) / 2;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    // Base Case
    dp[0][0] = 1;
    for(int i = 1; i <= sum; ++i) dp[0][i] = 0;

    for(int i = 1; i <= n; ++i) {
        for(int x = 0; x <= sum; ++x) {
            int op1 = (dp[i - 1][x]); // Ways of forming sum x from first "i - 1" natural numbers
            int op2 = (x >= i) ? (dp[i - 1][x - i]) : (0); // Ways of forming sum "x - i" using first "i - 1" natural numbers 
            dp[i][x] = (op1 + op2) % MOD;
        }
    }
    if(sum & 1) {
        // Sum if not divisible by 4, therefore, we can never divide into two sets
        cout << 0;
    }
    else {
        cout << (dp[n][sum / 2] * modinv(2)) % MOD;
    }
    return 0;
}
