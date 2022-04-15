#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    auto get = [&](int index)
    {
        ll maxx = -1;
        ll sum = 0;
        for(int i = 0; i < index; ++i)
        {
            maxx = max(maxx, v[i]);
            sum += v[i];
        }
        return make_pair(maxx, sum);
    };
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, INT_MAX));
    for(int i = 0; i <= n; ++i)
    {
        for(int j = 0; j <= k; ++j)
        {
            if(i == 0) dp[i][j] = 0;
            else if(j == 0)
            {
                auto [maxx, sum] = get(i);
                dp[i][j] = min(dp[i][j], i * maxx - sum);
            }
            else
            {
                ll maxx = -1, sum = 0;
                for(int z = i; z >= 1; --z)
                {
                    maxx = max(maxx, v[z - 1]);
                    sum += v[z - 1];
                    dp[i][j] = min(dp[i][j], (i - z + 1) * maxx - sum + dp[z - 1][j - 1]);
                }
            }
        }
    }
    cout << dp[n][k];
    return 0;
}
