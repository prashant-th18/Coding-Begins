#include"bits/stdc++.h"
using namespace std;
#define sz(x) ((int)x.size())
using ll = long long;
#define all(x) begin(x), end(x)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
int main() {
	int n = uid(10000, 10000);
	string s = string(n, '.');
	for(int i = 0; i < n; ++i) {
		s[i] = uid(0, 25) + 'a';
	}
	cout << s << endl;
	int q = uid(100, 100);
	cout << q << endl;
	bool ok = false;
	while(q--) {
		int type = uid(1, 2);
		
		if(q == 0) {
			if(!ok) type = 2;
		}
		
		cout << type << ' ';
		int l = uid(1, 100), r = uid(n - 100, n);
		if(type == 1) {
			char ch = uid(0, 25) + 'a';
			cout << l << ' ' << r << ' ' << ch << endl;
		}
		else {
			ok = true;
			cout << l << ' ' << r << endl;
		}
	}
	return 0;
}