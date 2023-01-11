#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) ((int)x.size())
using ll = long long;

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, c; cin >> n >> c;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	int ans = count(all(v), c);
	map<int, vector<int>> mp;
	for(int i = 0; i < n; ++i) {
		if(c != v[i]) mp[c - v[i]].push_back(i);
	}
	vector<int> dp(n, 0), pre(n, 0);
	for(int i = 0; i < n; ++i) {
		if(i == 0) pre[i] = v[i] == c;
		else {
			pre[i] = pre[i - 1] + (v[i] == c);
		}
	}
	for(const auto& [value, t] : mp) {
		int left = (pre[t[0]]);
		for(int i = sz(t) - 1; i >= 0; --i) {
			int right = pre[n - 1] - pre[t[i]];// t[i] + 1 .. n - 1
			if(i == sz(t) - 1) {
				dp[t[i]] = left + right + (i + 1);
			}
			else {
				dp[t[i]] = max(left + right + (i + 1), dp[t[i + 1]]);
			}
		}
	}
	debug(dp);
	for(int i = 0; i < n; ++i) {
		if(v[i] != c) {
			int el = c - v[i];
			int index = lower_bound(all(mp[el]), i) - begin(mp[el]);
			int temp = dp[i];
			temp -= index;
			temp -= pre[mp[el][0]];
			temp += pre[i];
			ans = max(ans, temp);
		}
	}
	cout << ans;
	return 0;
}
