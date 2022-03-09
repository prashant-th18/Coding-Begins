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

#ifdef LOCAL
#define debug(x) cout << '\n' << "----------------" << '\n' << #x << " : "; _print(x); cout << '\n' << "-------------" << '\n';
#else
#define debug(x)
#endif

template <typename T> void _print(vector <T> v) { cout << "[ "; for (auto myval : v) cout << myval << " "; cout << "]"; }
template <typename T1, typename T2> void _print(vector <T1, T2> v) { cout << "[ "; for (auto myval : v) cout << myval.ff << ' ' << myval.ss << " "; cout << "]"; }
template <typename T> void _print(set <T> v) { cout << "[ "; for (auto myval : v) cout << myval << " "; cout << "]"; }
template <typename T1, typename T2> void _print(map<T1, T2> v) { cout << "[ "; for (auto myval : v) cout << myval.ff << ' ' << myval.ss << " "; cout << "]"; }
void _print(int a) {cout << a;}
void _print(ll a) {cout << a;}
void _print(char a) {cout << a;}
void _print(string a) {cout << a;}
void _print(double a) {cout << a;}
void _print(set<pair<ll, ll>> v) { cout << endl << endl; for(auto val : v) cout << val.ff << ' ' << val.ss << endl << endl; }
// *-> KISS*
int solve() {
    map<ll, bool> mp;
    ll n, d; cin >> n >> d;
    --d; // 0 - based
    deque<ll> v;
    for (int i = 0; i < n; i++) {
        ll val; cin >> val;
        --val;
        mp[val] = true;
        v.push_back(val);
    }
    if(v[0] != 0)
    {
        v.push_front(0);
    }
    if(v[sz(v) - 1] != d)
    {
        v.push_front(d);
    }
    n = sz(v);
    set<pair<ll, ll>> st; // first -> difference
                          // second -> starting of this difference
    ll maxx = LLONG_MIN;
    for(int i = 1; i < n; ++i)
    {
        ll diff = v[i] - v[i - 1] - 1;
        st.insert(pair(diff, v[i - 1]));
    }
    maxx = max(maxx, (*st.begin()).ff);
    auto front = *(st.begin());
    //
    ll pre = front.ss, last = front.ss + front.ff + 1;
    // Deleting from set
    st.erase(st.begin());
    // Working on pre
    int index = lower_bound(all(v), pre) - begin(v);
    --index;
    if(index >= 0)
    {
        auto myit = st.find(pair(pre - v[index] - 1, v[index]));
        assert(myit != st.end());
        st.erase(myit);
        st.insert(pair(last - v[index] - 1, v[index]));
    }
    auto ans_find = [&]()
    {
        if(sz(st) == 0) return;
        auto temp = *(st.begin());
        maxx = max(maxx, temp.ff);
        //debug(temp.ss); debug(temp.ff);
        //debug(maxx);
    };
    // a is gone now
    // placing at day 0
    auto cc = [&](){
    if(!mp.count(0))
    {
        st.insert(pair(v[0], 0));
        ans_find();
        assert(st.find(pair(v[0], 0)) != st.end());
        st.erase(st.find(pair(v[0], 0)));
    }
    if(!mp.count(d))
    {
        st.insert(pair(d - v[n - 1] - 1, v[n - 1]));
        ans_find();
        assert(st.find(pair(d - v[n - 1] - 1, v[n - 1])) != st.end());
        st.erase(st.find(pair(d - v[n - 1] - 1, v[n - 1])));
    }
    };
    cc();
    // ab maximum difference vaale pr
    auto in_mid = [&]()
    {
        if(sz(st) == 0) return;
        auto temp = *(st.rbegin());

        if(temp.ff < 3) return;
        
        assert(st.find(temp) != st.end());
        st.erase(st.find(temp));

        ll npoint = (temp.ff + 1) / 2 + temp.ss;
        auto p2 = pair(npoint - temp.ss - 1, temp.ss);
        auto p1 = pair(temp.ss + temp.ff + 1 - npoint - 1, npoint);
        st.insert(p1); st.insert(p2);
        ans_find();
        assert(st.find(p1) != st.end());
        assert(st.find(p2) != st.end());
        st.erase(p1); st.erase(p2);
        st.insert(temp);
    };
    in_mid();
    if(index >= 0)
    {    
        auto it  = st.find(pair(last - v[index] - 1, v[index]));
        assert(it != st.end());
        st.erase(it);
        st.insert(pair(pre - v[index] - 1, v[index]));

    }
    int last_i = lower_bound(all(v), last) - begin(v);
    ++last_i;
    if(last_i < n)
    {
        auto p = pair(v[last_i] - last - 1, last);
        auto it = st.find(p);
       assert(it != st.end());
       st.erase(it);
        auto p2 = pair(v[last_i] - pre - 1, pre);
        st.insert(p2);
    }
    cc();
    in_mid();
    cout << maxx;
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
    return 0;
}
// -> Keep It Simple Stupid!

