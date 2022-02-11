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
        int n, p, k; cin >> n >> k >> p;
        vector<array<int, 2>> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i][0];
            v[i][1] = i;
        }
        sort(v.begin(), v.end());
        vector<int> pos(n, 0);
        vector<int> vis(n, false);
        int index = -1;
        auto f = [&](int num) -> void
        {
            ++index;
            vis[num] = true;
            pos[v[num][1]] = index;
            int maxx = v[num][0] + k;
            for(int i = num + 1; i < n; ++i)
            {
                if(v[i][0] <= maxx)
                {
                    vis[i] = true;
                    maxx = v[i][0] + k;
                    pos[v[i][1]] = index;
                }
                else break;
            }
        };
        for(int i = 0; i < n; ++i)
        {
            if(!vis[i])
            {
                f(i);
            }
        }
        while(p--)
        {
            int a, b; cin >> a >> b;
            --a; --b;
            if(pos[a] == pos[b]) cout << "Yes";
            else cout << "No";
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
