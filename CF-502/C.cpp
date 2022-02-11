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
        /*
        vector<int> v(n);
        int maxx = 1e9;
        iota(all(v), 1);
        auto fun = [&](int ans = -1) -> void
        {
        do {
            
            int max1 = -1;
            for(int s = 0; s < n; ++s)
            {
                int c = 1, pre = v[s];
                for(int i = s + 1; i < n; ++i)
                {
                    if(v[i] > pre)
                    {
                        pre = v[i];
                        ++c;
                    }
                }
                max1 = max(max1, c);
            }
            int max2 = -1;
            for(int s = 0; s < n; ++s)
            {
                int c = 1, pre = v[s];
                for (int i = s + 1; i < n; i++) {
                    if(v[i] < pre) ++c, pre = v[i];
                }
                max2 = max(max2, c);
            }
            maxx = min(maxx, max1 + max2);
            if(ans == max1 + max2){
            debug(max1 + max2);
            debug(v);
            }
        } while (next_permutation(all(v)));
        };*/
        cout << 1 << ' ';
        for (int i = 1, s = 3, e = 2; i < n; i++) {
            if(i % 2 == 1 && s <= n)
            {
                cout << s << ' ';
                s += 2;
            }
            else
            {
                cout << e << ' ';
                e += 2;
            }
        }
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
