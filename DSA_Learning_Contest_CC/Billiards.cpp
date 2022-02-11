#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
// *-> KISS*
const int MOD = 1e9 + 9;
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    vector<ll> shots((int)1e6 + 1);
    shots[0] =1; shots[1] = 0; shots[2] = 1; shots[3] = 1;
    for(ll i = 4; i < sz(shots); ++i)
    {
        /// Either make a cannon shot first
        // Or First make a In-Off Shot
        shots[i] = ((shots[i] + shots[i - 2]) % MOD + shots[i - 3]) % MOD;
    }
    cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        int x; cin >> x;
        cout << shots[x] << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
