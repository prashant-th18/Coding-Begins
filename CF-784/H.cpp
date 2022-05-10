#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> dp(31, 0);
        for (int i = 0; i < n; i++) {
            int z; cin >> z;
            for(int j = 0; j <= 30; ++j) {
                dp[j] += ((z >> j) & 1);
            }
        }
        for(int i = 30; i >= 0; --i) {
            int rem = n - dp[i];
            if(k >= rem) {
                k -= rem;
                dp[i] = n;
            }
        }
        int ans = 0;
        for(int i = 0; i < 31; ++i) {
            if(dp[i] == n) {
                ans += (1 << i);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
