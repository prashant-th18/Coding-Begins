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
        int n, m, k; cin >> n >> m >> k;
        vector<int> cycles(n, 0);
        vector<vector<int>> v(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }
        vector<bool> locked(k + 1, false);
        for (int j = 0; j < m; j++) {
            vector<vector<int>> temp(k + 1);
            for (int i = 0; i < n; i++) {
                if(v[i][j] == 0 || cycles[i] != 0) continue;
                else 
                {
                    if(locked[v[i][j]])
                    {
                        cycles[i] = j + 1;
                    }
                    else
                    {
                        temp[v[i][j]].push_back(i);
                    }
                }
            }
            for (int z = 0; z < k + 1; z++) {
                if(!locked[z] && sz(temp[z]) > 1)
                {
                    locked[z] = true;
                    for(const auto& val : temp[z])
                    {
                        cycles[val] = j + 1;
                    }
                }
            }
        }
        for(auto val : cycles) cout << val << '\n';
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
