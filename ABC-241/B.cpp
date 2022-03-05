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
        int n, m; cin >> n >> m;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int t; cin >> t; mp[t]++;
        }
        for (int i = 0; i < m; i++) {
            int t; cin >> t;
            if(mp[t] == 0)
            {
                cout << "No"; return 0;
            }
            else
            {
                --mp[t];
            }
        }
        cout << "Yes";
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
