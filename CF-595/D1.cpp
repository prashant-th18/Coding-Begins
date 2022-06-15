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
        int n, k; cin >> n >> k;
        vector<bool> vis(n, true);
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].ff >> v[i].ss;
        }
        set<int> br;
        while(true) {
            vector<int> cnt(n, 0);
            for(int i = 1; i <= 200; ++i) {
                int c = 0;
                for (int j = 0; j < n; j++) {
                    if(vis[j] == false) continue;
                    if(v[j].ff <= i && i <= v[j].ss) ++c;
                }
                if(c > k) {
                    for (int j = 0; j < n; j++) {
                        if(!vis[j]) continue;
                        if(v[j].ff <= i && i <= v[j].ss) cnt[j]++;
                    }
                }
            }
            vector<int> cl;
            for (int i = 0; i < n; i++) {
                if(cnt[i]) cl.push_back(i);
            }
            auto f = [&](int in1, int in2) {
                if(cnt[in1] != cnt[in2]) return cnt[in1] > cnt[in2];
                return (v[in1].ss - v[in1].ff) > (v[in2].ss - v[in2].ff);
            };
            sort(cl.begin(), cl.end(), f);
            if(sz(cl) == 0) break;
            else {
                br.insert(cl[0]);
                vis[cl[0]] = false;
            }
        }
        auto it = br.begin();
        while(it != br.end()) {
            int temp = *it;
            vis[temp] = true;
            for(int i = 1; i <= 200; ++i) {
                int c = 0;
                for(int j = 0; j < n; ++j) {
                    if(vis[j] && v[j].ff <= i && i <= v[j].ss) ++c;
                }
                if(c > k) {
                    vis[temp] = false; ++it; break;
                }
            }
            if(vis[temp] == false) continue;
            br.erase(it);
            it = br.begin();
        }
        cout << sz(br) << '\n';
        for(auto val : br) cout << val + 1 << ' ';
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
