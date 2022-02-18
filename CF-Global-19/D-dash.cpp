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

// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (ll &val : a) {
        cin >> val;
    }
    vector<ll> b(n);
    for (ll &val : b) {
        cin >> val;
    }
    ll orig = 1e18;
    auto ans = [&]()
    {
        ll t = 0;
        for (int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; ++j)
            {
                t += (a[i] + a[j]) * (a[i] + a[j]);
                t += (b[i] + b[j]) * (b[i] + b[j]);
            }
        }
        orig = min(orig, t);
    };
    ans();
    deque<ll> diff(n);
    for (int i = 0; i < n; i++) {
        diff[i] = a[i] - b[i];
    }
    sort(diff.rbegin(), diff.rend());
    /*
    for(int i = 0, cnt = 0, e = n - 1, s = 0; i < n; ++i, ++cnt)
    {
        if(cnt == 0)
        {
            swap(a[diff[e].ss], b[diff[e].ss]);
            ans();
            --e;
        }
        else
        {
            swap(a[diff[s].ss], b[diff[s].ss]);
            ans();
            ++s;
        }
    }
    cout << orig;
    
    ll rem = orig;
    while(sz(diff) > 1)
    {
        ll minn = 0;
        ll temp = diff.back();
        diff.pop_back();
        diff[0] += temp;
        sort(diff.rbegin(), diff.rend());
        for(int i = 1; i < sz(diff); ++i)
        {
            minn += diff[i];
        }
        orig = min(orig, rem - diff[0] * minn * 2);
    }
    cout << orig;

    */

    int maxValue(vector<vector<int>>& events, int k) {
        auto cmp = [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[1] < rhs[1];
        };
        sort(events.begin(), events.end(), cmp);

        int n = events.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        for (int i = 1; i <= n; i++) {
            int non_overlap_index = 0;
            for (int l = i - 1; l >= 1; l--) {
                if (events[l-1][1] < events[i-1][0]) {
                    non_overlap_index = l;
                    break;
                }
            }
            for (int j = 1; j <= k; j++) {
                dp[i][j] = max(dp[non_overlap_index][j-1] + events[i-1][2], dp[i-1][j]);
            }
        }
        return dp[n][k];
    }
};


    /*
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if(i == j)
            {
                swap(a[i], b[i]);
                ans();
                debug(i); debug(j);
                swap(a[i], b[i]);
            }
            else
            {
                swap(a[i], b[i]);
                swap(a[j], b[j]);
                ans();
                debug(i); debug(j);
                swap(a[i], b[i]); swap(a[j], b[j]);
            }
        }
    }
    */
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
