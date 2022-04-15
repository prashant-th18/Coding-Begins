#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = LLONG_MAX;
int main() {
    int n, m, q; cin >> n >> m >> q;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, MOD));
    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], c);
        dp[b][a] = min(dp[b][a], c);
    }
    for(int i = 1; i <= n; ++i) dp[i][i] = 0; // This caused me 4 WA 
    for(int k = 1; k <= n; ++k)
    {
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(dp[i][k] < MOD && dp[k][j] < MOD)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    while(q--)
    {
        int a, b; cin >> a >> b;
        cout << ((dp[a][b] >= MOD) ? (-1) : (dp[a][b])) << '\n';
    }
    return 0;
}
