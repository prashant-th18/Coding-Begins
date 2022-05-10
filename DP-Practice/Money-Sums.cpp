#include<bits/stdc++.h>
using namespace std;
const int N = 100001;
int main()
{
    int n; cin >> n;
    vector<int> v(n), ans;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // Till index "i", is it possible to make sum = "j"
    vector<vector<bool>> dp(n, vector<bool>(N, false));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(j == 0) dp[i][j] = true;
            else
            {
                bool op1 = (i == 0) ? (false) : (dp[i - 1][j]);
                bool op2 = false;
                if(j >= v[i])
                {
                    if(i == 0) op2 = (j == v[i]);
                    else op2 = dp[i - 1][j - v[i]];
                }
                dp[i][j] = (op1 | op2);
            }
            if(dp[i][j] && j != 0)
            {
                ans.push_back(j);
            }
        }
    }
    sort(begin(ans), end(ans));
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    cout << ans.size() << '\n';
    for(auto val : ans) cout << val << ' ';
    return 0;
}
