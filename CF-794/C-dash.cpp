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

// *-> KISS*
int solve() {
    int n; cin >> n;
    map<int, int> mp;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        ++mp[v[i]];
    }
    for(const auto& val : mp) {
        if(val.ss > n / 2) {
            cout << "NO"; return 0;
        }
    }
    deque<int> sorted;
    for(int i = 0; i < n; ++i) sorted.push_back(v[i]);
    sort(all(sorted));
    deque<int> sorted1 = sorted;
    vector<int> nvec(n);
    for (int i = 0; i < n; i++) {
        if(i & 1) {
            nvec[i] = sorted.back();
            sorted.pop_back();
        }
        else {
            nvec[i] = sorted.front();
            sorted.pop_front();
        }
    }
    auto dec = [&](int ind) {
        return (ind - 1 + n) % n;  
    };
    auto inc = [&](int ind) {
        return (ind + 1 + n) % n;  
    };
    auto check = [&]() {
        bool flag = true;
        for(int i = 0; i < n && flag; ++i) {
            flag &= (((nvec[i] < nvec[inc(i)]) && (nvec[i] < nvec[dec(i)])) || ((nvec[i] > nvec[inc(i)]) && (nvec[i] > nvec[dec(i)])));
        }
        return flag;
    };
    auto print = [&]() {
        for(int i = 0; i < n; ++i) cout << nvec[i] << ' ';
    };
    if(check()) {
        cout << "Yes\n";
        print();
    }
    else {
        swap(nvec[n - 1], nvec[1]);
        if(check()) {
            cout << "Yes\n"; print();
        }
        else {
            nvec.clear();
            nvec.assign(n, 0);
            for(int i = 0; i < n; ++i) {
                if(i & 1) {
                    nvec[i] = sorted1.front();
                    sorted1.pop_front();
                }
                else {
                    nvec[i] = sorted1.back();
                    sorted1.pop_back();
                }
            }
            if(check()) {
                cout << "Yes\n"; print();
            }
            else {
                swap(nvec[n - 1], nvec[1]);
                if(check()) {
                    cout << "YES\n"; print();
                }
                else cout << "No";
            }

        }
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
    return 0;
}
// -> Keep It Simple Stupid!
