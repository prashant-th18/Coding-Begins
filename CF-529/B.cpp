#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
// *-> KISS*
int32_t main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int &val : v) {
        cin >> val;
    }
    sort(v.begin(), v.end());
    cout << min(v[n - 2] - v[0], v[n - 1] - v[1]);
    return 0;
}
// -> Keep It Simple Stupid!
