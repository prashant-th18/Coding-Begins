#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) (int)x.size()
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(26));
        map<pair<int, int>, vector<int>> mp;
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            dp[0][v[i][0] - 97].push_back(i);
            dp[1][v[i][1] - 97].push_back(i);
            mp[pair(v[i][0] - 97, v[i][1] - 97)].push_back(i);
        }
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            vector<int>& uni = mp[pair(v[i][0] - 97, v[i][1] - 97)];
            ll tot = upper_bound(begin(uni), end(uni), i) - begin(uni);
            tot = sz(uni) - tot;
            vector<int> &f = dp[0][v[i][0] - 97];
            ll how1 = upper_bound(begin(f), end(f), i) - begin(f);
            how1 = sz(f) - how1;
            cnt += abs(tot - how1);
            vector<int>& s = dp[1][v[i][1] - 97];
            ll how2 = upper_bound(begin(s), end(s), i) - begin(s);
            how2 = sz(s) - how2;
            cnt += abs(tot - how2);
        }
        cout << cnt << '\n';
    }
    return 0;
}
