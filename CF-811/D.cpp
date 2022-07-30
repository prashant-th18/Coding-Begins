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
string s;
vector<string> v;
void fun() {
    queue<pair<int, int>> q;
    q.push(pair(n - 1, 0));
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        if(p.ff < 0) {
            cout << p.ss;
            return;
        }
        for(int i = 0; i < m; ++i) {
            string& t = v[i];
            int j = p.ff;
            for(int k = 0; k < sz(t); ++k) {
                int ah = sz(t) - 1 - k;
                int bh = k;
                if(t[k] == s[j] && (j + ah <= n - 1) && (j - bh >= 0)) {
                    if(s.substr(j - bh, sz(t)) == v[i]) {
                        q.push(pair(j - bh - 1, p.ss + 1));
                    }
                }
            }
        }
    }
    cout << -1;
}
// *-> KISS*
int solve() {
    cin >> s;
    n = sz(s);
    cin >> m;
    v.assign(m, string(0, ' '));
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }
    fun();
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = true;
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
