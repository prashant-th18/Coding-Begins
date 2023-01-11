using pii = pair<long long, long long>;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
using ll = long long;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& v) {
		sort(v.begin(), v.end(), [&](const vector<int>& a, const vector<int>& b) {
				return a[0] < b[0];
				});
		priority_queue<int, vector<int>, greater<int>> ind;
		vector<int> pos(n, 0);
		for(int i = 0; i < n; ++i) ind.push(i);
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		for(int j = 0; j < v.size(); ++j) {
			while(sz(pq) > 0 && pq.top().ff <= v[j][0]) {
				ind.push(pq.top().ss);
				pq.pop();
			}
			if(!ind.empty()) {
				pos[ind.top()]++;
				pq.push(pii(v[j][1], ind.top()));
				ind.pop();
			}
			else {
				pii p = pq.top(); pq.pop();
				ll dif = p.ff - v[j][0];
				pos[p.ss]++;
				pq.push(pii(dif + v[j][1], p.ss));
			}
		}
		int maxx = 0, in = -1;
		for(int i = 0; i < n; ++i) {
			if(pos[i] > maxx) {
				maxx = pos[i], in = i;
			}
		}
		return in;
    }
};

