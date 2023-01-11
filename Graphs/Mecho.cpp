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
const int inf = (int)1e9;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
using pll = pair<ll, ll>;

// *-> KISS*
int solve() {
    int n, s; cin >> n >> s;
	vector<string> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	pll start;
	vector<pll> bees;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(v[i][j] == 'M') start = {i, j};
			else if(v[i][j] == 'H') bees.push_back({i, j});
		}
	}
	// Valid function for mecho
	auto mvalid = [&](int i, int j) {
		return i >= 0 && j >= 0 && i < n && j < n && v[i][j] != 'T';
	};
	// valid function for bees
	auto bvalid = [&](int i, int j) {
		return i >= 0 && j >= 0 && i < n && j < n && v[i][j] != 'T' && v[i][j] != 'D';
	};

	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};

	int ans = -1;
	int si = 0, ei = 1000000;
	while(si <= ei) {
		int mid = (si + ei) >> 1;
		// We are assuming that Mecho will stay at it's place for mid minutes and then start moving towards 
		// his home
		vector<vector<bool>> bvis(n, vector<bool>(n, false)), 
			mvis(n, vector<bool>(n, false));
	
		vector<pll> last;
		vector<vector<int>> steps(n, vector<int>(n, inf));
		{
			queue<array<ll, 3>> q;
			for(int i = 0; i < sz(bees); ++i) {
				q.push({bees[i].ff, bees[i].ss, 0});
				bvis[bees[i].ff][bees[i].ss] = true;
			}
			while(!q.empty()) {
				array<ll, 3> t = q.front(); q.pop();
				/* debug(t); */
				steps[t[0]][t[1]] = 0;
				if(t[2] == mid) {
					last.push_back({t[0], t[1]});
					continue;
				}

				int x = t[0], y = t[1], step = t[2];

				for(int i = 0; i < 4; ++i) {
					int ni = x + dx[i], nj = y + dy[i];
					if(bvalid(ni, nj) && !bvis[ni][nj] && step + 1 <= mid) {
						bvis[ni][nj] = true;
						q.push({ni, nj, step + 1});
					}
				}
			}
		}

		bool yes = false;
		if(!bvis[start.ff][start.ss]) yes = true;
		
		queue<array<ll, 3>> q;
		for(int i = 0; i < sz(last); ++i) {
			q.push({last[i].ff, last[i].ss, 0});
		}
		while(!q.empty()) {
			array<ll, 3> _ = q.front(); q.pop();
			/* debug(_); */
			int x = _[0], y = _[1], step = _[2];
			steps[x][y] = step * s;
			for(int i = 0; i < 4; ++i) {
				int ni = x + dx[i], nj = y + dy[i];
				if(bvalid(ni, nj) && !bvis[ni][nj]) {
					q.push({ni, nj, step + 1});
					bvis[ni][nj] = true;
				}
			}
		}
		/* debug(steps); */
		q = queue<array<ll, 3>> ();

		/* debug(bvis); */
		
		if(yes) q.push({start.ff, start.ss, 0});

		/* if(!sz(q)) cout << mid << endl; */

		mvis[start.ff][start.ss] = true;
		ll minutes = -1; // -1 means unreachability
		while(!q.empty()) {
			array<ll, 3> t = q.front(); q.pop();
			int x = t[0], y = t[1], step = t[2];
			if(v[x][y] == 'D') {
				minutes = step;
				break;
			}

			for(int i = 0; i < 4; ++i) {
				int ni = x + dx[i], nj = y + dy[i];
				if(mvalid(ni, nj) && !mvis[ni][nj] && steps[ni][nj] > (step + 1)) {
					mvis[ni][nj] = true;
					q.push({ni, nj, step + 1});
				}
			}
		}
		if(minutes != -1) {
			ans = mid; si = mid + 1;
		}
		else ei = mid - 1;
	}
	cout << ans;
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
