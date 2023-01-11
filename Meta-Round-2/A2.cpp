#ifdef LOCAL
	#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// Use -> unordered_map<key_type, value_type, custom_hash> mp;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
// *-> KISS*
int solve() {
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	vector<vector<int>> bit(n + 1, vector<int>(31, 0));
	auto upd = [&](int in, int j, int del) {
		for(; in <= n; in += (in & (-in))) {
			bit[in][j] += del;
		}
	};
	auto SU = [&](int in, int j) {
		ll s = 0;
		for(; in > 0; in -= (in & (-in))) {
			s += bit[in][j];
		}
		return s;
	};
	auto sum = [&](int l, int r, int j) {
		return SU(r, j) - SU(l - 1, j);
	};
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 31; ++j) {
			upd(i + 1, j, (v[i] >> j) & 1);
		}
	}
	map<int, ordered_set> mp;
	for(int i = 0; i < n; ++i) {
		mp[v[i]].insert(i + 1);
	}
	int q; cin >> q;
	int ans = 0;
	while(q--) {
		int a, b, c; cin >> a >> b >> c;
		if(a == 1) {
			int pre = v[b - 1];
			mp[pre].erase(b);
			mp[c].insert(b);
			v[b - 1] = c;
			for(int j = 0; j < 31; ++j) {
				upd(b, j, -1 * ((pre >> j) & 1));
				upd(b, j, (c >> j) & 1);
			}
		}
		else {
			int num = 0;
			for(int j = 0; j < 31; ++j) {
				if(sum(b, c, j) & 1) num += (1 << j);
			}
			auto it = mp[num].lower_bound(b);
			if(it == mp[num].end() || (*it) > c) continue;

			int mid = (b + c) >> 1;
			int left = mp[num].order_of_key(mid) - mp[num].order_of_key(b);
			int right = mp[num].order_of_key(c + 1) - mp[num].order_of_key(mid + 1);

			// Considering in the left
			left += (v[mid - 1] == num);
			if(left - 1 == right) {
				// [b .. mid]
				// [mid + 1 .. c]
				vector<int> l(31), r(31);
				for(int i = 0; i < 31; ++i) {
					l[i] = sum(b, mid, i);
					r[i] = sum(mid + 1, c, i);
					l[i] -= ((num >> i) & 1);
				}
				if(l == r) {
					++ans;
					continue;
				}
			}
			left -= (v[mid - 1] == num);
			right += (v[mid - 1] == num);
			if(left == right - 1) {
				// [b .. mid - 1]
				// [mid .. c]
				vector<int> l(31), r(31, 0);
				for(int i = 0; i < 31; ++i) {
					l[i] = sum(b, mid - 1, i);
					r[i] = sum(mid, c, i);
					r[i] -= ((num >> i) & 1);
				}
				if(l == r) ++ans;
			}
		}
	}
	cout << ans;
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = true;
	int TET = 1;
    if(test) cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
		cout << "Case #" << i << ": ";
		#ifdef LOCAL
        	cerr << "##################" << '\n';
		#endif

        if (solve()) {
            break;
        }
        cout << '\n';
    }
	#ifdef LOCAL
    	cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	#endif
	return 0;
}
// -> Keep It Simple Stupid!
