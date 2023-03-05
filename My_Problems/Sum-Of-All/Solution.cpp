#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
template<typename T>
T binexp(T a, T b) { // Binary Exponentiation
    T ans = 1;
    while (b) {
        if (b & 1) {
            ans = 1LL * ans * a % MOD;
        }
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return ans;
}
ll mul(ll a, ll b) // Multiplying two numbers & taking mod as well
{
    return a % MOD * (b % MOD) % MOD;
}
ll sub(ll a, ll b) // Subtracting two numbers & taking mod
{
    a %= MOD; b %= MOD;
    return (a - b + MOD) % MOD;
}
ll add(ll a, ll b) // Adding two numbers & taking mod
{
    a %= MOD;
    b %= MOD;
    return (a + b) % MOD;
}
ll total_size = 0;
bool check(int si) {
    // This part is for the verification that sum of length of N over all test cases doesn't exceed 10^5
    total_size += si;
    return total_size <= 100000;
}
// *-> KISS*
int solve() {
    string s; cin >> s; // Input received!
    assert(sz(s) >= 1 && sz(s) <= (int)1e5);
    
    assert(check(sz(s)));

    ll ans = 0; // This will store the final answer we need to print
    int n = sz(s); // Length of the number
    for(ll i = 0; i < n; ++i)
    {
        ll num = (s[i] - '0');
        ll t = n - 1 - i;
        ll p = binexp(11LL, t), two = binexp(2LL, i), ten = binexp(10LL, t);
        p = mul(p, two); // (11 ^ t) * (2 ^ i)
        p = sub(p, ten); // ((11 ^ t) * (2 ^ i) - (10 ^ t))
        num = mul(num, p); // p * num
        ans = add(ans, num); // ans + num
    }
    cout << ans;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    cin >> TET; // Test cases received
    assert(TET >= 1 && TET <= (int)1e5);
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
#ifdef LOCAL
        cout << "##################" << '\n';
#endif
        if (solve())
        {
            break;
        }
        cout << '\n';
    }
#ifdef LOCAL
    cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}
// -> Keep It Simple Stupid!
