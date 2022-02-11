#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;

#ifdef LOCAL
#define debug(x) cout << '\n' << "----------------" << '\n' << #x << " : "; _print(x); cout << '\n' << "-------------" << '\n';
#else
#define debug(x)
#endif

template <typename T> void _print(vector <T> v) { cout << "[ "; for (auto myval : v) cout << myval << " "; cout << "]"; }
template <typename T1, typename T2> void _print(vector <T1, T2> v) { cout << "[ "; for (auto myval : v) cout << myval.ff << ' ' << myval.ss << " "; cout << "]"; }
template <typename T> void _print(set <T> v) { cout << "[ "; for (auto myval : v) cout << myval << " "; cout << "]"; }
template <typename T1, typename T2> void _print(map<T1, T2> v) { cout << "[ "; for (auto myval : v) cout << myval.ff << ' ' << myval.ss << " "; cout << "]"; }
void _print(int a) {cout << a;}
void _print(ll a) {cout << a;}
void _print(char a) {cout << a;}
void _print(string a) {cout << a;}
void _print(double a) {cout << a;}

// *-> KISS*
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    map<ll, int> mp;
    for(ll i = 0; i <= 62; ++i)
    {
        mp[1LL << i] = i;
    }
    auto binexp = [&](ll base, ll power) -> ll
    {
        ll res = 1;
        while(power)
        {
            if(power & 1)
            {
                res = res * base % MOD;
            }
            power >>= 1;
            base = base * base % MOD;
        }
        return res;
    };
    cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        ll n, odd {}, even {}; cin >> n;
        vector<ll> v(n);
        for (ll &val : v) {
            cin >> val;
            int ind = mp[val];
            even += (ind % 2 == 0);
            odd += (ind % 2);
        }
        ll a1 = binexp(2, even);
        ll a2 = (odd == 0) ? (1) : binexp(2, odd - 1);
        cout << (a1 * a2 % MOD - 1 + MOD) % MOD;
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
