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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e7;
vector<int> spf(N, -1);
void init() {
    for(int i = 2; i < N; ++i) {
        if(spf[i] == -1) {
            for(int j = i; j < N; j += i) {
                if(spf[j] == -1) spf[j] = i;
            }
        }
    }
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<int> v(n);
    int g = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        g = gcd(g, v[i]);
    }
    for (int i = 0; i < n; i++) {
        v[i] /= g;
    }
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        while(spf[v[i]] != -1) {
            int t = spf[v[i]];
            while(v[i] % t == 0) v[i] /= t;
            ++mp[t];
        }
    }
    int ans = n;
    for(auto& val : mp) {
        ans = min(ans, n - val.ss);
    }
    if(ans == n) ans = -1;
    cout << ans;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
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
