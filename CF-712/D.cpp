#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include "bits/stdc++.h"
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

// *-> KISS*
int solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, -1));
    vector<set<pair<int, int>>> t(3);
    int dx[] = {-1, -1, 1, 1};
    int dy[] = {-1, 1, 1, -1};
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            st.insert(pair(i, j));
        }
    }
    auto valid2 = [&](int i, int j, int col) {
        if((i - 1) >= 0 && v[i - 1][j] == col) return false;
        if((i + 1) < n && v[i + 1][j] == col) return false;
        if((j - 1) >= 0 && v[i][j - 1] == col) return false;
        if((j + 1) < n && v[i][j + 1] == col) return false;
        return true;
    };
    auto valid = [&](int i, int j, int col) {
        if(i < 0 || i >= n || j < 0 || j >= n || v[i][j] != -1 || !valid2(i, j, col)) return false;
        return true;
    };
    for(int i = 0; i < n * n; ++i) {
        int c; cin >> c;
        --c;
        bool f = false;
        for(int j = 0; j <= 2 && !f; ++j) {
            if(j != c) {
                for(auto it = t[j].begin(); it != t[j].end();) {
                    auto temp = *it;
                    for(int k = 0; k < 4; ++k) {
                        int ni = temp.ff + dx[k], nj = temp.ss + dy[k];
                        if(valid(ni, nj, j)) {
                            v[ni][nj] = j;
                            cout << j + 1 << ' ' << ni + 1 << ' ' << nj + 1 << endl;
                            t[j].insert(pair(ni, nj));
                            st.erase(pair(ni, nj));
                            f = true; break;
                        }
                    }
                    if(f) break;
                    it = t[j].erase(it);
                }
            }
        }
        if(!f) {
            pair<int, int> p;
            for(auto [ni, nj]: st) {
                for(int j = 0; j <= 2 && !f; ++j) {
                    if(j == c) continue;
                    if(valid2(ni, nj, j)) {
                        cout << j + 1 << ' ' << ni + 1 << ' ' << nj + 1 << endl;
                        v[ni][nj] = j;
                        t[j].insert(pair(ni, nj));
                        f = true;
                        p = pair(ni, nj);
                    }
                }
                if(f) break;
            }
            assert(f);
            st.erase(st.find(p));
        }
    }
    debug(v);
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = false;
    int TET = 1;
    if(test) cin >> TET;
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
