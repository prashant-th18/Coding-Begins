#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
// *-> KISS*
int32_t main() {
    string s; cin >> s;
    vector<string> ans;
    sort(s.begin(), s.end());
    do {
        ans.push_back(s);
    } while (next_permutation(all(s)));
    cout << sz(ans) << '\n';
    for(auto val : ans) cout << val << '\n';
    return 0;
}
// -> Keep It Simple Stupid!
