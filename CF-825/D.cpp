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
    int n; cin >> n;
	n *= 2;
	/* string s; */
	/* s += string(n / 2, '0'); s += string(n / 2, '1'); */
	/* do { */
	/* 	bool ok = false; */
	/* 	vector<int> v; */
	/* 	for(int ji = 0; ji < (1 << n); ++ji) { */
	/* 		for(int j = 0; j < n; ++j) { */
	/* 			if(ji & (1 << j)) v.push_back(j); */
	/* 		} */
		
	/* 	string p = s; */
	/* 	for(int i = 0; i < sz(v); ++i) { */
	/* 		int ni = v[(i + 1) % sz(v)]; */
	/* 		p[ni] = s[v[i]]; */
	/* 	} */
		
	/* 	bool ac = false; */
	/* 	set<int> st; */
	/* 	for(int i = 0; i < (1 << n) && (!ac); ++i) { */
	/* 		string s1, s2; */
	/* 		st.clear(); */
	/* 		for(int ii = 0; ii < n; ++ii) st.insert(ii); */

	/* 		for(int j = 0; j < n; ++j) { */
	/* 			if(i & (1 << j)) { */
	/* 				st.erase(j); */
	/* 				s2 += p[j]; */
	/* 			} */
	/* 		} */
	/* 		for(auto val : st) s1 += p[val]; */
	/* 		if(s1 == s2) ac = true; */
	/* 	} */

	/* 	if(ac) { */
	/* 		cout << s << endl; */
	/* 		for(int i = 0; i < sz(v); ++i) cout << v[i] << ' '; */
	/* 		cout << endl; */
	/* 		for(auto val : st) cout << val << ' '; */
	/* 		cout << endl; */
	/* 		ok = true; */
	/* 	} */
	/* 	v.clear(); */
	/* 	if(ok) break; */
	/* } */
	/* } while (next_permutation(all(s))); */
	string s; cin >> s;
	int c = count(all(s), '0');
	if(c % 2 == 1) {
		cout << -1; return 0;
	}
	set<int> o, z;
	for(int i = 0; i < sz(s); ++i) {
		if (s[i] == '0') {
			z.insert(i);
		}
		else o.insert(i);
	}
	
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
