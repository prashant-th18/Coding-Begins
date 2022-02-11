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
        vector<array<ll, 2>> v(3);
        cin >> v[0][0] >> v[0][1] >> v[1][0] >> v[1][1] >> v[2][0] >> v[2][1];
        sort(v.begin(), v.end(), [&](array<ll, 2> a, array<ll, 2> b)
                {
                    if(a[0] != b[0]) return a[0] < b[0];
                    return a[1] < b[1];
                });
        set<pair<int, int>> ans;
        while(v[0][0] < v[1][0])
        {
            ans.insert({v[0][0], v[0][1]});
            v[0][0]++;
        }
        while(v[2][0] > v[1][0])
        {
            ans.insert({v[2][0], v[2][1]});
            --v[2][0];
        }
        auto reach = [&](int y, int dy) -> void
        {
              if(dy < y) swap(y, dy);
              while(y <= dy)
              {
                  ans.insert({v[1][0], y});
                  ++y;
              }
        };
        reach(v[0][1], v[1][1]);
        reach(v[2][1], v[1][1]);
        cout << sz(ans) << '\n';
        for(auto [x, y] : ans) cout << x << ' ' << y << '\n';
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
