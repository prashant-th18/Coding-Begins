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
#define MOD 1000000007
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second
#ifdef LOCAL
#define debug(x) cout << '\n' << "----------------" << '\n' << #x << " : "; _print(x); cout << '\n' << "-------------" << '\n';
#else
#define debug(x)
#endif

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */
template <typename T> void _print(vector <T> v) { cout << "[ "; for (auto myval : v) cout << myval << " "; cout << "]"; }
template <typename T1, typename T2> void _print(vector <T1, T2> v) { cout << "[ "; for (auto myval : v) cout << myval.ff << ' ' << myval.ss << " "; cout << "]"; }
template <typename T> void _print(set <T> v) { cout << "[ "; for (auto myval : v) cout << myval << " "; cout << "]"; }
template <typename T1, typename T2> void _print(map<T1, T2> v) { cout << "[ "; for (auto myval : v) cout << myval.ff << ' ' << myval.ss << " "; cout << "]"; }
void _print(int a) {cout << a;}
void _print(ll a) {cout << a;}
void _print(char a) {cout << a;}
void _print(string a) {cout << a;}
void _print(double a) {cout << a;}
// *-> KISS*
int solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    vector<set<int>> f(26), s(26); // For upper and lower
    for (int i = 0; i < n; i++) {
        if(a[i] == b[i]) continue;
        else
        {
            f[a[i] - 97].insert(i);
            s[b[i] - 97].insert(i);
        }
    }
    for (int i = 0; i < 26; i++) {
        if((sz(f[i]) + sz(s[i])) & 1)
        {
            cout << "No"; return 0;
        }
    }
    vector<pair<int, int>> v;
    auto func = [&]() -> void
    {
    for (int i = 0; i < 26; i++) {
        while(sz(f[i]) >= 2)
        {
            auto secc = f[i].begin();
            auto firr = secc++;
            auto fir = *firr, sec = *secc;
            // *fir      *sec
            //   x         y
            //  si tj
            v.push_back({sec, fir});
            f[i].erase(sec); f[i].erase(fir);
            //  fir       x
            //  sec       y
            s[b[fir] - 97].erase(fir);
            if(b[fir] == b[sec]) s[b[sec] - 97].erase(sec);
            else
            {
                f[b[fir] - 97].insert(sec);
            }
            swap(a[sec], b[fir]);
        }
        while(sz(s[i]) >= 2)
        {
            auto secc = s[i].begin();
            auto firr = secc++;
            auto fir = *firr, sec = *secc;
            //  x        y
            // fir      sec
            v.push_back({sec, fir});
            // x        fir
            // y        sec
            s[i].erase(fir); s[i].erase(sec);
            f[a[sec] - 97].erase(sec);
            if(a[fir] == a[sec]) f[a[fir] - 97].erase(fir);
            else
            {
                s[a[sec] - 97].insert(fir);
            }
            swap(b[fir], a[sec]);
        }
    }
    for (int i = 0; i < 26; i++) {
        if(sz(f[i]) == 0 || sz(s[i]) == 0) continue;
        else
        {
            // a     xy
            // ch    a
            // Greedy
            auto firr = f[i].begin();
            auto secc = s[i].begin();
            auto fir = *firr;
            auto sec = *secc;
            f[i].erase(firr); s[i].erase(secc);
            f[a[sec] - 97].erase(sec);
            s[a[sec] - 97].insert(sec);
            v.push_back({sec, sec});
            s[b[fir] - 97].erase(fir);
            v.push_back({sec, fir});
            if(b[fir] == a[sec]) {}
            else f[b[fir] - 97].insert(sec);
            swap(b[fir], b[sec]);
            swap(a[sec], b[sec]);
        }
    }
    };
    while(a != b) func();
    cout << "Yes\n" << sz(v) << '\n';
    for(auto val : v) cout << val.ff + 1 << ' ' << val.ss + 1 << '\n';
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    cin >> TET;
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
}
// -> Keep It Simple Stupid!
