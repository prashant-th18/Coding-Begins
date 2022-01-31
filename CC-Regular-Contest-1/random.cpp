#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
mt19937 rng(uint32_t(chrono::steady_clock::now().time_since_epoch().count()));
#define uid(a, b) uniform_int_distribution<ll>(a, b)(rng)
// *-> KISS*
int32_t main() {
    fstream fout;
    fout.open("in17.in", ios :: out | ios :: trunc);
    int test = 1;
    fout << test << endl;
    int cnt = 0, limit = (1 << 30) - 1;
    int lim = 1 << 20;
    while(cnt < test)
    {
        int n = 100000;
        fout << n << '\n';
        vector<int> a, b;
        for(int i = 0; i < n; ++i)
        {
            a.push_back(uid(0, limit));
        }
        for(int i = 0; i < n; ++i)
        {
            b.push_back(uid(0, limit));
        }
        for (int i = 0; i < n; i++) {
            fout << (a[i] | b[i]) << ' ';
        }
        fout << '\n';
        for(int i = 0; i < n; ++i)
        {
            int temp = a[i] & b[i];
            if(3000LL * i > n) temp = uid(2 * lim, limit);
            
            fout << temp << ' ';
        }
        fout << '\n';
        ++cnt;
    }
    cout << cnt << endl;
    return 0;
}
// -> Keep It Simple Stupid!
