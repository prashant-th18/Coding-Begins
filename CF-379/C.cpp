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
    //cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        ll n, m, k; cin >> n >> m >> k;
        ll x, s; cin >> x >> s;
        vector<pair<ll, ll>> a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i].ff;
        }
        for (int i = 0; i < m; i++) {
            cin >> a[i].ss;
        }
        vector<pair<ll, ll>> temp(k);
        for (int i = 0; i < k; i++) {
            cin >> temp[i].ss;
        }
        for (int i = 0; i < k; i++) {
            cin >> temp[i].ff;
        }
        sort(temp.begin(), temp.end());
        vector<ll> st;
        for (int i = 0; i < k; i++) {
            st.push_back(temp[i].ff);
        }
        vector<ll> mini(k, LLONG_MIN);
        for (int i = 0; i < k; i++) {
            if(i == 0)
            {
                mini[i] = temp[i].ss;
            }
            else
            {
                mini[i] = max(mini[i], temp[i].ss);
            }
        }
        ll ans = n * x;
        auto fun = [&](ll s1, ll s2) -> void
        {
            auto it = upper_bound(all(st), s1) - st.begin() - 1;
            if(it >= 0)
            {
                ans = min(ans, max(0LL, n - mini[it]) * s2);
            }
            else
            {
                ans = min(ans, n * s2);
            }
        };
        fun(s, x);
        for(int i = 0; i < m; ++i)
        {
            if(a[i].ss > s) continue;
            ll ntime = a[i].ff;
            ll nmana = s - a[i].ss;
            fun(nmana, ntime);
        }
        cout << ans;
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
