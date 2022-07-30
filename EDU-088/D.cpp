#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

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

int n;
vector<int> v, t1, t2, pre, suf;
void build1(int in = 1, int s = 0, int e = n - 1) {
    if(s == e) {
        t1[in] = pre[s];
    }
    else {
        int mid = (s + e) >> 1;
        build1(2 * in, s, mid);
        build1(2 * in + 1, mid + 1, e);
        t1[in] = max(t1[2 * in], t1[2 * in + 1]);
    }
}
int query1(int in, int s, int e, int qs, int qe) {
    if(qs > qe) return INT_MIN;
    if(s == qs && e == qe) return t1[in];
    int mid = (s + e) >> 1;
    return max(query1(2 * in, s, mid, qs, min(mid, qe)), query1(2 * in + 1, mid + 1, e, max(mid + 1, qs), qe));
}
void build2(int in = 1, int s = 0, int e = n - 1) {
    if(s == e) t2[in] = suf[s];
    else {
        int mid = (s + e) >> 1;
        build2(2 * in, s, mid);
        build2(2 * in + 1, mid + 1, e);
        t2[in] = max(t2[2 * in], t2[2 * in + 1]);
    }
}
int query2(int in, int s, int e, int qs, int qe) {
    if(qs > qe) return INT_MIN;
    if(s == qs && e == qe) return t2[in];
    int mid = (s + e) >> 1;
    return max(query2(2 * in, s, mid, qs, min(mid, qe)), query2(2 * in + 1, mid + 1, e, max(mid + 1, qs), qe));
}
// *-> KISS*
int solve() {
    cin >> n;
    v.assign(n, 0);
    pre.assign(n, 0);
    suf.assign(n, 0);
    t1.assign(4 * n, 0);
    t2.assign(4 * n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> left(n), right(n);
    {
        map<int, int> pos;
        for(int i = n - 1; i >= 0; --i) {
            int r = n - 1;
            pos[v[i]] = i;
            for(int j = v[i] + 1; j <= 30; ++j) {
                if(pos.count(j)) {
                    r = min(r, pos[j] - 1);
                }
            }
            right[i] = r;
        }
        debug(right);
        pos.clear();
        for(int i = 0; i < n; ++i) {
            int l = 0;
            pos[v[i]] = i;
            for(int j = v[i] + 1; j <= 30; ++j) {
                if(pos.count(j)) {
                    l = max(l, pos[j] + 1);
                }
            }
            left[i] = l;
        }
        debug(left);
    }
    pre[0] = v[0];
    for(int i = 1; i < n; ++i) pre[i] = pre[i - 1] + v[i];
    suf[n - 1] = v[n - 1];
    for(int i = n - 2; i >= 0; --i) suf[i] = suf[i + 1] + v[i];
    debug("Yo");
    build1();
    build2();
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        int ri = query1(1, 0, n - 1, i, right[i]);
        ri -= pre[i];
        int le = query2(1, 0, n - 1, left[i], i);
        le -= suf[i];
        ans = max(ans, ri + le);
    }
    cout << ans;
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

        if (solve()) {
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
