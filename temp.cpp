#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        ll n; cin >> n;
        for(int x = 1; x <= n; ++x)
        {
            int i = x - 1;
            ll sa = (i * (i + 1)) >> 1;
            int s = i + 1, e = 100000;
            int a = 0;
            while(s <= e)
            {
                int mid = (s + e) >> 1;
                int temp = mid * (mid + 1) / 2 - (i + 1) * (i + 2) / 2;
                if(temp == sa)
                {
                    a = temp; break;
                }
                else if(temp > sa)
                {
                    e = mid - 1;
                }
                else s = mid + 1;
            }
            if(a == sa) cout << x << ' ';
        }
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
