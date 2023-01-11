class Solution {
public:
    int maxProfit(vector<int>& v) {
        int maxx = 0, ans = 0;
		for(int i = v.size() - 1; i >= 0; --i) {
			ans = max(ans, maxx - v[i]);
			maxx = max(maxx, v[i]);
		}
		return ans;
    }
};
