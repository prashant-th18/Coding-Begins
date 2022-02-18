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
        vector<vector<char>> v(n, vector<char>(n, '.'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }
        vector<vector<bool>> column(n, vector<bool>(n, false)), row(n, vector<bool>(n, false));
        for(int i = n - 1; i >= 0; --i)
        {
            for(int j = n - 1; j >= 0; --j)
            {
                if(j == n - 1)
                {
                    column[i][j] = (v[i][j] == '.');
                }
                else
                {
                    column[i][j] = column[i][j + 1] && (v[i][j] == '.');
                }
            }
        }
        for(int j = n - 1; j >= 0; --j)
        {
            for(int i = n - 1; i >= 0; --i)
            {
                if(i == n - 1)
                {
                    row[i][j] = (v[i][j] == '.');
                }
                else
                {
                    row[i][j] = row[i + 1][j] && (v[i][j] == '.');
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cnt += row[i][j] && column[i][j];
            }
        }
        cout << cnt;
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
