#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
int N = 3e5;
// *-> KISS*

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    cin >> test;
    string res = "0123456789";
    string ans = "989";
    for (int i = 0; i < N; i++) {
        ans += res[i % 10];
    }
    for(int t_ = 0; t_ < test; t_++)
    {
        // 98901
        // 98789
        // 98767
        int n; cin >> n;
        cout << (ans.substr(0, n));
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
