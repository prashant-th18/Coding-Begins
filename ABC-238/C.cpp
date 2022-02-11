#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 998244353;
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
        ll n; cin >> n;
        vector<ll> v;
        v.push_back(0);
        ll res = 10;
        int cnt = 0;
        for(; cnt < 18; res *= 10LL, ++cnt)
        {
            v.push_back(res - 1);
        }
        ll sum = 0;
        for(int i = 1; i < sz(v); ++i)
        {
            ll num = v[i];
            if(num >= n)
            {
                ll diff = (n - v[i - 1]) % MOD;
                sum = (sum + (diff * (diff + 1) / 2) % MOD) % MOD;
                break;
            }
            else
            {
                ll diff = (v[i] - v[i - 1]) % MOD;
                sum = (sum + (diff * (diff + 1) / 2) % MOD) % MOD;
            }
        }
        cout << sum;
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
