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
        ll n, k; cin >> n >> k;
        vector<ll> v(n);
        vector<ll> vis(n, -1);
        vector<ll> ans;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        ll node = 0, cnt = 0;
        while(vis[node] == -1)
        {
            vis[node] = cnt++;
            ans.push_back(v[node]);
            node = (node % n + v[node]) % n;
        }
        // node pr again cycle
        ll nsize = sz(ans);
        ll ind = vis[node];
        swap(ans, v);
        if(k <= nsize)
        {
            cout << accumulate(v.begin(), v.begin() + k, 0LL);
        }
        else
        {
            ll s = accumulate(v.begin() + ind, v.end(), 0LL);
            k -= (ind + 1);
            ll last = nsize - ind;
            ll rem = accumulate(v.begin() + ind, v.begin() + ind + (k % last), 0LL);
            cout << accumulate(v.begin(), v.begin() + ind, 0LL) + (k / last) * s + rem;
        }
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
