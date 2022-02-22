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
    cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        int n; cin >> n;
        map<int, string> mp;
        mp[1] = mp[2] = mp[3] = mp[5] = mp[7] = mp[8] = mp[9] = "Bob";
        mp[4] = mp[6] = "Alice";
        if(n <= 9)
        {
            cout << mp[n];    
        }
        else if(__builtin_popcountll(n) == 1)
        {
            if((int)log2(n) & 1)
            cout << "Bob";
            else cout << "Alice";
        }
        else if(n & 1) cout << "Bob";
        else cout << "Alice";
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
