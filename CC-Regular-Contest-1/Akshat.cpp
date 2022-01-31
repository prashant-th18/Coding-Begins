#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
// *-> KISS
mt19937 rng(uint32_t(chrono::steady_clock::now().time_since_epoch().count()));
#define uid(a, b) uniform_int_distribution<ll>(a, b)(rng)
int32_t main() {
    fstream fout;
    fout.open("akshat.out", ios :: out | ios :: trunc);
    for(int i = 0; i < 10; ++i)
    {
        fout << string((int)1e5, 'a') << endl;
    }
    return 0;
}
// -> Keep It Simple Stupid!
