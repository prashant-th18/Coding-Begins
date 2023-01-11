using ll = long long;
class Solution {
public:
    vector<ll> maximumSegmentSum(vector<int>& nums, vector<int>& q) {
        int n = nums.size();
		set<int> pos;
		vector<ll> pre(n + 1, 0);
		pos.insert(0);
		pos.insert(n + 1);
		for(int i = 0; i < n; ++i) pre[i + 1] = pre[i] + nums[i];
		multiset<ll> st; st.insert(pre[n]); st.insert(0);
		vector<ll> ans;
		for(int i = 0; i < q.size(); ++i) {
			int elem = q[i] + 1;
			int up = *(pos.upper_bound(elem));
			int down = *(--pos.upper_bound(elem));
			ll sum = pre[up - 1] - pre[down];
			st.erase(st.lower_bound(sum));
			pos.insert(elem);
			// elem + 1 .. up
			// down + 1 .. elem - 1 
			if(elem + 1 < up) {
				st.insert(pre[up - 1] - pre[elem]);
			}
			if(elem - 1 > down) {
				st.insert(pre[elem - 1] - pre[down]);
			}
			ans.push_back(*(st.rbegin()));	
		}
		return ans;
    }
};
