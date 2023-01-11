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

#ifdef LOCAL
	void debug_print(string s) {
		cerr << "\"" << s << "\"";
	}

	void debug_print(const char* s) {
		debug_print((string)s);
	}

	void debug_print(bool val) {
		cerr << (val ? "true" : "false");
	}

	void debug_print(int val) {
		cerr << val;
	}

	void debug_print(ll val) {
		cerr << val;
	}

	void debug_print(double val) {
		cerr << val;
	}

	template<typename F, typename S>
	void debug_print(pair<F, S> val) {
		cerr << "(";
		debug_print(val.first);
		cerr << ", ";
		debug_print(val.second);
		cerr << ")";
	}

	void debug_print(vector<bool> val) {
		cerr << "{";
		bool first = true;
		for (bool x : val) {
			if (!first) {
				cerr << ", ";
			} else {
				first = false;
			}
			debug_print(x);
		}
		cerr << "}";
	}

	template<typename T>
	void debug_print(T val) {
		cerr << "{";
		bool first = true;
		for (const auto &x : val) {
			if (!first) {
				cerr << ", ";
			} else {
				first = false;
			}
			debug_print(x);
		}
		cerr << "}";
	}

	void debug_print_collection() {
		cerr << endl;
	}

	template<typename First, typename... Args>
	void debug_print_collection(First val, Args... args) {
		cerr << " ";
		debug_print(val);
		debug_print_collection(args...);
	}

#define debug(...) cerr << "@@@ " << #__VA_ARGS__ << " ="; debug_print_collection(__VA_ARGS__);

#else
	#define debug(...) 
#endif


mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
	freopen("cownav.in", "r", stdin);
	freopen("cownav.out", "w", stdout);
    int n; cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    
    map<array<int, 6>, bool> vis;
	vis[{n - 1, 0, 0, n - 1, 0, 1}] = true;
	queue<array<int, 7>> q;
	q.push({n - 1, 0, 0, n - 1, 0, 1, 0});
	// (x1, y1, dir1) (x2, y2, dir2), steps
	
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	
	auto valid = [&](int i, int j) -> bool {
		return i >= 0 && j >= 0 && i < n && j < n && v[i][j] != 'H';
	};
	
	auto get = [&](int x, int y, int dir) -> array<int, 2> {
		int px = x, py = y;
		if(px == 0 && py == n - 1) return {px, py};
		int nx = x + dx[dir], ny = y + dy[dir];
		if(valid(nx, ny)) {
			return {nx, ny};
		}
		return {px, py};
	};
	
	while(!q.empty()) {
		array<int, 7> t = q.front(); q.pop();
		// debug(t);
		
		if(t[0] == t[3] && t[1] == t[4] && t[0] == 0 && t[1] == n - 1) {
			cout << t[6];
			return 0;
		}
		
		int x1 = t[0], y1 = t[1], dir1 = t[2];
		int x2 = t[3], y2 = t[4], dir2 = t[5];
		int steps = t[6];
		
		// Move forward
		{
			array<int, 2> n1 = get(x1, y1, dir1);
			array<int, 2> n2 = get(x2, y2, dir2);
			if(!vis[{n1[0], n1[1], dir1, n2[0], n2[1], dir2}]) {
				vis[{n1[0], n1[1], dir1, n2[0], n2[1], dir2}] = true;
				q.push({n1[0], n1[1], dir1, n2[0], n2[1], dir2, steps + 1});
			}
		}
		
		// Turn right
		{
			int nd1 = (dir1 + 1) % 4, nd2 = (dir2 + 1) % 4;
			if(!vis[{x1, y1, nd1, x2, y2, nd2}]) {
				vis[{x1, y1, nd1, x2, y2, nd2}] = true;
				q.push({x1, y1, nd1, x2, y2, nd2, steps + 1});
			}
		}
		
		// Turn Left
		{
			int nd1 = (dir1 + 3) % 4, nd2 = (dir2 + 3) % 4;
			if(!vis[{x1, y1, nd1, x2, y2, nd2}]) {
				vis[{x1, y1, nd1, x2, y2, nd2}] = true;
				q.push({x1, y1, nd1, x2, y2, nd2, steps + 1});
			}
		}
	}
	assert(false);
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
