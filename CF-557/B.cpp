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
        vector<vector<int>> a(n, vector<int>(m, 0));
        auto b = a;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> b[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(a[i][j] > b[i][j]) swap(a[i][j], b[i][j]);   
            }
        }
        for(int i = 0; i < n; ++i)
        {
            for(int j = 1; j < m; ++j)
            {
                if(a[i][j] <= a[i][j - 1] || b[i][j] <= b[i][j - 1])
                {
                    cout << "Impossible"; return 0;
                }
            }
        }
        for(int j = 0; j < m; ++j)
        {
            for(int i = 1; i < n; ++i)
            {
                if(a[i][j] <= a[i - 1][j] || b[i][j] <= b[i - 1][j])
                {
                    cout << "Impossible"; return 0;
                }
            }
        }
        cout << "Possible";
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
