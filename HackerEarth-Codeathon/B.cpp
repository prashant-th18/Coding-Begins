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
        int n; cin >> n;
        vector<int> a(n);
        for (int &val : a) {
            cin >> val;
        }
        vector<int> b(n);
        for (int &val : b) {
            cin >> val;
        }
        bool flag = true; // true means same dir, else opposite
        int s = 0, e = n - 1;
        bool ans = true;
        int c = 0;
        while(s < e)
        {
            if(flag)
            {
                if(a[s] == b[s] && a[e] == b[e])
                {
                    ++s, --e; continue;
                }
                if((a[s] == b[e]) && (b[s] == a[e]))
                {
                    ++s; --e;
                    ++c; flag = !flag; continue;
                }
                else
                {
                    ans = false; break;
                }
            }
            else
            {
                if(a[s] == b[e] && a[e] == b[s])
                {
                    ++s, --e; continue;
                }
                if((a[s] == b[s]) && (a[e] == b[e]))
                {
                    ++s, --e; ++c;
                    flag = !flag; continue;
                }
                else
                {
                    ans = false; break;
                }
            }
        }
        if(ans)
        {
            cout << c;
        }
        else cout << -1;
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
