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

const int N = 1e7 + 1;
vector<int> spf(N, -1);
void init() {
    for(int i = 2; i < N; ++i) {
        if(spf[i] == -1) {
            for(int j = i; j < N; j += i) spf[j] = i;
        }
    }
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    /*
    for(int i = 1; i <= n; ++i) {
        cout << i << " -> ";
        vector<int> t;
        for(int j = 2; j * j <= i; ++j) {
            if(i % j == 0) {
                t.push_back(j);
                if(i / j != j) t.push_back(i / j);
            }
        }
        sort(t.begin(), t.end());
        bool f = false; int x = -1, y = -1;
        for(int j = 0; j < sz(t) && !f; ++j) {
            for(int k = j + 1; k < sz(t) && !f; ++k) {
                if(gcd(t[j] + t[k], i) == 1) {
                    f = true; x = t[j], y = t[k];
                }
            }
        }
        cout << x << ' ' << y << endl;
    } */
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<int>> ans(n);
    vector<array<int, 2>> sol(n, {-1, -1});
    for(int i = 0; i < n; i++) {
        int pre = v[i];
        if(!(pre & 1)) {
            int c = 0;
            while(v[i] % 2 == 0) v[i] /= 2, ++c;
            if(v[i] == 1) continue;
            else {
                sol[i][0] = (1 << c);
                sol[i][1] = v[i];
            }
        }
        else {
            int num = spf[v[i]];
            int c = 0;
            while(v[i] % num == 0) ++c, v[i] /= num;
            if(v[i] == 1) {
                continue;
            }
            else {
                ans[i].push_back(num);
                while(v[i] != 1) {
                    num = spf[v[i]];
                    while(v[i] % num == 0) v[i] /= num;
                    ans[i].push_back(num);
                }
                for(int j = 0; j < sz(ans[i]) && sol[i][0] == -1; ++j) {
                    for(int k = j + 1; k < sz(ans[i]) && sol[i][0] == -1; ++k) {
                        if(gcd(ans[i][j] + ans[i][k], pre) == 1) {
                            sol[i][0] = ans[i][j]; sol[i][1] = ans[i][k];
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; ++i) cout << sol[i][0] << ' ';
    cout << '\n';
    for(int i = 0; i < n; ++i) cout << sol[i][1] << ' ';
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = false;
    init();
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
