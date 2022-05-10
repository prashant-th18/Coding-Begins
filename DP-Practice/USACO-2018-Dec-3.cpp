#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<ll> dp(n + 1, 0);
    for(int i = n - 1; i >= 0; --i)
    {
        ll till = v[i];
        for(int j = i; j <= min(n - 1, i + k - 1); ++j)
        {
            till = max(till, v[j]);
            dp[i] = max(dp[i], till * (j - i + 1) + dp[j + 1]);
        }
    }
    cout << dp[0];
}
