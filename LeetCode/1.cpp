class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        vector<int> ans;
		int n = v.size();
		unordered_map<int, int> mp;
		for(int i = 0; i < n; ++i) {
			if(mp.count(target - v[i])) {
				ans.push_back(i); ans.push_back(mp[target - v[i]]);
				break;
			}
			mp[v[i]] = i;
		}
		return ans;
    }
};
