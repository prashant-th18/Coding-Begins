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
        vector<int> v(n);
        for (int &val : v) {
            cin >> val;
        }
        vector<int> comp(m + 1);
        for (int i = 0; i < m; i++) {
            cin >> comp[i + 1];
        }
        int s = accumulate(all(comp), 0);
        for(int i = 0; i <= n - s; ++i)
        {
            vector<int> cnt(m + 1);
            for(int j = i; j < i + s; ++j) cnt[v[j]]++;
            if(comp == cnt)
            {
                cout << "YES"; return 0;
            }
        }
        cout << "NO";
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
