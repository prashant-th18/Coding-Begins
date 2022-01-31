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

inline ll nxt() { ll _; cin >> _; return _; }

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
    string s; cin >> s;
    function<vector<int>(string t)> compress = [&](string t) -> vector<int>
    {
        int cnt = 0;
        char ch = t[0];
        vector<int> res;
        for(int i = 0; i < sz(t); ++i)
        {
            if(ch == t[i])
            {
                ++cnt;
            }
            else
            {
                res.push_back(cnt);
                cnt = 1; ch = t[i];
            }
        }
        res.push_back(cnt);
        return res;
    };
    vector<int> res = compress(s);
    priority_queue<pair<int, int>> pq; // cnt, -index
    for (int i = 0; i < sz(res); i++) {
        pq.push({res[i], -i});
    }
    unordered_map<int, bool> mp; // visited
    function<void()> remove_bad = [&]() -> void
    {
        while(pq.size() != 0 && mp[pq.top().ss])
        {
            pq.pop();
        }
    };
    int cnt = 0, j = sz(res) - 1;
    for(int i = 0; i < sz(res); ++i)
    {
        remove_bad();
        if(res[i] == 0 || j < i) break;
        if(res[i] == 1)
        {
            auto f = pq.top();

            if(i == j) ++cnt;
            else
            {
                --res[j];
                if(res[j] == 0) --j;
            }
        }
        else
        {
            ++cnt; mp[-i] = true;
        }
    }
    cout << cnt;
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
