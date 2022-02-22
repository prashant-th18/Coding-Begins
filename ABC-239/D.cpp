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
    int N = 1e3;
    vector<bool> v(N, true);
    v[1] = false;
    for(int i = 4; i < N; i += 2) v[i] = false;
    for(int i = 3; i * i < N; ++i)
    {
        if(v[i])
        {
            for(int j = i * i; j < N; j += 2 * i) v[j] = false;
        }
    }
    for(int t_ = 0; t_ < test; t_++)
    {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int cnt = 0;
        for(int i = a; i <= b; ++i)
        {
            bool flag = false;
            for(int j = c; j <= d && !flag; ++j)
            {
                flag |= v[i + j];
            }
            cnt += flag;
        }
        if(cnt == (b - a + 1)) cout << "Aoki";
        else cout << "Takahashi";
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
