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

int n;
vector<int> a, b;
void getInput(vector<int>& temp) {
	int k; cin >> k;
	temp.assign(k, 0);
	
	for(int i = 0; i < k; ++i) {
		cin >> temp[i];
	}
}

vector<vector<int>> dp;
// 0 -> First Person Wins
// 1 -> Second Person Wins
// 2 -> Loop
int dfs(int node, int option) {
	debug(node, option);
	if(dp[node][option] != -1) return dp[node][option];
	
	dp[node][option] = 2; // Making Looping Possible
	
	vector<int>& v = (option ? b : a);
	
	bool loopPossible = false;
	
	for(const auto& other : v) {
		int nextNode = (node + other) % n;
		if(nextNode == 0) {
			// Monster Reached Black Hole
			// Good!
			dp[node][option] = option;
			break;
		}			
		else {
			int get = dfs(nextNode, 1 - option);
			if(get == option) {
				dp[node][option] = get;
				break;
			}
			else if(get == 2) {
				loopPossible = true;
			}
		}
	}
	if(dp[node][option] == option) {
		debug(node, option, dp[node][option]);
		return dp[node][option];
	}
	if(!loopPossible) {
		dp[node][option] = 1 - option;
	}
	debug(node, option, dp[node][option]);
	return dp[node][option];
}
vector<vector<int>> v;
// *-> KISS*
int solve() {
    cin >> n;
    getInput(a);
    getInput(b);
	
	// vector<vector<int>> v(n);
    
    dp.assign(n + 1, vector<int>(2, -1));
    for(int j = 0; j < 2; ++j) {
    	for(int i = 1; i < n; ++i) {
    		int get = dfs(i, j);
    		if(get == 2) {
    			cout << "Loop ";
    		}
    		else if(get == j) {
    			cout << "Win ";
    		}
    		else cout << "Lose ";
    	}
    	cout << '\n';
    }
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int TET = 1;
    //cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
		#ifdef LOCAL
        	cout << "##################" << '\n';
		#endif
        if (solve()) {
            break;
        }
        // cout << '\n';
    }
	#ifdef LOCAL
    	cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	#endif
	return 0;
}
// -> Keep It Simple Stupid!
