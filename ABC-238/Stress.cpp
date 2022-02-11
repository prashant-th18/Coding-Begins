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
        ll a = 3, b = 18;
        for(int i = 0; i <= 18; ++i)
        {
            for(int j = 0; j <= 18; ++j)
            {
                if(i + j == b && ((i & j) == a))
                {
                    cout << "!"; return 0;
                }
            }
        }
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
