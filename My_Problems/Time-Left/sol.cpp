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
        string s; cin >> s;
        int h = stoi(s.substr(0, 2));
        int m = stoi(s.substr(3));
        int d = 23 - h;
        d *= 60;
        d += (60 - m);
        d += 570;
        cout << d << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
