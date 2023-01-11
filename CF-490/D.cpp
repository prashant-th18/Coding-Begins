#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #include "debug.h"
#endif
#ifndef LOCAL
#include "bits/stdc++.h"
#endif

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

// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
    vector<ll> v(n), rem(m);
    vector<vector<pll>> here(m);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        rem[v[i] % m]++;
    }
    int how = n / m;
    ll sum = 0;
    priority_queue<pll> pq;
    for(int i = m - 1; i >= 0; --i) {
        ll& R = rem[i];
        bool flag = false;
        while(!pq.empty() && R > 0) {
            flag = true;
            pll p = pq.top(); pq.pop();
            ll mini = min(p.ss, R);
            R -= mini;
            p.ss -= mini;
            sum += (p.ff - i) * mini;
            here[i].push_back(pll((p.ff - i), mini));
            if(p.ss != 0) {
                pq.push(p);
            }
        }
        ll dif = R - how;
        if(dif < 0)  
            pq.push(pll(i, abs(dif)));
        debug(i, dif, sz(pq));
    }
    rem.assign(m, 0);
    for(int i = 0; i < n; ++i) {
        int re = v[i] % m;
        auto& t = here[re];
        if(sz(t)) {
            pll& p = t[sz(t) - 1];
            p.ss--;
            v[i] += p.ff;
            if(p.ss == 0) t.pop_back();
        }
        rem[v[i] % m]++;
    }
    for(int i = m - 1; i >= 0; --i) {
        ll& dif = rem[i];
        while(!pq.empty() && dif > 0) {
            pll p = pq.top(); pq.pop();
            ll mini = min(p.ss, dif);
            dif -= mini;
            p.ss -= mini;
            if(p.ff > i) {
                sum += (p.ff - i) * mini;
                here[i].push_back(pll((p.ff - i), mini));
            }
            else {
                sum += ((m - i) + p.ff) * mini;
                here[i].push_back(pll((m - i) + p.ff, mini));
                rem[p.ff] += mini;
            }
            if(p.ss != 0) {
                pq.push(p);
            }
        }
        ll d = dif - how;
        if(d < 0) {
            pq.push(pll(i, abs(d)));
        }
    }
    while(!pq.empty()) {
        debug(pq.top()); pq.pop();
    }
    assert(pq.empty());
    rem.assign(m, 0);
    cout << sum << '\n';
    for(int i = 0; i < n; ++i) {
        int re = v[i] % m;
        auto& t = here[re];
        if(sz(t)) {
            pll& p = t[sz(t) - 1];
            p.ss--;
            v[i] += p.ff;
            if(p.ss == 0) t.pop_back();
        }
        rem[v[i] % m]++;
    }
    for(int i = 0; i < n; ++i) cout << v[i] << ' ';
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
