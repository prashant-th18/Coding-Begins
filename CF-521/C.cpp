#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int main() {
    int n; cin >> n;
    vector<pii> v(n);
    ll sum {};
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        sum += v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end(), [&](pii a, pii b) {
        return a.first > b.first;
    });
    vector<int> ans;
    for(int i = 0; i < n; ++i) {
        ll temp = sum - v[i].first;
        if(i == 0)
        {
            if(temp - v[1].first == v[1].first) ans.push_back(v[i].second);
        }
        else
        {
            if(v[0].first == temp - v[0].first) ans.push_back(v[i].second);
        }
    }
    cout << ans.size() << '\n';
    for(auto val : ans) cout << val + 1 << ' ';
    return 0;
}
