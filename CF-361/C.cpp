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
    for(int t_ = 0; t_ < test; t_++)
    {
        ll m; cin >> m;
        ll s = 8, e = 8 * m + 1;
        ll ans = -1;
        while(s <= e)
        {
            ll mid = (s + e) >> 1;
            ll cnt = 0; bool flag = false;
            for(ll i = 2; mid / i / i / i != 0 ; ++i)
            {
                cnt += (mid / i / i / i);
                flag |= (mid % (i * i * i) == 0);
            }
            if(cnt < m)
            {
                s = mid + 1;
            }
            else if(cnt > m)
            {
                e = mid - 1;
            }
            else if(flag)
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        cout << ans;
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
