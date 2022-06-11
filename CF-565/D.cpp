#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */

const int N = 2750132;
vector<int> prime;
vector<bool> p(N, true);
vector<int> sieve(N, -1);
map<int, int> mp;
void init() {
    int cnt = 1;
    p[2] = true;
    p[0] = p[1] = false;
    for(int i = 4; i < N; i += 2) p[i] = false;
    prime.push_back(2);
    mp[2] = cnt++;
    for(ll i = 3; i < N; i += 2) {
        if(p[i]) {
            prime.push_back(i);
            mp[i] = cnt++;
            for(ll j = i * i; j < N; j += 2 * i) {
                p[j] = false;
            }
        }
    }
    for(ll i = 2; i * i < N; ++i) {
        if(sieve[i] == -1) {
            for(ll j = i * i; j < N; j += i) {
                if(sieve[j] == -1) sieve[j] = i;
            }
        }
    }
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    n *= 2;
    multiset<int> st;
    for (int i = 0; i < n; i++) {
        int tt; cin >> tt; st.insert(tt);
    }
    vector<int> t;
    while(sz(st) != 0) {
        int lar = *st.rbegin();
        if(sieve[lar] == -1) {
            // It's a prime
            int who = mp[lar];
            t.push_back(who);
            st.erase(st.find(lar));
            st.erase(st.find(who));
        }
        else {
            int who = lar / sieve[lar];
            t.push_back(lar);
            st.erase(st.find(lar));
            st.erase(st.find(who));
        }
    }
    for(auto val : t) cout << val << ' ';
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    //cin >> TET;
    init();
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
#ifdef LOCAL
        cout << "##################" << '\n';
#endif
        if (solve())
        {
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
