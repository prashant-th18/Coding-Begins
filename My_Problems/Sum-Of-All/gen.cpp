#include"bits/stdc++.h"
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
int main() {
    int t = 1;
    cout << t << endl;
    int s = 0;
    for(int i = 0; i < t; ++i) {
        int maxn = 100000 / t;
        int n = maxn;
        s += n;
        string res = string(n, '.');
        res[0] = uid(1, 9) + '0';
        for(int i = 1; i < n; ++i) {
            res[i] = uid(0, 9) + '0';
        }
        cout << res << endl;
    }
    assert(s <= 100000);
    return 0;
}
