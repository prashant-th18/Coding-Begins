#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> dp(x + 1);
    dp[0] = 1; // Only Way to make a empty subset
    for(int i = 1; i <= x; ++i)
    {
        for(auto& c : v)
        {
            if(i - c >= 0)
            {
                dp[i] += dp[i - c];
                dp[i] %= (1000000007);
            }
        }
    }
    cout << dp[x];
    return 0;
}
