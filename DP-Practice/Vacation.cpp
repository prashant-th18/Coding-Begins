#include<bits/stdc++.h>
using namespace std;
int main() {
    ios :: sync_with_stdio(0); cin.tie(nullptr);
    int c = 0;
    while(1) {
        string a, b;
        getline(cin, a);
        if(a == "#") break;
        getline(cin, b);
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = n; i >= 0; --i) {
            for(int j = m; j >= 0; --j) {
                if(i == n || j == m) dp[i][j] = 0;
                else {
                    if(a[i] == b[j]) {
                        dp[i][j] = 1 + dp[i + 1][j + 1];
                    }
                    else {
                        dp[i][j] = max({dp[i][j + 1], dp[i + 1][j]});
                    }
                }
            }
        }
        ++c;
        cout << "Case #" << c << ": you can visit at most " << dp[0][0] << " cities.\n";
    }
    return 0;
}
