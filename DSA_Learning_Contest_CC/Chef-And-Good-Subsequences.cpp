#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((ll)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const ll MOD = 1e9 + 7;
// *-> KISS*

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

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        ll n, k; cin >> n >> k;
        vector<ll> v(n), occ(8001);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            ++occ[v[i]];
        }
        sort(all(v));
        v.resize(unique(all(v)) - v.begin());
        k = min(k, sz(v) + 1);
        ll ans = 0;
        vector<vector<ll>> dp(sz(v) + 1, vector<ll>(k + 1, 0));
        for(int i = 0; i < sz(v); ++i)
        {
            for(int j = 0; j <= k; ++j)
            {
                if(j == 0) dp[i][j] = 1;
                else
                {
                    ll one = (i == 0) ? (0) : (dp[i - 1][j]);
                    ll two = 0;
                    if(i == 0)
                    {
                        if(j == 1) two = occ[v[i]];
                    }
                    else
                    {
                       two = dp[i - 1][j - 1] * (occ[v[i]]) % MOD; 
                    }
                    dp[i][j] = (one + two) % MOD;
                }
                if(i == sz(v) - 1)
                {
                    ans = (ans + dp[i][j]) % MOD;
                }
            }
        }
        cout << ans;
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
