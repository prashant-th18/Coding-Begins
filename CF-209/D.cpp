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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int n, K = 26;
vector<int> v;
vector<vector<int>> g;

// *-> KISS*
int solve() {
	cin >> n;
	v.assign(n, 0);
	g.assign(n, vector<int>(K, 0));
	vector<int> lg(n + 1, 0);
	lg[1] = 0;
	for(int i = 2; i <= n; ++i) {
		lg[i] = 1 + lg[i / 2];
	}
	for(auto& val : v) cin >> val;
	for(int i = 0; i < n; ++i) {
		g[i][0] = v[i];
	}
	for(int i = n - 1; i >= 0; --i) {
		for(int j = 1; j < K; ++j) {
			int last = i + (1 << j) - 1;
			if(last >= n) break;
			g[i][j] = gcd(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
		}
	}
	auto query = [&](int l, int r) {
		int dif = r - l + 1;
		int j = lg[dif];
		return gcd(g[l][j], g[r - (1 << j) + 1][j]);
	};
	int maxx = 0;
	vector<int> ans;
	for(int i = 0; i < n; ++i) {
		int s = i, e = n - 1, r = i, l = i;
		while(s <= e) {
			int mid = (s + e) >> 1;
			int gg = query(i, mid);
			if(gg % v[i] == 0) {
				r = mid;
				s = mid + 1;
			}
			else e = mid - 1;
		}
		s = 0, e = i;
		while(s <= e) {
			int mid = (s + e) >> 1;
			int gg = query(mid, i);
			if(gg % v[i] == 0) {
				l = mid;
				e = mid - 1;
			}
			else s = mid + 1;
		}
		/* cerr << i << ' ' << anss << endl; */
		int dif = r - l + 1;
		if(dif > maxx) {
			maxx = dif;
			ans.clear();
			ans.push_back(l);
		}
		else if(dif == maxx) ans.push_back(l);
	}
	sort(all(ans));
	ans.resize(unique(all(ans)) - ans.begin());
	maxx = max(0, maxx - 1);
	cout << sz(ans) << ' ' << maxx << '\n';
	for(auto val : ans) cout << val + 1 << ' ';
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = false;
	int TET = 1;
    if(test) cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
		#ifdef LOCAL
        	cout << "##################" << '\n';
		#endif

        if (solve()) {
            break;
        }
        cout << '\n';
    }
	#ifdef LOCAL
    	cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	#endif
	return 0;
}
// -> Keep It Simple Stupid!
