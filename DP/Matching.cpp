#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int n;
vector<vector<int>> v, orig;
map<vector<vector<int>>, ll> mp;
vector<bool> vis;
ll add(ll &a, ll b) {
    return (a + b) % MOD;
}
/*
void make0(int i, int j) {
    for(int k = 0; k <= j; ++k) v[i][k] = 0;
}
void make1(int i, int j) {
    for(int k = 0; k <= j; ++k) {
        v[i][k] = orig[i][k];
    }
}
*/
ll fun(int index) {
    if(index < 0) return 1;
    vector<vector<int>> t(n, vector<int>(index + 1, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= index; ++j) {
            t[i][j] = v[i][j];
        }
    }
    if(mp.count(t)) return mp[t];
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        if(v[i][index] == 1 && !vis[i]) {
            vis[i] = true;
            ans = add(ans, fun(index - 1));
            vis[i] = false;
        }
    }
    cerr << ans << endl;
    return mp[t] = ans;
}
int main() {
    cin >> n;
    v.assign(n, vector<int>(n, 0));
    vis.assign(n, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    orig = v;
    cout << fun(n - 1);
    return 0;
}
