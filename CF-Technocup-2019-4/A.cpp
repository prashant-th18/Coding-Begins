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
        string s; cin >> s;
        string res = string(sz(s), '.');
        int i = sz(s) - 1;
        int si = 0, ei = i;
        bool flag = (sz(s) & 1) ? (true) : (false);
        while(i >= 0)
        {
            if(flag)
            {
                res[i--] = s[si++];
            }
            else
            {
                res[i--] = s[ei--];
            }
            flag = !flag;
        }
        cout << res;
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
