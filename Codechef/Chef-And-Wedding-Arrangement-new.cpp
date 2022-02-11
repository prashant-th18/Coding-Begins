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
    cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        int n, k; cin >> n >> k;
        vector<int> v(n);
        for (int &val : v) {
            cin >> val;
        }
        int c = 1;
        for (int i = 0; i < n; i++) {
            int cnt[101] = {0};
            int j = i;
            bool flag = false;
            while(j < n)
            {
                if(cnt[v[j]] != 0)
                {
                    flag = true;
                    break;
                }
                else ++cnt[v[j++]];
            }
            if(flag) ++c;
            i = j - 1;
        }
        cout << c;
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
