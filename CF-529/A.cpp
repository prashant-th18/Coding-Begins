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
    string s; cin >> s;
    int i = 0, cnt = 0;
    string res = "";
    while(i < n)
    {
        res += s[i];
        ++i;
        i += cnt;
        ++cnt;
    }
    cout << res;
    return 0;
}
// -> Keep It Simple Stupid!
