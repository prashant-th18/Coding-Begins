#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    int t, a, b; cin >> t >> a >> b;
    vector<vector<bool>> dp(2, vector<bool>(t + 1, false));
    dp[0][0] = true;
    for(int i = 0; i <= t; ++i) {
        if(i >= a) dp[0][i] |= dp[0][i - a];
        if(i >= b) dp[0][i] |= dp[0][i - b];
        dp[1][i / 2] |= dp[0][i];
    }
    for(int i = 0; i <= t; ++i) {
        if(i >= a) dp[1][i] |= dp[1][i - a];
        if(i >= b) dp[1][i] |= dp[1][i - b];
    }
    for(int i = t; i >= 0; --i) if(dp[1][i]) {
        cout << i; break;
    }
    return 0;
}
