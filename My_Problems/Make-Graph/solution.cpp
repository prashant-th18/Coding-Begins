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
        int k; cin >> k;
        if(k == 1)
        {
            cout << "NO"; return 0;
        }
        int nodes = k + 1;
        vector<pair<int, int>> ans;
        for(int i = 1; i <= nodes - 1; ++i)
        {
            for(int j = i + 1; j <= nodes; ++j)
            {
                ans.push_back({i, j});
            }
        }
        cout << "yES\n";
        cout << nodes << ' ' << sz(ans) << '\n';
        for(auto [x, y] : ans)
        {   
            cout << x << ' ' << y << '\n';
        }
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
