#define ff first
#define ss second
using pii = pair<int, int>;
class Solution {
public:
    int oddEvenJumps(vector<int>& v) {
		int n = v.size(), c = 1;
		set<pii> st;
		set<int> last;
		vector<vector<bool>> dp(n, vector<bool>(2, false));
		dp[n - 1][0] = dp[n - 1][1] = true;
		st.insert(pii(v[n - 1], n - 1)); last.insert(v[n - 1]);
		for(int i = n - 2; i >= 0; --i) {
			// Odd numbered
			auto it = st.lower_bound(pii(v[i], i));
			if(it != st.end()) {
				dp[i][0] = dp[(*it).ss][1];
			}
			c += dp[i][0];

			// Even numbered
			auto it1 = last.upper_bound(v[i]);
			if(it1 != last.begin()) {
				--it1;
				it = st.lower_bound(pii((*it1), i));
				if(it != st.end()) {
					dp[i][1] = dp[(*it).ss][0];
				}
			}
			st.insert(pii(v[i], i));
			last.insert(v[i]);
		}
		return c;
    }
};
