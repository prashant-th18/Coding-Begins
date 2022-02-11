#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*

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

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        /*
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int c = 0;
        for (int size = 1; size <= n; size++) {
            for (int i = 0; i < n - size + 1; i++) {
                set<int> st;
                for (int j = i; j < i + size; j++) {
                    st.insert(v[j]);
                }
                debug(st);
                if(sz(st) == size) ++c;
            }
        }
        cout << c;
        */
        ll n, k; cin >> n >> k;
        k -= n;
        ll s = 0, e = n - 1;
        ll ans = 0;
        while(s <= e)
        {
            ll mid = (s + e) >> 1;
            ll temp = mid * (mid + 1) >> 1;
            if(temp <= k)
            {
                ans = mid; s = mid + 1;
            }
            else e = mid - 1;
        }
        deque<int> dq;
        ll maybe = ans * (ans + 1) >> 1;
        k -= maybe;
        int cnt = 2;
        while(cnt <= ans + 1)
        {
            if(k == 0)
            {
                dq.push_back(1);
            }
            dq.push_back(cnt++);
            --k;
        }
        bool flag = false;
        for(auto val : dq)
        {
            if(val == 1) 
            {
                flag = true; break;
            }
        }
        if(!flag) dq.push_back(1);
        while(sz(dq) != n) dq.push_front(1);
        for(auto val : dq) cout << val << ' ';
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
