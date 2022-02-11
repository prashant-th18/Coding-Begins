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
    //cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        int n; cin >> n;
        vector<int> v(n);
        for (int &val : v) {
            cin >> val;
        }
        string s; cin >> s;
        int maxx = -1;
        for (int i = 0; i < n - 1; i++) {
            if(maxx > i)
            {
                maxx = max(maxx, v[i] - 1);
                if(s[i] == '0')
                {
                    cout << "NO"; return 0;
                }
            }
            else
            {
                if(i + 1 == v[i])
                {
                    continue;
                }
                else if(v[i] > i + 1)
                {
                    maxx = v[i] - 1;
                    --i;
                }
                else continue;
            }
        }
        cout << "YES";
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
