#include<bits/stdc++.h>
using namespace std;
int main() {
    ios :: sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = n - 1; i >= 0; --i) {
            for(int j = m - 1; j >= 0; --j) {
                int op1 = (i + 1 < n) ? (dp[i + 1][j]) : (0);
                int op2 = (i + 1 < n && j + 1 < m) ? (dp[i + 1][j + 1]) : (0);
                int op3 = (i + 1 < n && j - 1 >= 0) ? (dp[i + 1][j - 1]) : (0);
                dp[i][j] = v[i][j] + max({op1, op2, op3});
            }
        }
        cout << *max_element(begin(dp[0]), end(dp[0])) << '\n';
    }
    return 0;
}
