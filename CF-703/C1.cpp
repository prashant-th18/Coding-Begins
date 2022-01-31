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
    int max2 = -1;
    cout << "? " << 1 << ' ' << n << endl;
    cin >> max2;
    auto right = [&](int maxx) -> int
    {
        int s = maxx, e = n;
        int ans = -1;
        while(s <= e)
        {
            int mid = (s + e) / 2;
            if(maxx == mid)
            {
                cout << "? " << maxx << ' ' << maxx + 1 << endl;
                int tt; cin >> tt;
                if(tt == maxx) ans = maxx + 1;
                break;
            }
            cout << "? " << maxx << ' ' << mid << endl;
            int temp; cin >> temp;
            if(temp == maxx)
            {
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    };
    auto left = [&](int maxx) -> int
    {
        int s = 1, e = maxx;
        int ans = -1;
        while(s <= e)
        {
            int mid = (s + e) / 2;
            if(maxx == mid)
            {
                cout << "? " << maxx - 1 << ' ' << maxx << endl;
                int tt; cin >> tt;
                if(tt == maxx) ans = maxx - 1;
                break;
            }
            cout << "? " << mid << ' ' << maxx << endl;
            int temp; cin >> temp;
            if(temp == maxx)
            {
                ans = mid;
                s = mid + 1;
            }
            else e = mid - 1;
        }
        return ans;
    };
    if(max2 == 1)
    {
        // Right
        int t = right(max2);
        cout << "! " << t << endl;
    }
    else if(max2 == n)
    {
        // Left
        int t = left(max2);
        cout << "! " << t << endl;
    }
    else
    {
        int ind; cout << "? " << 1 << ' ' << max2 << endl;
        cin >> ind;
        if(ind == max2)
        {
            // Left
            int t = left(max2);
            cout << "! " << t << endl;
        }
        else
        {
            // Right
            int t = right(max2);
            cout << "! " << t << endl;
        }
    }
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    //cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
        #ifdef LOCAL
            cout << "##################" << '\n';
        #endif
        if(solve())
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
