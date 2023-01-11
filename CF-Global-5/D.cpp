#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)

vector<int> v, t;
void build(int in, int s, int e) {
	if(s == e) t[in] = v[s];
	else {
		int mid = (s + e) >> 1;
		build(2 * in, s, mid);
		build(2 * in + 1, mid + 1, e);
		t[in] = min(t[2 * in], t[2 * in + 1]);
	}
}
int query(int in, int s, int e, int qs, int qe) {
	if(qs > qe) return INT_MAX;
	if(s == qs && e == qe) return t[in];
	int mid = (s + e) >> 1;
	return min(query(2 * in, s, mid, qs, min(mid, qe)), query(2 * in + 1, mid + 1, e, max(qs, mid + 1), qe));
}
int main() {
	int n; cin >> n;
	n *= 2;
	v.assign(n, 0);
	t.assign(4 * n, 0);
	for(int i = 0; i < n / 2; ++i) cin >> v[i], v[i + n / 2] = v[i];
	build(1, 0, n - 1);
	vector<int> dp(n + 1, INT_MAX);
	vector<int> res(n / 2, 0);
	for(int i = n / 2 - 1; i >= 0; --i) {
		int elem = v[i];
		int s = i, e = n - 1, ans = -1;
		while(s <= e) {
			int mid = (s + e) >> 1;
			int get = query(1, 0, n - 1, i, mid);
			if(get < (elem + 1) / 2) {
				ans = mid;
				e = mid - 1;
			}
			else s = mid + 1;
		}
		if(ans == -1) {
			res[i] = -1;
		}
		else {
			res[i] = ans - i;
		}
	}
	if(count(all(res), -1) == n / 2) {
		for(auto val : res) cout << val << ' ';
			return 0;
	}
	int mini = 1e9, in = -1;
	for(int i = 0; i < n / 2; ++i) {
		if(res[i] != -1) {
			if(res[i] < mini) {
				mini = res[i];
				in = i;
			}
		}
	}
	/* cerr << in << endl; */
	n /= 2;
	int steps = res[in] + 1, index = (in - 1 + n) % (n);
	while(index != in) {
		if(res[index] != -1) {
			steps = min(steps, res[index]);
		}
		res[index] = steps;
		--index;
		index = (index + n) % (n);
		++steps;
	}
	for(auto val : res) cout << val << ' ';
	return 0;
}
