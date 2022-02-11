#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        string s, t; cin >> s >> t;
        int n = sz(s), m = sz(t);
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = n; i >= 0; --i)
        {
            for(int j = m; j >= 0; --j)
            {
                if(i == n || j == m)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    int one = dp[i + 1][j + 1] + (s[i] == t[j]);
                    int two = dp[i + 1][j];
                    int three = dp[i][j + 1];
                    dp[i][j] = max({one, two, three});
                }
            }
        }
        //cout << dp[0][0];
        int i = 0, j = 0;
        string res = "";
        while(i < n && j < m)
        {
            if(s[i] == t[j])
            {
                res += s[i];
                ++i, ++j;
            }
            else
            {
                int maxx = max({dp[i + 1][j + 1], dp[i + 1][j], dp[i][j + 1]});
                if(dp[i + 1][j + 1] == maxx)
                {
                    ++i, ++j;
                }
                else if(dp[i + 1][j] == maxx)
                {
                    ++i;
                }
                else ++j;
            }
        }
        cout << res;
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
