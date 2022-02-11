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
        n *= 2;
        bool flag = false;
        vector<int> cnt(n / 2 + 1);
        for (int i = 0; i < n; i++) {
            int t; cin >> t;
            cnt[t]++;
        }
        for(int i = 0; i <= n; ++i)
        {
            if(cnt[i] == 0)
            {
                flag = true; break;
            }
            else if(cnt[i] == 1)
            {
                break;
            }
        }
        if(flag) cout << "YES";
        else cout << "NO";
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
