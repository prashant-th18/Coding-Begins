#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int MOD = (int)1e9 + 7;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<int> prefix(n + 1, 0);
    for(int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + v[i];
    }
    vector<pii> pairs(m);
    for(int i = 0; i < m ; ++i) {
        cin >> pairs[i].first >> pairs[i].second;
    }
    sort(pairs.begin(), pairs.end());
    vector<int> ans(k + 1, MOD);
    ans[0] = 0;
    for(int i = 1; i <= k; ++i) {
        ans[i] = prefix[i];
        for(int j = 0; j < m; ++j) {
            int pre = i - pairs[j].first;
            if(pre >= 0)
            {
                ans[i] = min(ans[i], ans[pre] + prefix[i] - prefix[pre + pairs[j].second]);
            }
        }
    }
    cout << ans[k];
    return 0;
}
