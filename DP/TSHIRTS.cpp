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

vector<int> extractIntegerWords(string str)
{
    stringstream ss;
    vector<int> curr;
    ss << str;
    string temp;
    int found;
    while (!ss.eof()) {
        ss >> temp;
        if (stringstream(temp) >> found)
            curr.push_back(found);
        temp = "";
    }
    return curr;
}
const int MAX = 101;
// *-> KISS*
int solve() {
    int n; cin >> n;
	vector<vector<int>> shirts(101);
	map<int, set<int>> person;
	for(int i = 0; i < n; ++i) {
		string s;
		getline(cin >> ws, s);
		vector<int> v = (extractIntegerWords(s));
		for(auto val : v) {
			shirts[val].push_back(i);
			person[i].insert(val);
		}
		s.clear();
	}
	vector<vector<int>> dp(MAX + 1, vector<int>(1 << n, 0));
	// dp[i][j] ->
	// If you have shirts from "i" to "MAX", then, what are the number of ways to assign these shirts 
	// to persons represented by "j"
	dp[MAX][0] = 1;
	for(int i = MAX - 1; i >= 0; --i) {
		for(int mask = 0; mask < (1 << n); ++mask) {
			// Two ways:
			// 1. Don't consider this shirt
			dp[i][mask] = dp[i + 1][mask];
			// 2. Consider this shirt for a person which exists in mask, and which has this shirt
			for(int j = 0; j < n; ++j) {
				if(mask & (1 << j)) {
					// This person is present
					// Check for this person, whether this shirt can be wore or not
					if(person[j].count(i)) {
						dp[i][mask] = (dp[i][mask] + dp[i + 1][mask ^ (1 << j)]) % MOD;
					}
				}
			}
		}
	}
	cout << dp[0][(1 << n) - 1];
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
