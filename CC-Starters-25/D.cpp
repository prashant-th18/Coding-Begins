#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
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
    cin >> test;
    vector<int> fact(2e6, 0);
    fact[0] = fact[1] = 1;
    for(int i = 2; i < sz(fact); ++i)
    {
        fact[i] = 1LL * i * fact[i - 1] % MOD;
    }
    auto binexp = [&](ll base, ll power) -> ll
    {
        ll res = 1;
        while(power)
        {
            if(power & 1) res = res * base % MOD;
            power >>= 1;
            base = base * base % MOD;
        }
        return res;
    };
    auto modinv = [&](ll num)
    {
        return binexp(num, MOD - 2);  
    };
    auto ncr = [&](ll n, ll r) -> ll
    {
        if(r > n) return 0;
        else if(r == n) return 1;

        return fact[n] * modinv(fact[r]) % MOD * modinv(fact[n - r]) % MOD;
    };
    for(int t_ = 0; t_ < test; t_++)
    {
        ll n, m; cin >> n >> m;
        vector<ll> a(n + 1);
        for (int i = 1; i < n + 1; i++) {
            cin >> a[i];
        }
        vector<int> index(n + 2, INT_MAX);
        vector<bool> vis(n + 1, false);
        int z = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(vis[i]) continue;

            vis[i] = true;
            index[i] = z++;
            int min_index = index[i];
            vector<int> help = {i};
            int next = a[i];
            while(vis[next] == false)
            {
                min_index = min(min_index, index[next]);
                help.push_back(next);
                vis[next] = true;
                next = a[next];
            }
            help.push_back(next); min_index = min(min_index, index[next]);
            for(auto val : help)
            {
                index[val] = min_index;
            }
        }
        vector<int> cc(n + 1, 0);
        for(int i = 1; i <= n; ++i)
        {
            ++cc[index[i]];
        }
        vector<ll> cycles;
        for(int i = 0; i <= n; ++i)
        {
            if(cc[i] != 0)
            {
                cycles.push_back(cc[i]);
            }
        }
        debug(cycles);
        ll cnt = 0;
        for (int i = 0; i < sz(cycles); i++) {
            ll how = cycles[i];
            cnt = (cnt + (ncr(m, how) * fact[how]) % MOD) % MOD;
        }
        cout << cnt;
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
