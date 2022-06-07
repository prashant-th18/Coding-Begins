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
    // checker
    int n, k; cin >> n >> k;
    /*
    string temp = string(k, '0');
    temp += string(n - k, '1');
    int minn = 10000000;
    string res = "";
    auto fun = [&]() {
        int s = 0;  
        for(int i = 0; i < n - 1; ++i) {
            s += stoi(temp.substr(i, 2));   
        }
        debug(s, temp);
        if(s <= minn) {
            minn = s;
        }

    };
    do {
       fun(); 
    } while(next_permutation(all(temp))); 
    
    */
    string s;
    auto getRes = [&]() {
        ll sum = 0;
        for(int i = 0; i < n - 1; ++i) {
            sum += stoll(s.substr(i, 2));
        }
        return sum;
    };
    cin >> s;
    int c = count(all(s), '0');
    if(c == 0 || c == n) {
        cout << getRes(); return 0;
    }
    auto first = [&]() -> int {
          for(int i = 0; i < n; ++i) if(s[i] == '1') return i;
    };
    auto last = [&]() -> int {
        for(int i = n - 1; i >= 0; --i) if(s[i] == '1') return i;  
    };
    if(s[0] == '1' && s[n - 1] == '1') cout << getRes();
    else if(s[0] == '1' && s[n - 1] == '0') {
        int i = last();
        int cc = n - 1 - i;
        if(cc <= k) {
            swap(s[i], s[n - 1]);
        }
        cout << getRes();
    }
    else if(s[0] == '0' && s[n - 1] == '1') {
        int i = first();
        if(i <= k && i != n - 1) {
            swap(s[0], s[i]);
        }
        cout << getRes();
    }
    else {
        int j = last();
        if((n - 1 - j) <= k) {
            swap(s[j], s[n - 1]);
            k -= (n - 1 - j);
            int i = first();
            if(i != n - 1) {
                if(i <= k) swap(s[0], s[i]);
            }
            cout << getRes();
        }
        else {
            int i = first();
            if(i <= k) swap(s[0], s[i]);
            cout << getRes();
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
