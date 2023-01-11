#define sz(x) ((int)x.size())
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& t) {
		int n = v.size();
		vector<vector<int>> ans;
		bool f = false;
		for(int i = 0; i < n; ++i) {
			if(v[i][0] <= t[0] && t[0] <= v[i][1]) {
				f = true;
				int j = i + 1;
				while(j < n && v[j][1] <= t[1]) ++j;
				if(j == n) {
					ans.push_back({v[i][0], max(t[1], v[j - 1][1])});
					i = n + 1;
				}
				else {
					if(v[j][0] <= t[1]) {
						ans.push_back({v[i][0], v[j][1]});
						i = j + 1;
					}
					else {
						ans.push_back({v[i][0], max(t[1], v[j - 1][0])});
						i = j;
					}
				}
				--i;
			}
			else ans.push_back(v[i]);
		}
		if(!f) {
			if(sz(ans) == 0) ans.push_back(t);
			else if(ans.back()[1] < t[0]) ans.push_back(t);
			else {
				reverse(ans.begin(), ans.end());
				ans.push_back(t);
				reverse(ans.begin(), ans.end());
			}
		}
		return ans;
    }
};
