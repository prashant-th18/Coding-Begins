#include"bits/stdc++.h"
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
using ll = long long;
const int maxx = 1e9;
int main() {
    int t = 1000;
    cout << t << endl;
    int s = 0;
    for(int i = 0; i < t; ++i) {
        int maxn = 1000;
        int n = maxn;
        s += n;
		cout << n << endl;
		for(int i = 0; i < n; ++i) {
			cout << uid(-maxx, maxx) << ' ';
		}
		cout << endl;
    }
    assert(s <= 1000000);
    return 0;
}

