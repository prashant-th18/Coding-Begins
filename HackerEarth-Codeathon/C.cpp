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
        vector<array<ll, 2>> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i][0] >> v[i][1];
        }
        auto f = [&](array<ll, 2> a, array<ll, 2> b) -> bool
        {
            if(a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        };
        sort(v.begin(), v.end(), f);
        auto bin = [&](ll num) -> int
        {
            ll s = 0, e = n - 1;
            int ans = -1;
            while(s <= e)
            {
                ll mid = (s + e) >> 1;
                if(v[mid][0] >= num)
                {
                    ans = mid; e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
            return ans;
        };
        ll s = 0, cnt = 0;
        while(1)
        {
            auto index = bin(s);
            if(index == -1) break;
            s = v[index][0];
            priority_queue<ll> last;
            while(index < n && v[index][0] == s)
            {
                last.push(-v[index][1]);
                ++index;
            }
            while(!last.empty())
            {
                if(s <= -last.top())
                {
                    ++cnt;
                }
                else
                {
                    while(!last.empty() && s > -last.top()) last.pop();
                    continue;
                }
                ++s;
                last.pop();
                while(index < n && v[index][0] == s)
                {
                    debug(index);
                    last.push(-v[index][1]);
                    ++index;
                }
            }
        }
        cout << cnt;
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
