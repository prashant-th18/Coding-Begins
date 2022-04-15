#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<int> dp(x + 1, 1000000000);
    dp[0] = 0;
    for(int i = 1; i <= x; ++i)
    {
        for(auto& c : v)
        {
            if(i - c < 0) break;
            dp[i] = min(dp[i], 1 + dp[i - c]);
        }
    }
    cout << ((dp[x] == 1000000000) ? (-1) : (dp[x]));
    return 0;
}
