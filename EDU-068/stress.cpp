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
        int n, k; cin >> n >> k;
        map<int, bool> mp;
        mp[0] = true; // Bob
        mp[1] = mp[2] = false;
        for(int i = 3; i <= n; ++i)
        {
            if(mp[i - 1] || mp[i - 2] || (i >= k && (mp[i - k]))) mp[i] = false;
            else mp[i] = true;
        }
        for(auto val : mp)
        {
            cout << val.ff << " -> " << val.ss << endl;
        }
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
