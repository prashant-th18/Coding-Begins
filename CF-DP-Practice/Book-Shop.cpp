#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, x; cin >> n >> x;
    vector<int> h(n), s(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < x + 1; j++) {
            int op1 = ((i == 0) ? (0) : (dp[i - 1][j]));
            int op2 = 0;
            if(j >= h[i])
            {
                if(i == 0) op2 = s[i];
                else op2 = dp[i - 1][j - h[i]] + s[i];
            }
            dp[i][j] = max(op1, op2);
        }
    }
    cout << dp[n - 1][x];
    return 0;
}
