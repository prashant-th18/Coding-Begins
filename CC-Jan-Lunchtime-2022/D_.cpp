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

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */
vector<int> v;
int k, n;
struct comp
{
    bool operator()(const int& a, const int& b) const
    {
        int first = 0, second = 0;
        int i = (a + 1) % n, cnt = 0;
        while(cnt < k)
        {
            if(v[i] == 0) ++first;
            i = (i + 1) % n;
            ++cnt;
        }
        cnt = 0;
        i = (b + 1) % n;
        while(cnt < k)
        {
            if(v[i] == 0) ++second;
            i = (i + 1) % n;
            ++cnt;
        }
        return first < second;
    }
};

#ifdef LOCAL
#define debug(x) cout << '\n' << "----------------" << '\n' << #x << " : "; _print(x); cout << '\n' << "-------------" << '\n';
#else
#define debug(x)
#endif

template <typename T> void _print(vector <T> vv) { cout << "[ "; for (auto myval : vv) cout << myval << " "; cout << "]"; }
void _print(int a) {cout << a;}
void _print(ll a) {cout << a;}
void _print(char a) {cout << a;}
void _print(string a) {cout << a;}
void _print(double a) {cout << a;}

// *-> KISS*
int solve() {
    cin >> n >> k;
    v.clear();
    v.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int cnt = count(all(v), 0);
    if(cnt == 0)
    {
        cout << -1; return 0;
    }
    set<int, comp> st; // index
    vector<int> ans(n);
    int first = 1;
    int index = -1;
    for(int i = 0; i < n; ++i) if(v[i] == 0) { index = i; break; }
    st.insert(index);
    auto dec = [&](auto in) -> int
    {
        return (in - 1 + n) % n;  
    };
    while(sz(st) != 0)
    {
        int ind = *st.begin(); st.erase(st.begin());
        ans[ind] = first++;
        int i = dec(ind);
        int c = 0;
        while(c < k)
        {
            if(v[i] != 0)
            {
                --v[i];
                if(v[i] == 0)
                {
                    st.insert(i);
                }
            }
            i = dec(i);
            ++c;
        }
    }
    if(first <= n)
    {
        cout << first << endl;
        cout << -1;
    }
    else
    {
        for(auto val : ans) cout << val << ' ';
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

