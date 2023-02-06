#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

using pll = pair<ll, ll>;
// *-> KISS*
int solve() {
    ll n, w, h; cin >> n >> w >> h;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    
    set<pll> rl, rr;
    for(int i = 0; i < n; ++i) {
        ll num1 = a[i] + w - (b[i] + h); // kitna maxx krr skta
        num1 = max(0LL, num1);
        
        ll num2 = (a[i] - w) - (b[i] - h); // kitna krna hi hoga
        num2 = max(0LL, num2);
        rl.insert({num2, -(i + 1)});
        rl.insert({num1, (i + 1)});
        
        ll num3 = b[i] - h - (a[i] - w); // kitna maxx krr skta
        num3 = max(0LL, num3);
        
        ll num4 = b[i] + h - (a[i] + w); // kitna krna hi hoga
        num4 = max(num4, 0LL);
        rr.insert({num4, -(i + 1)});
        rr.insert({num3, (i + 1)});
    }
    int cnt = 0;
    bool ok = false;
    int startleft, endleft;
    for(const auto& [x, y] : rl) {
        debug(x, y);
        if(y < 0) {
            cnt++;
            if(cnt == n) startleft = x, ok = true;
        }
        else {
            if(cnt == n) {
                endleft = x;
            }
            cnt--;
        }
    }
    cnt = 0;
    int startright, endright;
    for(const auto& [x, y] : rr) {
        debug(x, y);
        if(y < 0) {
            cnt++;
            if(cnt == n) {
                startright = x;
                ok &= true;
            }
        }
        else {
            if(cnt == n) {
                endright = x;
            }
            cnt--;
        }
    }
    auto check = [&](int num) -> bool {
        auto cc = a;
        for(int i = 0; i < n; ++i) cc[i] += num;
            
        for(int i = 0; i < n; ++i) {
            int ml = cc[i] - w, mr = cc[i] + w;
            int ol = b[i] - h, oz = b[i] + h;
            if(ml <= ol && oz <= mr) {
                
            }
            else return false;
        }
        return true;
    };
    if(ok) {
        bool l1 = (startright <= 0) && (0 <= endright);
        bool l0 = (startleft <= 0) && (0 <= endleft);
        if(l1 && l0) cout << "YES";
        else if(l1) {
            // Sbhi ko startleft jitna left krdo
            if(check(-startleft)) {
                cout << "YES";
            }
            else cout << "NO";
        }
        else if(l0) {
            if(check(startright)) {
                cout << "YES";
            }
            else cout << "NO";
        }
        else cout << "NO";
    }
    else cout << "NO";
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
