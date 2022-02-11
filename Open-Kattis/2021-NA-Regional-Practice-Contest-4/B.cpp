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
        int n; cin >> n;
        vector<string> v(n);
        for (string &val : v) {
            cin >> val;
        }
        int count = 1;
        for (int i = 0; i < n; i++) {
            if(v[i][0] != 'm')
            {
                int num = stoi(v[i]);
                if(num != count)
                {
                    cout << "something is fishy"; return 0;
                }
            }
            ++count;
        }
        cout << "makes sense";
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
