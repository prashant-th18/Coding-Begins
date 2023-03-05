#include"bits/stdc++.h"
using namespace std;
#define sz(x) ((int)x.size())
using ll = long long;
#define all(x) begin(x), end(x)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
const int N = 1e7;
vector<int> p;
vector<bool> pr(N, true);
void init() {
	pr[0] = pr[1] = false;
	p.push_back(2);
	for(int i = 4; i < N; i += 2) pr[i] = false;
	for(ll i = 3; i < N; ++i) {
		if(pr[i]) {
			p.push_back(i);
			for(ll j = i * i; j < N; j += 2 * i) {
				pr[j] = false;
			}
		}
	}
	/* random_shuffle(all(p)); */
}
int main() {
	init();
	int n = uid(1, 100000);
	assert(n <= p.size());
	cout << n << endl;
	vector<int> temp;
	for(int i = 0; i < n; ++i) {
		temp.push_back(p[i]);
	}
	random_shuffle(all(temp));
	for(auto& val : temp) cout << val << ' ';
	cout << endl;
	int q = 1000000;
	cout << q << endl;
	int num = 9999889;
	while(q--) {
		cout << num-- << '\n';
	}
	return 0;
}

