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
// *-> KISS*
int solve() {
	freopen("lasers.in", "r", stdin);
	freopen("lasers.out", "w", stdout);
    int n, sx, sy, tx, ty; cin >> n >> sx >> sy >> tx >> ty;
	unordered_map<int, vector<int>, custom_hash> cx, cy;
	for(int i = 0; i < n; ++i) {
		int x, y; cin >> x >> y;
		cx[x].push_back(y);
		cy[y].push_back(x);
	}
	if(sx == tx && sy == ty) {
		cout << 0; return 0;
	}
	cx[tx].push_back(ty);
	cy[ty].push_back(tx);
	for(auto& [val, v] : cx) sort(all(v));
	for(auto& [val, v] : cy) sort(all(v));
	
	map<array<int, 3>, bool> vis; // (x, y) , direction
	queue<array<int, 4>> q; // (x, y), steps, direction
	q.push({sx, sy, 0, 0}); q.push({sx, sy, 0, 1}); q.push({sx, sy, 0, 2}); q.push({sx, sy, 0, 3});
	vis[{sx, sy, 0}] = vis[{sx, sy, 1}] = vis[{sx, sy, 2}] = vis[{sx, sy, 3}] = true;
	// 0 up
	// 1 right
	// 2 down
	// 3 left
	int hr[] = {1, 3}, vr[] = {0, 2};
	while(!q.empty()) {
		array<int, 4> _ = q.front(); q.pop();
		int x = _[0], y = _[1], steps = _[2], dir = _[3];
		/* debug(x, y, dir); */
		if(dir == 0) {
			vector<int>& v = cx[x];
			/* debug(v); */
			int in = upper_bound(all(v), y) - begin(v);
			for(int i = in; i < sz(v); ++i) {
				if(vis[{x, v[i], dir}]) break;
				if(tx == x && ty == v[i]) {
					cout << steps;
					return 0;
				}
				else {
					vis[{x, v[i], dir}] = true;
					for(int j = 0; j < 2; ++j) {
						if(!vis[{x, v[i], hr[j]}]) {
							vis[{x, v[i], hr[j]}] = true;
							q.push({x, v[i], steps + 1, hr[j]});
						}
					}
				}
			}
		}
		else if(dir == 1) {
			vector<int>& v = cy[y];
			/* debug(v); */
			int in = upper_bound(all(v), x) - begin(v);
			for(int i = in; i < sz(v); ++i) {
				if(vis[{v[i], y, dir}]) break;
				if(ty == y && tx == v[i]) {
					cout << steps;
					return 0;
				}
				else {
					vis[{v[i], y, dir}] = true;
					for(int j = 0; j < 2; ++j) {
						if(!vis[{v[i], y, vr[j]}]) {
							vis[{v[i], y, vr[j]}] = true;
							q.push({v[i], y, steps + 1, vr[j]});
						}
					}
				}
			}
		}
		else if(dir == 2) {
			vector<int>& v = cx[x];
			/* debug(v); */
			int in = lower_bound(all(v), y) - begin(v);
			--in;
			for(int i = in; i >= 0; --i) {
				if(vis[{x, v[i], dir}]) break;
				if(tx == x && ty == v[i]) {
					cout << steps;
					return 0;
				}
				else {
					vis[{x, v[i], dir}] = true;
					for(int j = 0; j < 2; ++j) {
						if(!vis[{x, v[i], hr[j]}]) {
							vis[{x, v[i], hr[j]}] = true;
							q.push({x, v[i], steps + 1, hr[j]});
						}
					}
				}
			}
		}
		else {
			vector<int>& v = cy[y];
			/* debug(v); */
			int in = lower_bound(all(v), x) - begin(v);
			--in;
			for(int i = in; i >= 0; --i) {
				if(vis[{v[i], y, dir}]) break;
				if(ty == y && tx == v[i]) {
					cout << steps;
					return 0;
				}
				else {
					vis[{v[i], y, dir}] = true;
					for(int j = 0; j < 2; ++j) {
						if(!vis[{v[i], y, vr[j]}]) {
							vis[{v[i], y, vr[j]}] = true;
							q.push({v[i], y, steps + 1, vr[j]});
						}
					}
				}
			}
		}
	}
	cout << -1;
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
