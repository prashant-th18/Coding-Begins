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
    for(int t_ = 0; t_ < test; t_++)
    {
        ll n, k; cin >> n >> k;
        if(n == 0) cout << "Bob";
        else if(k != 3 && __gcd(k, 3LL) != 1)
        {
            ll s = 1, e = n / k + 1;
            ll ans = 0;
            while(s <= e)
            {
                ll mid = (s + e) >> 1;
                ll midd = k * mid + (mid - 1);
                if(midd <= n)
                {
                    ans = mid; s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
            debug(ans);
            ll num = n - ans;
            if(num % 3 == 0) cout << "Bob";
            else cout << "Alice";
        }
        else if(k == 3)
        {
            cout << ((n % 4 == 0) ? ("Bob") : ("Alice"));
        }
        else
        {
            cout << ((n % 3 == 0) ? ("Bob") : ("Alice"));
        }
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
