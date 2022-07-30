#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second
using pll = pair<ll, ll>;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll add(ll a, ll b) {
    return (a % MOD + b % MOD) % MOD;
}
ll mul(ll a, ll b) {
    return (a % MOD * b % MOD) % MOD;
}
template<typename T>
T binexp(T a, T b) {
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
// *-> KISS*
int solve() {
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);
    ll n, m, k; cin >> n >> m >> k;
    vector<array<ll, 2>> v(n);
    vector<vector<ll>> rhyme;
    set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
        st.insert(v[i][1]);
    }
    vector<int> hash(n + 1); int dif = 1;
    for(auto& val : st) {
        hash[val] = dif++;
    }
    --dif;
    rhyme.assign(dif + 1, vector<ll>());
    for (int i = 0; i < n; i++) {
        v[i][1] = hash[v[i][1]];
        rhyme[v[i][1]].push_back(v[i][0]);
    }
    for(int i = 1; i <= dif; ++i) sort(rhyme[i].begin(), rhyme[i].end());

    // Now we are sure that rhyme classes are from [1 .. dif ]
    vector<ll> cnt(26, 0);
    for (int i = 0; i < m; i++) {
        char ch; cin >> ch;
        cnt[ch - 'A']++;
    }
    vector<vector<ll>> dp(k + 1, vector<ll>(dif + 1));
    vector<ll> till(k + 1, 0);
    // Base Case
    till[0] = 1;
    for(int i = 1; i <= k; ++i) {
        ll here = 0;
        for(int j = 1; j <= dif; ++j) {
            // dp[i][j] -> sentence of length "i" such that last word rhyme class is "j"
            for(int l = 0; l < sz(rhyme[j]); ++l) {
                if(rhyme[j][l] > i) break;
                else {
                    dp[i][j] = add(dp[i][j], till[i - rhyme[j][l]]);
                }
            }
            here = add(here, dp[i][j]);
        }
        till[i] = here;
    }
    // Now you know, k length ke liye 1 rhyme class ke corresponding sentences => dp[k][1]
    vector<ll> how(dif + 1, 0);
    for(int i = 1; i <= dif; ++i) how[i] = dp[k][i];
    ll res = 1;
    for(int i = 0; i < 26; ++i) {
        if(cnt[i] != 0) {
            ll t = 0;
            for(int j = 1; j <= dif; ++j) {
                t = add(t, binexp(how[j], cnt[i]));
            }
            res = mul(res, t);
        }
    }
    cout << res;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = false;
    int TET = 1;
    if(test) cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
        #ifdef LOCAL
        	cout << "##################" << '\n';
        #endif

        if (solve()) {
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
