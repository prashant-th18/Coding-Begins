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
    cout << fixed << setprecision(9);
    //cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        string s; cin >> s;
        int n = sz(s);
        auto inc = [&](int index) -> int 
        {
            return (index + 1) % n;
        };
        vector<vector<pair<vector<char>, int>>> chars(26);
        for(int i = 0; i < n; ++i)
        {
            int j = inc(i);
            int c = 0;
            vector<char> temp(n - 1, '.');
            while(j != i)
            {
                temp[c] = s[j];
                ++c;
                j = inc(j);
            }
            chars[s[i] - 97].push_back({temp, i});
        }
        int maxx = 0, cnt = 0;
        for(int i = 0; i < 26; ++i)
        {
            maxx = 0;
            for(int j = 0; j < n - 1; ++j)
            {
                int ans = 0;
                vector<vector<int>> occ(26);
                for(int k = 0; k < sz(chars[i]); ++k)
                {
                    occ[chars[i][k].ff[j] - 97].push_back(chars[i][k].ss);
                }
                for (int k = 0; k < 26; k++) {
                    if(sz(occ[k]) == 1)
                    {
                        ++ans;
                    }
                }
                maxx = max(maxx, ans);
            }
            cnt += maxx;
        }
        cout << (long double)cnt / n;
        cout << '\n';
    }
    // bababbdaee
    return 0;
}
// -> Keep It Simple Stupid!
