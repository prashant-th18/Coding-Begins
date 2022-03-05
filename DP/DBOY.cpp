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
        int n; cin >> n;
        vector<int> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        vector<ll> dp(1001, LLONG_MAX); // -1 -> Not Possible
        dp[0] = 0;
        for(int i = 1; i <= 1000; ++i)
        {
            ll maxx = LLONG_MAX;
            for(int j = 0; j < n; ++j)
            {
                if(i - v[j] < 0)
                {
                    break;
                }
                else
                {
                    if(dp[i - v[j]] != LLONG_MAX)
                    {
                        maxx = min(maxx, 1 + dp[i - v[j]]);
                    }
                }
            }
            dp[i] = maxx;
        }
        debug(dp);
        ll ans = 0;
        /*
        set<pair<ll, ll>> st;
        for(int i = 0; i <= 1000; ++i)
        {
            if(dp[i] != -1)
            {
                st.insert(make_pair(i, dp[i]));
            }
        }
        for (int i = 0; i < n; i++) {
            h[i] *= 2;
            auto it = st.lower_bound(make_pair(h[i], 0));
            ans += (it -> second);
        }
        cout << ans;
        */
        for(int i = 0; i < n; ++i) ans += dp[2 * h[i]];
        cout << ans;
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
