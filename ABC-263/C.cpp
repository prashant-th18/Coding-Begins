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

int n, m;
vector<int> v;
vector<int> ans;
void fun(int in, int cnt = 0) {
    if(cnt == n) {
        for(auto& val : ans) cout << val << ' ';
        cout << '\n';
        return;
    }
    else if(in == m) return;
    else {
        // Take it
        ans.push_back(v[in]);
        fun(in + 1, cnt + 1);

        // Don't
        ans.pop_back();
        fun(in + 1, cnt);
    }
}
// *-> KISS*
int solve() {
    cin >> n >> m;
    v.assign(m, 0);
    iota(all(v), 1);
    fun(0);
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
