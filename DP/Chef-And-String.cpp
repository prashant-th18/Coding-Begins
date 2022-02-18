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
        int n = sz(s);
        map<char, int> mp;
        int cnt = 0;
        mp['C'] = mp['H'] = mp['E'] = 0;
        for (int i = 0; i < n; i++) {
            if(s[i] == 'C')
            {
                mp[s[i]]++;
            }
            else if(s[i] == 'H')
            {
                if(mp[s[i]] + 1 <= mp['C']) ++mp[s[i]];
            }
            else if(s[i] == 'E')
            {
                if(mp[s[i]] + 1 <= mp['H']) ++mp[s[i]];
            }
            else
            {
                if(mp['E'] > 0)
                {
                    --mp['E']; --mp['H']; --mp['C'];
                    ++cnt;
                }
            }
        }
        cout << cnt;
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
