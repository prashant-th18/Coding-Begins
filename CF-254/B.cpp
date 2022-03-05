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
        ll n, m; cin >> n >> m;
        vector<vector<int>> v(n + 1);
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            v[a].push_back(b);
            ++cnt[b];
        }
        vector<int> order;
        queue<int> q;
        for(int i = 1; i <= n; ++i) if(cnt[i] == 0) q.push(i);
        while(!q.empty())
        {
            int f = q.front(); q.pop();
            order.push_back(f);
            for(const auto& val : v[f])
            {
                --cnt[val];
                if(cnt[val] == 0) q.push(val);
            }
        }
        reverse(all(order));
        debug(order);
        ll ans = 1;
        vector<bool> vis(n + 1, false);
        for (int i = 0; i < sz(order); i++) {
            bool flag = false;
            vis[order[i]] = true;
            for(const auto& val : v[order[i]])
            {
                if(vis[val])
                {
                    flag = true; break;
                }
            }
            if(flag)
            {
                ans *= 2;
            }
        }
        cout << ans;
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
