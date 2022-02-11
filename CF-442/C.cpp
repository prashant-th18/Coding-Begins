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
        int n; cin >> n;
        if(n == 2) cout << "3\n2 1 2";
        else
        {
            vector<int> ans;
            for(int i = 2; i <= n; i += 2) ans.push_back(i);
            for(int i = 1; i <= n; i += 2) ans.push_back(i);
            for(int i = 2; i <= n; i += 2) ans.push_back(i);
            cout << sz(ans) << '\n';
            for(auto val : ans) cout << val << ' ';
        }
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
