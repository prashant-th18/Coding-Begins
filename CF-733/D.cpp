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

inline ll nxt() { ll x; cin >> x; return x; }

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
    int n = nxt();
    vector<int> v(n), order(n);
    vector<bool> vis(n + 1, false);
    map<int, vector<int>> mp;
    vector<int> left;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        v[i] = nxt();
        mp[v[i]].push_back(i + 1);
        if(!vis[v[i]])
        {
            ++cnt;
            vis[v[i]] = true;
            order[i] = v[i];
        }
        else
        {
            left.push_back(i + 1);
        }
    }
    debug(left);
    vector<int> right;
    for(int i = 1; i <= n; ++i)
    {
        if(!vis[i]) right.push_back(i);
    }
    function<void()> print = [&]()
    {
        cout << cnt << '\n';
        for (int i = 0; i < n; i++) {
            cout << order[i] << ' ';
        }
    };
    if(sz(left) == 0)
    {
        print();
    }
    else if(sz(left) == 1)
    {
        // if left[0] == right[0], lo bhai aagya swaad
        // else mauj
        if(left[0] != right[0])
        {
            order[left[0] - 1] = right[0];
        }
        else
        {
            // now go to the map whose key is v[left[0] - 1]
            vector<int> temp = mp[v[left[0] - 1]];
            for(int i = 0; i < sz(temp); ++i)
            {
                // ab mujeh koi index milega
                if(temp[i] == left[0]) continue;
                else
                {
                    // suppose temp[i] == 1
                    //  toh ab esa krte hai ki jha prr 1 point krr rha tha vha left[0] ko point krva dete hai
                    order[left[0] - 1] = v[temp[i] - 1];
                    left[0] = temp[i];
                    break;
                }
            }
            order[left[0] - 1] = right[0];
        }
        print();
    }
    else
    {
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        unordered_map<int, int> in;
        for (int i = 0; i < sz(right); i++) {
            in[right[i]] = i;
        }
        set<int> st; for(int i = 0; i < sz(right); ++i) st.insert(i);
        for (int i = 0; i < sz(left); i++) {
            if(in.count(left[i]))
            {
                if(i <= in[left[i]])
                {
                    if(st.count(in[left[i]] - i)) st.erase(in[left[i]] - i);
                }
                else
                {
                    if(st.count(in[left[i]] + n - i)) st.erase(in[left[i]] + n - i);
                }
            }
        }
        int gap = *st.begin();
        debug(gap);
        debug(sz(right));
        for (int i = 0; i < sz(left); i++) {
            order[left[i] - 1] = (right[(gap + i) % sz(right)]);
        }
        print();
    }
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
