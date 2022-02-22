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
        int xa, ya, xb, yb; cin >> xa >> ya >> xb >> yb;
        if(xb >= xa && yb >= ya)
        {
            cout << "Polycarp";
        }
        else
        {
            int pdis = xa + ya;
            int vdis = 0;
            // Either make yb = 1 or xb = 1
            if(yb - 1 < xb - 1)
            {
                vdis = xb;
            }
            else
            {
                vdis = yb;
            }
            if(vdis < pdis) cout << "Vasiliy";
            else cout << "Polycarp";
        }
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
