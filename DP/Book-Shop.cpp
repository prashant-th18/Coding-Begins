#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
// *-> KISS*
int32_t main() {
    int n; cin >> n;
    int x; cin >> x; // Total Amount of money I have
    vector<int> price(n), pages(n);
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    for(int i = 0; i < n; ++i)
    {
        for(int money = 0; money <= x; ++money)
        {
            if(money == 0)
            {
                dp[i][money] = 0;
            }
            else
            {
                int op1 = (i == 0) ? (0) : (dp[i - 1][money]);
                int op2 = (price[i] > money) ? (0) : (pages[i] + ((i == 0) ? (0) : (dp[i - 1][money - price[i]])));
                dp[i][money] = max(op1, op2);
            }
        }
    }
    cout << dp[n - 1][x];
    return 0;
}
// -> Keep It Simple Stupid!
