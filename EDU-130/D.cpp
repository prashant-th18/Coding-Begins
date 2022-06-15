#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second
using pi = pair<int, char>;

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

#define ordered_set tree<pi, null_type,less<pi>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */

#ifdef LOCAL
    void debug_print(string s) {
        cerr << "\"" << s << "\"";
    }

    void debug_print(const char* s) {
        debug_print((string)s);
    }

    void debug_print(bool val) {
        cerr << (val ? "true" : "false");
    }

    void debug_print(int val) {
        cerr << val;
    }

    void debug_print(ll val) {
        cerr << val;
    }

    void debug_print(double val) {
        cerr << val;
    }

    template<typename F, typename S>
    void debug_print(pair<F, S> val) {
        cerr << "(";
        debug_print(val.first);
        cerr << ", ";
        debug_print(val.second);
        cerr << ")";
    }

    void debug_print(vector<bool> val) {
        cerr << "{";
        bool first = true;
        for (bool x : val) {
            if (!first) {
                cerr << ", ";
            } else {
                first = false;
            }
            debug_print(x);
        }
        cerr << "}";
    }

    template<typename T>
    void debug_print(T val) {
        cerr << "{";
        bool first = true;
        for (const auto &x : val) {
            if (!first) {
                cerr << ", ";
            } else {
                first = false;
            }
            debug_print(x);
        }
        cerr << "}";
    }

    void debug_print_collection() {
        cerr << endl;
    }

    template<typename First, typename... Args>
    void debug_print_collection(First val, Args... args) {
        cerr << " ";
        debug_print(val);
        debug_print_collection(args...);
    }

#define debug(...) cerr << "@@@ " << #__VA_ARGS__ << " ="; debug_print_collection(__VA_ARGS__);

#else
    #define debug(...) 
#endif

char q1(int i) {
    cout << "? " << 1 << ' ' << i + 1 << endl;
    char ch; cin >> ch;
    return ch;
}
int q2(int l, int r) {
    cout << "? " << 2 << ' ' << l + 1 << ' ' << r + 1 << endl;
    int c; cin >> c;
    return c;
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    string res = string(n, '.');
    res[0] = q1(0);
    vector<int> back(26, -1);
    ordered_set st;
    int c1 = 0, c2 = 0;
    st.insert({0, res[0]});
    back[res[0] - 'a'] = 0;
    for(int i = 1; i < n; ++i) {
        int s = 0, e = sz(st) - 1;
        int ans = -1;

        while(s <= e) {
            int mid = (s + e) >> 1;
            int ind = (*st.find_by_order(mid)).ff;
            int dis1 = 0;
            for(int j = 0; j < 26; ++j) {
                if(back[j] >= ind) dis1++;
            }
            int dis2 = q2(ind, i);
            if(dis1 == dis2) {
                ans = mid; s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        debug(st);
        debug(ans);
        if(ans == -1) {
            ++c1;
            if(c1 > 26) assert(false);
            res[i] = q1(i);
        }
        else {
            res[i] = res[(*st.find_by_order(ans)).ff];
        }
        if(back[res[i] - 'a'] != -1) {
            st.erase(st.find({back[res[i] - 'a'], res[i]}));
        }
        st.insert({i, res[i]});
        back[res[i] - 'a'] = i;
    }
    cout << '!' << ' ' << res << endl;
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
