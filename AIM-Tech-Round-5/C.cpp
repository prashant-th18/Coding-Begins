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
        int n; cin >> n;
        vector<array<ll, 4>> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3];
        }
        // O(N ^ 2)
        for (int i = 0; i < n; i++) {
           vector<pair<ll, ll>> temp = {{v[i][0], v[i][1]}, {v[i][0], v[i][3]}, {v[i][2], v[i][1]}, {v[i][2], v[i][3]}};
            for(auto [x, y] : temp)
           {
                int c = 0;
                for (int j = 0; j < n; j++) {
                if(v[j][0] <= x && x <= v[j][2] && v[j][1] <= y && y <= v[j][3])
                {
                    ++c;    
                }
            }
            if(c >= n - 1)
            {
                cout << x << ' ' << y; return 0;
            }
        }
    }
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
