#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<array<bool, 2>> dp(n, {false, false});
    dp[0] = {true, true};
    for(int i = 1; i < n; ++i) {
        if(abs(a[i] - a[i - 1]) <= k) dp[i][0] |= dp[i - 1][0];
        if(abs(a[i] - b[i - 1]) <= k) dp[i][0] |= dp[i - 1][1];
        if(abs(b[i] - a[i - 1]) <= k) dp[i][1] |= dp[i - 1][0];
        if(abs(b[i] - b[i - 1]) <= k) dp[i][1] |= dp[i - 1][1];
    }
    if(dp[n - 1][0] || dp[n - 1][1]) cout << "Yes";
    else cout << "No";
    return 0;
}
